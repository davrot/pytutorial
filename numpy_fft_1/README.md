# Numpy -- rfft and spectral power
## Goal
We want to calculate a well behaved power spectral density from a 1 dimensional time series. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Generation of test data 
We will generate a sine wave with 10 Hz.

```python
import numpy as np

time_series_length: int = 1000
dt: float = 1.0 / 1000.0  # time resolution is 1ms
sampling_frequency: float = 1.0 / dt
frequency_hz: float = 10.0
t: np.ndarray = np.arange(0, time_series_length) * dt
y: np.ndarray = np.sin(t * 2 * np.pi * frequency_hz)
```

![figure 1](figure_1.png)
 

