# Animation and Slider
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## Test data

```python
import numpy as np
import matplotlib.pyplot as plt

axis = np.arange(-100, 101) / 100.0

x = axis[:, np.newaxis, np.newaxis].copy()
y = axis[np.newaxis, :, np.newaxis].copy()
z = axis[np.newaxis, np.newaxis, :].copy()

r = np.sqrt(x**2 + y**2 + z**2)

mask_0 = r > 0.75
r = 1.0 / (r + 1.0)
r[mask_0] = 0

plt.imshow(r[100, :, :], cmap="hot")
plt.colorbar()
plt.title("Cut through center of x-axis")
plt.show()
```

![image0](image0.png)

