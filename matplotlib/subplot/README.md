# subplot
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


```python
import numpy as np

import matplotlib.pyplot as plt

rng = np.random.default_rng()

plt.figure(1)
plt.subplot(2, 2, 1)
plt.imshow(rng.random((10, 100)))
plt.title("A")
plt.subplot(2, 2, 2)
plt.imshow(rng.random((5, 10)))
plt.title("B")
plt.subplot(2, 2, 3)
plt.imshow(rng.random((50, 20)))
plt.title("C")
plt.subplot(2, 2, 4)
plt.imshow(rng.random((100, 200)))
plt.title("D")
plt.show()
```

![image0](image0.png)


