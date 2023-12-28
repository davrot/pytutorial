# Numba
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

["Numba is an open source JIT compiler that translates a subset of Python and NumPy code into fast machine code."](https://numba.pydata.org/)

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install numba
```

[A ~5 minute guide to Numba](https://numba.pydata.org/numba-doc/latest/user/5minguide.html)

## [Numba basic types](https://numba.pydata.org/numba-doc/dev/reference/types.html)

For the example that will show you the options of optimization we need to understand the numba naming schema. 

### Numbers

For the function signatures we need to be able to translate the usual np.dtype into numpy.types.

For doing so we just replace **np.** by **numba.types.** .

|Type name(s)|	Shorthand|	Comments|
|---|---|---|
|numba.types.boolean	|b1|	represented as a byte|
|numba.types.uint8, byte	|u1|	8-bit unsigned byte|
|numba.types.uint16	|u2|	16-bit unsigned integer|
|numba.types.uint32	|u4|	32-bit unsigned integer|
|numba.types.uint64	|u8|	64-bit unsigned integer|
|numba.types.int8, char	|i1|	8-bit signed byte|
|numba.types.int16	|i2|	16-bit signed integer|
|numba.types.int32	|i4|	32-bit signed integer|
|numba.types.int64	|i8|	64-bit signed integer|
|numba.types.intc	|–|	C int-sized integer|
|numba.types.uintc	|–|	C int-sized unsigned integer|
|numba.types.intp	|–|	pointer-sized integer|
|numba.types.uintp	|–|	pointer-sized unsigned integer|
|numba.types.float32|	f4|	single-precision floating-point number|
|numba.types.float64, double|	f8|	double-precision floating-point number|
|numba.types.complex64|	c8|	single-precision complex number|
|numba.types.complex128|	c16|	double-precision complex number|

### Arrays

If we have arrays in the function signature, which is a very likely senario, we might want to give as much information to numpy as possible about the numpy.ndarray. In some cases it is very benificial to make a np.ndarray an array with C memory layout and tell numba about it.

We can use the numpy function **numpy.ascontiguousarray for** converting a numpy array into a C memory layout.

We can also check a numpy array, let's call it X, if it is already in the C memory layout. This is done by looking at **X.flags['C_CONTIGUOUS']**.

Some example for array signatures are: 

|||
|---|---|
|numba.types.float32[:]|	1d array of float32 with no particular memory layout|
|numba.types.float32[:,:]|	2d array of float32 with no particular memory layout|
|numba.types.float32[:,:,:]|	3d array of float32 with no particular memory layout|
|numba.types.float32[::1]|	1d array of float32 with C memory layout|
|numba.types.float32[:,::1]|	2d array of float32 with C memory layout|
|numba.types.float32[:,:,::1]|	3d array of float32 with C memory layout|
|numba.types.float32[::1,:]|	2d array of float32 with Fortran memory layout|
|numba.types.float32[::1,:,:]| 3d array of float32 with Fortran memory layout|

## An example (up to 350x faster)

For measuring the time used by the program I ran everything twice and took the second time. I did this is because the just-in-time compilation takes a moment for the first call of a function.  

### Basis code (7.76 sec)

This is the basic code without any optimizations.

```python
import time
import numpy as np


def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float64
) -> np.uint64:

    summation: np.float64 = np.float64(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:

    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in range(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float64)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float64
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")
    print(results[0:10])
```

### Optimization 1 (0.482sec)


We add just-in-time compilation to the function get_spike with @njit(cache=True). ["To avoid compilation times each time you invoke a Python program, you can instruct Numba to write the result of function compilation into a file-based cache."](https://numba.pydata.org/numba-doc/latest/user/jit.html#cache)

```python
import time
import numpy as np
from numba import njit


@njit(cache=True)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float64
) -> np.uint64:

    summation: np.float64 = np.float64(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:

    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in range(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float64)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float64
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")
    print(results[0:10])
```


### Optimization 2 (0.627sec)

We also add just-in-time compilation to the function main with @njit(cache=True). 

```python
import time
import numpy as np
from numba import njit


@njit(cache=True)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float64
) -> np.uint64:

    summation: np.float64 = np.float64(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


@njit(cache=True)
def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:

    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in range(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float64)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float64
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")
    print(results[0:10])
```

### Optimization 3 (0.619sec)

We add [function signatures](https://numba.pydata.org/numba-doc/latest/reference/types.html) to the code with:

```python
@njit(
    numba.types.uint64(numba.types.float64[:], numba.types.uint64, numba.types.float64),
    cache=True,
)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float64
) -> np.uint64:


[...]

@njit(
    numba.types.uint64[:](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float64[:],
        numba.types.float64[:, :],
    ),
    cache=True,
)
def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:
```


```python
import time
import numpy as np
from numba import njit
import numba


