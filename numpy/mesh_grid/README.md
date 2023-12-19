# Meshgrid
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.meshgrid](https://numpy.org/doc/stable/reference/generated/numpy.meshgrid.html)


```python
numpy.meshgrid(*xi, copy=True, sparse=False, indexing='xy')
```

> Return a list of coordinate matrices from coordinate vectors.
> 
> Make N-D coordinate arrays for vectorized evaluations of N-D scalar/vector fields over N-D grids, given one-dimensional coordinate arrays x1, x2,…, xn.

```python
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 1, 100)
y = np.linspace(0, 1, 100)

xv, yv = np.meshgrid(x, y)

plt.imshow(xv, cmap="hot")
plt.xlabel("x axis")
plt.ylabel("y axis")
plt.title("xv")
plt.show()

plt.imshow(yv, cmap="hot")
plt.xlabel("x axis")
plt.ylabel("y axis")
plt.title("yv")
plt.show()
```

![image0](image0.png)

![image1](image1.png)
