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

## An example (up to 437x faster)

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