@njit(
    numba.types.uint64(numba.types.float64[:], numba.types.uint64, numba.types.float64),
    cache=True,
)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float64
) -> np.uint64:

    summation: np.float64 = np.float64(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


@njit(
    numba.types.uint64[:](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float64[:],
        numba.types.float64[:, :],
    ),
    cache=True,
)
def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:

    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in range(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float64)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float64
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")
    print(results[0:10])
```

### Optimization 4 (0.419sec)

We tell numba about the [C memory layout](https://numba.pydata.org/numba-doc/latest/reference/types.html#arrays) of the arrays with refining the function signature:

```python
@njit(
    numba.types.uint64[::1](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float64[::1],
        numba.types.float64[:, ::1],
    ),
    cache=True,
)
```

```python
import time
import numpy as np
from numba import njit
import numba


@njit(
    numba.types.uint64(numba.types.float64[:], numba.types.uint64, numba.types.float64),
    cache=True,
)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float64
) -> np.uint64:

    summation: np.float64 = np.float64(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


@njit(
    numba.types.uint64[::1](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float64[::1],
        numba.types.float64[:, ::1],
    ),
    cache=True,
)
def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:

    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in range(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float64)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float64
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")
    print(results[0:10])
```

### Optimization 5 (0.235sec)

We don't really need float64. Let's us switch to float32:

```python
import time
import numpy as np
from numba import njit
import numba


@njit(
    numba.types.uint64(numba.types.float32[:], numba.types.uint64, numba.types.float32),
    cache=True,
)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float32
) -> np.uint64:

    summation: np.float32 = np.float32(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


@njit(
    numba.types.uint64[::1](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float32[::1],
        numba.types.float32[:, ::1],
    ),
    cache=True,
)
def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:

    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in range(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float32)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float32
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")
    print(results[0:10])
```

### Optimization 6 (0.144sec)

Let us activate [fastmath](https://numba.pydata.org/numba-doc/latest/reference/jit-compilation.html#jit-decorator-fastmath)

```python
@njit(
    numba.types.uint64(numba.types.float32[:], numba.types.uint64, numba.types.float32),
    cache=True,
    fastmath=True,
)
[...]

@njit(
    numba.types.uint64[::1](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float32[::1],
        numba.types.float32[:, ::1],
    ),
    cache=True,
    fastmath=True,
)
```

```python
import time
import numpy as np
from numba import njit
import numba


@njit(
    numba.types.uint64(numba.types.float32[:], numba.types.uint64, numba.types.float32),
    cache=True,
    fastmath=True,
)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float32
) -> np.uint64:
    summation: np.float32 = np.float32(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


@njit(
    numba.types.uint64[::1](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float32[::1],
        numba.types.float32[:, ::1],
    ),
    cache=True,
    fastmath=True,
)
def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:
    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in range(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float32)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float32
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")
    print(results[0:10])
```

### Optimization 7 (0.022sec)

We can run the function main in [parallel](https://numba.pydata.org/numba-doc/latest/reference/jit-compilation.html#jit-decorator-parallel). This can be activated by:

```python
@njit(
    numba.types.uint64[::1](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float32[::1],
        numba.types.float32[:, ::1],
    ),
    cache=True,
    fastmath=True,
    parallel=True,
)
```
and then we need to replace **range** by **[prange](https://numba.pydata.org/numba-doc/latest/user/parallel.html#numba-parallel)**.

```python
import time
import numpy as np
from numba import njit, prange
import numba


@njit(
    numba.types.uint64(numba.types.float32[:], numba.types.uint64, numba.types.float32),
    cache=True,
    fastmath=True,
)
def get_spike(
    h: np.ndarray, number_of_neurons: np.uint64, random_number: np.float32
) -> np.uint64:
    summation: np.float32 = np.float32(0.0)

    output: np.uint64 = np.uint64(number_of_neurons - 1)

    for i in range(0, np.uint64(number_of_neurons - 1)):
        summation += h[i]

        if random_number <= summation:
            output = np.uint64(i)
            return output

    return output


@njit(
    numba.types.uint64[::1](
        numba.types.uint64,
        numba.types.uint64,
        numba.types.float32[::1],
        numba.types.float32[:, ::1],
    ),
    cache=True,
    fastmath=True,
    parallel=True,
)
def main(
    number_of_iterations: np.uint64,
    number_of_neurons: np.uint64,
    random_number_spikes: np.ndarray,
    random_number_h: np.ndarray,
) -> np.ndarray:
    results = np.zeros((number_of_iterations), dtype=np.uint64)

    for i in prange(0, number_of_iterations):
        h = random_number_h[i, :]
        h /= h.sum()
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])

    return results


if __name__ == "__main__":
    number_of_iterations: np.uint64 = np.uint64(10000)
    number_of_neurons: np.uint64 = np.uint64(10000)
    myrng = np.random.default_rng()

    random_number_spikes = myrng.random((number_of_iterations), dtype=np.float32)
    random_number_h = myrng.random(
        (number_of_iterations, number_of_neurons), dtype=np.float32
    )

    start_time = time.perf_counter()
    results = main(
        number_of_iterations=number_of_iterations,
        number_of_neurons=number_of_neurons,
        random_number_spikes=random_number_spikes,
        random_number_h=random_number_h,
    )
    end_time = time.perf_counter()

    check_for_errors = np.sum([results >= number_of_neurons])
    if check_for_errors > 0:
        print("Something went really wrong! Panic!")
    print(f"{end_time-start_time:.5f} sec")

    print(results[0:10])
