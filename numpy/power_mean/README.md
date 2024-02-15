# Power and mean 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## The order is important 

You are not allowed to average over the trials before calculating the power. This is the same for calculating the fft power as well as the wavelet power. 

```python
import numpy as np
import matplotlib.pyplot as plt

t: np.ndarray = np.linspace(0, 1.0, 10000)
f: float = 10

sinus_a = np.sin(f * t * 2.0 * np.pi)
sinus_b = np.sin(f * t * 2.0 * np.pi + np.pi)

plt.plot(t, sinus_a, label="a")
plt.plot(t, sinus_b, label="b")
plt.plot(t, (sinus_a + sinus_b) / 2.0, "k--", label="(a+b)/2")
plt.legend()
plt.xlabel("t [s]")
plt.show()
```

![image0.png]


```python
import numpy as np
import matplotlib.pyplot as plt

t: np.ndarray = np.linspace(0, 1.0, 10000)
f: float = 10
n: int = 1000

rng = np.random.default_rng(1)
sinus = np.sin(f * t[:, np.newaxis] * 2.0 * np.pi + 2.0 * np.pi * rng.random((1, n)))
print(sinus.shape)

plt.plot(t, sinus)
plt.plot(t, sinus.mean(axis=-1), "k--")
plt.show()
```

![image1.png]
