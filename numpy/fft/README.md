# [FFT](https://numpy.org/doc/stable/reference/routines.fft.html)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Fouriert transformations are an important part of data analysis. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Numpy](https://numpy.org/doc/stable/reference/routines.fft.html) vs  [scipy](https://docs.scipy.org/doc/scipy/tutorial/fft.html#fourier-transforms-scipy-fft)

```shell
pip install scipy
```

Numpy says [itself](https://numpy.org/doc/stable/reference/routines.fft.html#discrete-fourier-transform-numpy-fft): 
> The SciPy module scipy.fft is a more comprehensive superset of numpy.fft, which includes only a basic set of routines.

## fft vs rfft

### [numpy.fft.fft](https://numpy.org/doc/stable/reference/generated/numpy.fft.fft.html)

```python
fft.fft(a, n=None, axis=-1, norm=None)[source]
```
> Compute the one-dimensional discrete Fourier Transform.
> 
> This function computes the one-dimensional n-point discrete Fourier Transform (DFT) with the efficient Fast Fourier Transform (FFT) algorithm [CT].

### [numpy.fft.rfft](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfft.html)

```python
fft.rfft(a, n=None, axis=-1, norm=None)[source]
```

> Compute the one-dimensional discrete Fourier Transform for real input.
> 
> This function computes the one-dimensional n-point discrete Fourier Transform (DFT) of a real-valued array by means of an efficient algorithm called the Fast Fourier Transform (FFT).

### Comparison

If the input array is **real-valued** (i.e. no complex numbers) then use **rfft**. Otherwise use **fft**. However, you can always use **fft** if you want but you might need to add extra steps to remove the complex noise from the results. E.g. if x is real-valued ifft(fft(x)) can be complex, due to numerical noise.


The test signal: 

```python
import numpy as np
import matplotlib.pyplot as plt

# Test signal
f: float = 10.0
t = np.linspace(0, 10, 10000)
x = np.sin(t * f * 2 * np.pi)

plt.plot(t, x)
plt.ylabel("sin(x)")
plt.xlabel("sin(x)")
plt.show()
```

![image0](image0.png)

```python
fft_result = np.fft.fft(x)
print(fft_result.shape) # -> (10000,)
rfft_result = np.fft.rfft(x)
print(rfft_result.shape) # -> (5001,)
```


## [Discrete Fourier Transform (numpy.fft)](https://numpy.org/doc/stable/reference/routines.fft.html#discrete-fourier-transform-numpy-fft)

## [Standard FFTs](https://numpy.org/doc/stable/reference/routines.fft.html#standard-ffts)

|||
|---|---|
|[fft(a[, n, axis, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.fft.html#numpy.fft.fft)|Compute the one-dimensional discrete Fourier Transform.|
|[ifft(a[, n, axis, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.ifft.html#numpy.fft.ifft)|Compute the one-dimensional inverse discrete Fourier Transform.|
|[fft2(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.fft2.html#numpy.fft.fft2)|Compute the 2-dimensional discrete Fourier Transform.|
|[ifft2(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.ifft2.html#numpy.fft.ifft2)|Compute the 2-dimensional inverse discrete Fourier Transform.|
|[fftn(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.fftn.html#numpy.fft.fftn)|Compute the N-dimensional discrete Fourier Transform.|
|[ifftn(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.ifftn.html#numpy.fft.ifftn)|Compute the N-dimensional inverse discrete Fourier Transform.|

## [Real FFTs](https://numpy.org/doc/stable/reference/routines.fft.html#real-ffts)

|||
|---|---|
|[rfft(a[, n, axis, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfft.html#numpy.fft.rfft)|Compute the one-dimensional discrete Fourier Transform for real input.|
|[irfft(a[, n, axis, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.irfft.html#numpy.fft.irfft)|Computes the inverse of rfft.|
|[rfft2(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfft2.html#numpy.fft.rfft2)|Compute the 2-dimensional FFT of a real array.|
|[irfft2(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.irfft2.html#numpy.fft.irfft2)|Computes the inverse of rfft2.|
|[rfftn(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfftn.html#numpy.fft.rfftn)|Compute the N-dimensional discrete Fourier Transform for real input.|
|[irfftn(a[, s, axes, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.irfftn.html#numpy.fft.irfftn)|Computes the inverse of rfftn. |

## [Hermitian FFTs](https://numpy.org/doc/stable/reference/routines.fft.html#hermitian-ffts)

|||
|---|---|
|[hfft(a[, n, axis, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.hfft.html#numpy.fft.hfft)|Compute the FFT of a signal that has Hermitian symmetry, i.e., a real spectrum.|
|[ihfft(a[, n, axis, norm])](https://numpy.org/doc/stable/reference/generated/numpy.fft.ihfft.html#numpy.fft.ihfft)|Compute the inverse FFT of a signal that has Hermitian symmetry.|

## [Helper routines](https://numpy.org/doc/stable/reference/routines.fft.html#helper-routines)

|||
|---|---|
|[fftfreq(n[, d])](https://numpy.org/doc/stable/reference/generated/numpy.fft.fftfreq.html#numpy.fft.fftfreq)|Return the Discrete Fourier Transform sample frequencies.|
|[rfftfreq(n[, d])](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfftfreq.html#numpy.fft.rfftfreq)|Return the Discrete Fourier Transform sample frequencies (for usage with rfft, irfft).|
|[fftshift(x[, axes])](https://numpy.org/doc/stable/reference/generated/numpy.fft.fftshift.html#numpy.fft.fftshift)|Shift the zero-frequency component to the center of the spectrum.|
|[ifftshift(x[, axes])](https://numpy.org/doc/stable/reference/generated/numpy.fft.ifftshift.html#numpy.fft.ifftshift)|The inverse of fftshift.|