```

## Failure is an option: Debugging 

If something is too good to be true then maybe it is not true! Not only in the case of an email from a rich Nigerian prince you might want to debug the situation, also you shouldn't totally trust numba as well. As always: Check if the results are in the right region. 

If Numba njit has a problem it ***usually*** gives you an error message and stops. This is the reason why we use njit instead of jit. If jit sees a problem it fixes it with slow Python code. And it does this silently. You will only notice the absence of an improvement. njit stops with an error message. 

Only once we found a problem (with an earlier version of numba) where the use of parallel loops failed so beautiful that we got wrong results but a speed improvement 10000x. Looking on the speed improvement this was clearly a case of too good to be true.

But you are not helpless!

In the case of our example with prange we can [activate debugging information](https://numba.pydata.org/numba-doc/latest/user/parallel.html#diagnostics) 

```python
main.parallel_diagnostics(level=4)
```
and see that it did:

```python
================================================================================
 Parallel Accelerator Optimizing:  Function main, <ipython-input-1-dc4cb05d144d>
 (30)  
================================================================================


Parallel loop listing for  Function main, <ipython-input-1-dc4cb05d144d> (30) 
---------------------------------------------------------------------------------|loop #ID
@njit(                                                                           | 
    numba.types.uint64[::1](                                                     | 
        numba.types.uint64,                                                      | 
        numba.types.uint64,                                                      | 
        numba.types.float32[::1],                                                | 
        numba.types.float32[:, ::1],                                             | 
    ),                                                                           | 
    cache=True,                                                                  | 
    fastmath=True,                                                               | 
    parallel=True,                                                               | 
)                                                                                | 
def main(                                                                        | 
    number_of_iterations: np.uint64,                                             | 
    number_of_neurons: np.uint64,                                                | 
    random_number_spikes: np.ndarray,                                            | 
    random_number_h: np.ndarray,                                                 | 
) -> np.ndarray:                                                                 | 
    results = np.zeros((number_of_iterations), dtype=np.uint64)------------------| #0
                                                                                 | 
    for i in prange(0, number_of_iterations):------------------------------------| #2
        h = random_number_h[i, :]                                                | 
        h /= h.sum()-------------------------------------------------------------| #1
        results[i] = get_spike(h, number_of_neurons, random_number_spikes[i])    | 
                                                                                 | 
    return results                                                               | 
--------------------------------- Fusing loops ---------------------------------
Attempting fusion of parallel loops (combines loops with similar properties)...
  Trying to fuse loops #0 and #2:
    - fusion failed: cross iteration dependency found between loops #0 and #2
----------------------------- Before Optimisation ------------------------------
Parallel region 0:
+--2 (parallel)
   +--1 (parallel)


--------------------------------------------------------------------------------
------------------------------ After Optimisation ------------------------------
Parallel region 0:
+--2 (parallel)
   +--1 (serial)


 
Parallel region 0 (loop #2) had 0 loop(s) fused and 1 loop(s) serialized as part
 of the larger parallel loop (#2).
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
 
---------------------------Loop invariant code motion---------------------------
Allocation hoisting:
No allocation hoisting found

Instruction hoisting:
loop #0:
  Has the following hoisted:
    $expr_out_var.15 = const(uint64, 0)
loop #2:
  Has the following hoisted:
    $const120.4 = const(NoneType, None)
    $const122.5 = const(NoneType, None)
    $124build_slice.6 = global(slice: <class 'slice'>)
    $124build_slice.7 = call $124build_slice.6($const120.4, $const122.5, func=$124build_slice.6, args=(Var($const120.4, <ipython-input-1-dc4cb05d144d>:50), Var($const122.5, <ipython-input-1-dc4cb05d144d>:50)), kws=(), vararg=None, varkwarg=None, target=None)
    $186load_global.16 = global(get_spike: CPUDispatcher(<function get_spike at 0x7fedb9fc27a0>))
  Failed to hoist the following:
    dependency: $126build_tuple.8 = build_tuple(items=[Var($parfor__index_18.95, <string>:2), Var($124build_slice.7, <ipython-input-1-dc4cb05d144d>:50)])
    dependency: h = getitem(value=random__number__h, index=$126build_tuple.8, fn=<built-in function getitem>)
    dependency: $206binary_subscr.22 = getitem(value=random__number__spikes, index=$parfor__index_18.95, fn=<built-in function getitem>)
    dependency: $220call.23 = call $push_global_to_block.94($h.1.22, number__of__neurons, $206binary_subscr.22, func=$push_global_to_block.94, args=[Var($h.1.22, <ipython-input-1-dc4cb05d144d>:51), Var(number__of__neurons, <ipython-input-1-dc4cb05d144d>:30), Var($206binary_subscr.22, <ipython-input-1-dc4cb05d144d>:52)], kws=(), vararg=None, varkwarg=None, target=None)
--------------------------------------------------------------------------------
```

