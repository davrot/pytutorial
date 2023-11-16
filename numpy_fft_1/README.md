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

## Fourier transform with rfft

Since we deal with non-complex waveforms (i.e. only real values) we should use rfft. This is faster and uses less memory. 

### 1 dimension


| | |
| ------------- |:-------------:|
| [numpy.fft.rfft](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfft.html) |  Compute the one-dimensional discrete Fourier Transform for real input. |
| [numpy.fft.irfft](https://numpy.org/doc/stable/reference/generated/numpy.fft.irfft.html) |  Computes the inverse of [rfft](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfft.html#numpy.fft.rfft). |
| [numpy.fft.rfftfreq](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfftfreq.html) |  Return the Discrete Fourier Transform sample frequencies (for usage with rfft, irfft). |

### 2 dimensions

| | |
| ------------- |:-------------:|
| [numpy.fft.rfft2](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfft2.html) |  Compute the 2-dimensional FFT of a real array. |
| [numpy.fft.irfft2](https://numpy.org/doc/stable/reference/generated/numpy.fft.irfft2.html) |  Computes the inverse of rfft2. |

### N dimensions

| | |
| ------------- |:-------------:|
| [numpy.fft.rfftn](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfftn.html) | Compute the N-dimensional discrete Fourier Transform for real input.
| [numpy.fft.irfftn](https://numpy.org/doc/stable/reference/generated/numpy.fft.irfftn.html) | Computes the inverse of rfftn.


Since we deal with a 1 dimensional time series

```python
y_fft: np.ndarray = np.fft.rfft(y)
frequency_axis: np.ndarray = np.fft.rfftfreq(y.shape[0]) * sampling_frequency
```
