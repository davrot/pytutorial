# [PyWavelets](https://pywavelets.readthedocs.io/en/latest/) -- Wavelet Transforms in Python
## The goal
How do we do wavelet transforms under Python?

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

You might want to read: [A Practical Guide to Wavelet Analysis](https://paos.colorado.edu/research/wavelets/)  ->  [PDF](https://paos.colorado.edu/research/wavelets/bams_79_01_0061.pdf)

```shell
pip install PyWavelets
```

## Which [continuous mother wavelets](https://pywavelets.readthedocs.io/en/latest/ref/cwt.html#continuous-wavelet-families) are available?

```python
import pywt

wavelet_list = pywt.wavelist(kind="continuous")
print(wavelet_list)
```

```Python console
['cgau1', 'cgau2', 'cgau3', 'cgau4', 'cgau5', 'cgau6', 'cgau7', 'cgau8', 'cmor', 'fbsp', 'gaus1', 'gaus2', 'gaus3', 'gaus4', 'gaus5', 'gaus6', 'gaus7', 'gaus8', 'mexh', 'morl', 'shan']
```

* The mexican hat wavelet "mexh" 
* The Morlet wavelet "morl"
* The complex Morlet wavelet ("cmorB-C" with floating point values B, C) 
* The Gaussian wavelets ("gausP" where P is an integer between 1 and and 8)
* The complex Gaussian wavelets ("cgauP" where P is an integer between 1 and 8)
* The Shannon wavelets ("shanB-C" with floating point values B and C)
* The frequency B-spline wavelets ("fpspM-B-C" with integer M and floating point B, C)

see [Choosing the scales for cwt](https://pywavelets.readthedocs.io/en/latest/ref/cwt.html#choosing-the-scales-for-cwt)

## Visualizing wavelets

```python
import numpy as np
import matplotlib.pyplot as plt
import pywt

wavelet_name: str = "cmor1.5-1.0"

# "linked" to how many peaks and
# troughs the wavelet will have
scale: float = 10

# Invoking the complex morlet wavelet object
wav = pywt.ContinuousWavelet(wavelet_name)

# Integrate psi wavelet function from -Inf to x
# using the rectangle integration method.
int_psi, x = pywt.integrate_wavelet(wav, precision=10)
int_psi /= np.abs(int_psi).max()
wav_filter: np.ndarray = int_psi[::-1]

nt: int = len(wav_filter)
t: np.ndarray = np.linspace(-nt // 2, nt // 2, nt)
plt.plot(t, wav_filter.real, label="real")
plt.plot(t, wav_filter.imag, label="imaginary")
plt.ylim([-1, 1])
plt.legend(loc="upper left")
plt.xlabel("time (samples)")
plt.title(f"filter {wavelet_name}")
```

![figure 1](image1.png)
