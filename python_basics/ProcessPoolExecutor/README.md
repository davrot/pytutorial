# ProcessPoolExecutor: A fast way to implement multiprocessing 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

A fast way (measured in source code length) for multi-processing a function. Is it the best way? No, but it is easily accessable.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## An example
We want to run 4 processes (number_of_cpu_processes = 4) at the same time. 

The first step is to get rid of most of the arguments of the function function_a. We use [functools.partial](https://docs.python.org/3/library/functools.html#functools.partial) to fix all the non relevant (for the multiprocessing) arguments. We will leave only one argument which is akin to a job id. 

Then we create a [concurrent.futures.ProcessPoolExecutor](https://docs.python.org/3/library/concurrent.futures.html#processpoolexecutor) session with 4 processes: 
> The [ProcessPoolExecutor](https://docs.python.org/3/library/concurrent.futures.html#concurrent.futures.ProcessPoolExecutor) class is an
> [Executor](https://docs.python.org/3/library/concurrent.futures.html#concurrent.futures.Executor) subclass that uses a pool of processes to execute calls asynchronously. [ProcessPoolExecutor](https://docs.python.org/3/library/concurrent.futures.html#concurrent.futures.ProcessPoolExecutor) uses the multiprocessing module,
> which allows it to side-step the [Global Interpreter Lock](https://docs.python.org/3/glossary.html#term-global-interpreter-lock) but also means that only picklable objects can be executed and returned.

Using the ProcessPoolExecutor instance executor, we now can call the [executor.map](https://docs.python.org/3/library/concurrent.futures.html#concurrent.futures.Executor.map) method.  

[map(func, *iterables, timeout=None, chunksize=1)](https://docs.python.org/3/library/concurrent.futures.html#concurrent.futures.Executor.map) : 
> When using [ProcessPoolExecutor](https://docs.python.org/3/library/concurrent.futures.html#concurrent.futures.ProcessPoolExecutor), this method chops iterables into a number of chunks which it
> submits to the pool as separate tasks. The (approximate) size of these chunks can be specified by setting chunksize to a positive integer.
> For very long iterables, using a large value for chunksize can significantly improve performance compared to the default size of 1.

[map(function, iterable, ...)](https://docs.python.org/3/library/functions.html#map): 
> Return an iterator that applies function to every item of iterable, yielding the results. If additional iterable arguments are passed, function must
> take that many arguments and is applied to the items from all iterables in parallel. With multiple iterables, the iterator stops when the shortest iterable is exhausted.

As you can see in the output, all random numbers are the same. This is the results of the "but also means that only picklable objects can be executed and returned.". The rng object is pickled and thus frozen in its state. Every time map calls the function, rng is un-pickled -- with the same state --.

```python
import numpy as np
import concurrent.futures
import functools


def function_a(parameter_a: float, rng) -> tuple[float, float]:
    return rng.random() + parameter_a, parameter_a


number_of_cpu_processes: int = 4
rng = np.random.default_rng()
number_of_calls: int = 10

function_a_partial = functools.partial(
    function_a,
    rng=rng,
)

with concurrent.futures.ProcessPoolExecutor(number_of_cpu_processes) as executor:
    for id, (return_value_a, return_value_b) in enumerate(
        executor.map(function_a_partial, range(0, number_of_calls))
    ):
        print(f"{id} {return_value_a:.3f} {return_value_b}")
```

Output:

```python
0 0.951 0
1 1.951 1
2 2.951 2
3 3.951 3
4 4.951 4
5 5.951 5
6 6.951 6
7 7.951 7
8 8.951 8
9 9.951 9
``` 

Another example but with a Numpy array as result array:

```python
import numpy as np
import concurrent.futures
import functools


def function_a(parameter_a: float, size: int, rng) -> np.ndarray:
    return rng.random((size,)) + parameter_a


number_of_cpu_processes: int = 4
rng = np.random.default_rng()
number_of_calls: int = 10
size = 12
function_a_partial = functools.partial(
    function_a,
    size=size,
    rng=rng,
)

results: np.ndarray = np.zeros((number_of_calls, size))

with concurrent.futures.ProcessPoolExecutor(number_of_cpu_processes) as executor:
    for id, return_value_a in enumerate(
        executor.map(function_a_partial, range(0, number_of_calls))
    ):
        results[id, :] = return_value_a

print(results)
```
