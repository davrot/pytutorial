# [scipy.signal](https://docs.scipy.org/doc/scipy/reference/signal.html) -- Butterworth low, high and band-pass
## Goal

Sometimes we need to remove of frequency range from a time series. For this we can use a Butterworth filter [scipy.signal.butter](https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.butter.html) and the [scipy.signal.filtfilt](https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.filtfilt.html) command. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

| | |
| ------------- |:-------------:|
| [scipy.signal.filtfilt](https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.filtfilt.html) | Apply a digital filter forward and backward to a signal. |
| [scipy.signal.butter](https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.butter.html)  | Butterworth digital and analog filter design. |

## Example data 

```python
import numpy as np
import matplotlib.pyplot as plt

samples_per_second: int = 1000
dt: float = 1.0 / samples_per_second

# 10 secs
t: np.ndarray = np.arange(0, int(10 * samples_per_second)) * dt

f_low = 1  # Hz
f_mid = 10  # Hz
f_high = 100  # Hz

sin_low = np.sin(2 * np.pi * t * f_low)
sin_mid = np.sin(2 * np.pi * t * f_mid)
sin_high = np.sin(2 * np.pi * t * f_high)

plt.figure(1)
plt.plot(t, sin_low)
plt.plot(t, sin_mid + 3)
plt.plot(t, sin_high + 6)
plt.xlabel("Time [s]")
plt.ylabel("Waveform shifted")
plt.title("unfiltered data")
plt.show()
```
