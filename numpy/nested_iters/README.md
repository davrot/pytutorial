# zip
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

{: .topic-optional}
This is an optional topic!

## [numpy.nested_iters](https://numpy.org/doc/stable/reference/generated/numpy.nested_iters.html)

```python
numpy.nested_iters(op, axes, flags=None, op_flags=None, op_dtypes=None, order='K', casting='safe', buffersize=0)
```

> Create nditers for use in nested loops
> 
> Create a tuple of nditer objects which iterate in nested loops over different axes of the op argument. The first iterator is used in the outermost loop, the last in the innermost loop. Advancing one will change the subsequent iterators to point at its new element.

```python
import numpy as np


a = np.arange(1, 7).reshape((2, 3))
print(a)
print()

iter_a, iter_b = np.nested_iters(a, [[0], [1]], flags=["multi_index"])

for x in iter_a:
    for y in iter_b:
        print(
            f"iter_a.multi_index: {iter_a.multi_index}, iter_b.multi_index: {iter_b.multi_index}"
        )
```

Output:

```python
[[1 2 3]
 [4 5 6]]

iter_a.multi_index: (0,), iter_b.multi_index: (0,)
iter_a.multi_index: (0,), iter_b.multi_index: (1,)
iter_a.multi_index: (0,), iter_b.multi_index: (2,)
iter_a.multi_index: (1,), iter_b.multi_index: (0,)
iter_a.multi_index: (1,), iter_b.multi_index: (1,)
iter_a.multi_index: (1,), iter_b.multi_index: (2,)
```
