# Remove a common signal from your data
## Goal
We want to remove a common signal which was mixed on top a set of data channels. There are many methods to do so. We will use SVD. Implementations are for example: [scipy.linalg.svd](https://docs.scipy.org/doc/scipy/reference/generated/scipy.linalg.svd.html) or [torch.svd_lowrank](https://pytorch.org/docs/stable/generated/torch.svd_lowrank.html) (which also works on the GPU)

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Creating dirty test data 

```python
import numpy as np
import matplotlib.pyplot as plt

rng = np.random.default_rng()

time_series_length: int = 1000
number_of_channels: int = 100

t: np.ndarray = np.arange(0, time_series_length) / 1000

# Clean data
frequencies = 10 / rng.random((1, number_of_channels))
phase = 2 * np.pi * rng.random((1, number_of_channels))
clean_data: np.ndarray = (
    0.5
    * rng.random((1, number_of_channels))
    * np.sin(t[..., np.newaxis] * 2 * np.pi * frequencies + phase)
    + np.arange(0, number_of_channels)[np.newaxis, ...]
)

# Perturbation
y: np.ndarray = np.sin(t * 2 * np.pi * 1)
mix_coefficients: np.ndarray = 1 + rng.random((number_of_channels)) * 5
perturbation: np.ndarray = y[..., np.newaxis] * mix_coefficients[np.newaxis, ...]

# Dirty data
dirty_data: np.ndarray = clean_data.copy()
dirty_data += perturbation

np.savez(
    "data.npz", clean_data=clean_data, perturbation=perturbation, dirty_data=dirty_data
)


plt.plot(t, clean_data[..., 0:3])
plt.xlabel("Time [s]")
plt.ylabel("Clean data waveform")
plt.show()

plt.plot(t, perturbation[..., 0:3])
plt.xlabel("Time [s]")
plt.ylabel("Perturbation ")
plt.show()

plt.plot(t, dirty_data[..., 0:3])
plt.xlabel("Time [s]")
plt.ylabel("Dirty data ")
plt.show()
```
We get three fully random time series

![figure 1](image1.png)

Sine wave with random amplitudes as common perturbation

![figure 2](image2.png)

Both combined with random mixing coefficients

![figure 3](image3.png)

## Estimating the common signal


