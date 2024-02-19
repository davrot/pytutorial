<span style="color:#FFFFCC"> __Topic \#3__ </span>  <span style="color:#FFCC00"> __Data __ </span>  <span style="color:#FFCC00"> __analysis__ </span>

![](img/T3_DataAnalysis0.png)

<span style="color:#0070C0"> __Fiddling__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __with__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __signals__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __and__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __frequencies__ </span>

sampling\, frequency space representations\, filters and filter properties\, convolution theorem

<span style="color:#0070C0"> __Spectral__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __analysis__ </span>

\(windowed\) Fourier\, Hilbert\, wavelets\, coherence measures

<span style="color:#0070C0"> __Multidimensional __ </span>  <span style="color:#0070C0"> __representations__ </span>

PCA\, ICA\, SVD\, k\-means

<span style="color:#0070C0"> __Classification__ </span>

ROC\, k\-NN\, SVM

<span style="color:#0070C0"> __Fiddling__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __with__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __signals__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __and__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __frequencies__ </span>

frequency above Nyquist

__Sampling__

Sampled signals have a limited time resolution and a limited range and precision

2 bits range = 4 states

__Reminder__  __: __  __the__  __ Fourier __  __transform__

__Signals s\(t\)__  can also be represented in Fourier space as  __complex__  __ __  __coefficients__  __ S\(f\)__ \. Transform forth and back by \(inverse\)  __Fourier __  __transform__ \. Visualize a Fourier\-transformed signal as  __power __  __spectral__  __ __  __density__  \(remember lecture/exercise in Theo\. Neurosciences\):

![](img/T3_DataAnalysis1.png)

some interesting signal feature at f=10 Hz

…there‘s a hole in the bucket\, dear Liza\, dear Liza\!

_https://en\.wikipedia\.org/wiki/There%27s\_a\_Hole\_in\_My\_Bucket_

_source_  _: neuroimage\.usc\.edu_

__How__  __ __  __can__  __ __  __we__  __ __  __extract__  __ __  __signals__  __ at __  __frequency__  __ __  __ranges__  __ __  __of__  __ __  __interest__  __\, __  __or__  __ __  __put__  __ __  __holes__  __ in __  __the__  __ __  __spectrum__  __ __  __of__  __ __  __the__  __ __  __data__  __?__

![](img/T3_DataAnalysis2.png)

Visualizing in frequency space what a filter does…

amplitude drops to ~70%

![](img/T3_DataAnalysis3.png)

_https://www\.allaboutcircuits\.com/technical\-articles/an\-introduction\-to\-filters/_

__Quality __  __factor__ :

<span style="color:#0070C0"> __Q=f0/\(f2\-f1\)__ </span>

__dB = __  __decibel__  __: __ defined as  <span style="color:#0070C0"> __10 log\(P2/P1\) dB __ </span> for  __power __  __ratio__  P2 vs\. P1

…therefore\,  <span style="color:#0070C0"> __20 log\(A2/A1\) dB __ </span> for  __amplitude__  __ __  __ratios__ \!

\(note that mathematical „log“ is numpyically „log10“\!\)

__Filter __  __order__ :

<span style="color:#0070C0"> __~ __ </span>  <span style="color:#0070C0"> __slope__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __of__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __decay__ </span>

![](img/T3_DataAnalysis4.png)

__Filtering__  __ __  __with__  __ Python__

We like the butterworth filter provided by the  <span style="color:#0070C0"> __scipy\.signal__ </span>  <span style="color:#0070C0"> __ __ </span> module\. One uses  <span style="color:#0070C0"> __butter__ </span>  to construct the filter\, and  <span style="color:#0070C0"> __filtfilt__ </span>  to apply the constructed filter to a time series:

![](img/T3_DataAnalysis5.png)

__Sample __  __signals__  __ __  __used__  __ in __  __the__  __ __  __following__  __ __  __slides__  __:__

![](img/T3_DataAnalysis6.png)

![](img/T3_DataAnalysis7.png)

![](img/T3_DataAnalysis8.png)

![](img/T3_DataAnalysis9.png)

__High\-pass __  __and__  __ __  __bandpass__

![](img/T3_DataAnalysis10.png)

![](img/T3_DataAnalysis11.png)

![](img/T3_DataAnalysis12.png)

<span style="color:#FF0000"> __beware__ </span>  <span style="color:#FF0000"> __\!__ </span>

<span style="color:#FF0000"> __transients__ </span>  <span style="color:#FF0000"> __\!__ </span>

![](img/T3_DataAnalysis13.png)

Filters imply phase shifts\. To compensate\, combine for\- and backward filtering\.

Filter first before downsampling \(see example\)\.

To inspect a filter\, filter a white noise signal and plot PSD\.

Take care\, transients at start and end of signal

The more parameter you specify\, the more difficult is it to design a filter

<span style="color:#0070C0"> __blue__ </span>  <span style="color:#0070C0"> __: __ </span>  <span style="color:#0070C0">original </span>  <span style="color:#0070C0">signal</span>  <span style="color:#0070C0">\, </span>  <span style="color:#0070C0">sampled</span>  <span style="color:#0070C0"> at 2500 Hz</span>

<span style="color:#FF0000"> __red__ </span>  <span style="color:#FF0000"> __: __ </span>  <span style="color:#FF0000">downsampled</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">to</span>  <span style="color:#FF0000"> 25 Hz</span>

__black__  __: __ first filtered\, then downsampled to 25 Hz

The convolution theorem states that  <span style="color:#C00000">in Fourier </span>  <span style="color:#C00000">space</span>  <span style="color:#C00000">\, </span>  <span style="color:#C00000">convolutions</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">are</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">expressed</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">by</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">multiplication</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">of</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">the</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">transformed</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">signal</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">and</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">filter</span> \.

If you transform a filter into Fourier space\, you can investigate its properties by considering it a ‚mask‘ for your time series representation\.

You can  <span style="color:#C00000">use</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">the</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">convolution</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">theorem</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">to</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">perform</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">convolutions</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">efficiently</span> \, using FFT\.

<span style="color:#FF0000"> __Example__ </span>  <span style="color:#FF0000"> __: __ </span>  <span style="color:#FF0000"> __low__ </span>  <span style="color:#FF0000"> __\-pass __ </span>  <span style="color:#FF0000"> __filter__ </span>

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/scipy/scipy\.signal\_butterworth](https://davrot.github.io/pytutorial/scipy/scipy.signal_butterworth/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/scipy/scipy.signal_butterworth/)</span>

<span style="color:#0070C0"> __Spectral__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __analysis__ </span>

__ __  __ANDA __  __tutorial__  __…__

<span style="color:#FF0000">Switch</span>

<span style="color:#FF0000">presentations</span>

__Wavelet Transform in Python__

One can use the  <span style="color:#0070C0"> __pywt__ </span>  module\, and requires essentially only two commands for creating a ‚mother wavelet‘ and applying it to the time series of interest:

<span style="color:#6A9955">\# The wavelet we want to use\.\.\.</span>

<span style="color:#9CDCFE">mother</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">pywt</span>  <span style="color:#CCCCCC">\.ContinuousWavelet</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#CE9178">"cmor1\.5\-1\.0"</span>  <span style="color:#CCCCCC">\)</span>

<span style="color:#6A9955">\# \.\.\.applied with the parameters we want:</span>

<span style="color:#9CDCFE">complex\_spectrum</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">frequency\_axis</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">pywt</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#DCDCAA">cwt</span>  <span style="color:#CCCCCC">\(</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#9CDCFE">data</span>  <span style="color:#D4D4D4">=</span>  <span style="color:#9CDCFE">test\_data</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">scales</span>  <span style="color:#D4D4D4">=</span>  <span style="color:#9CDCFE">wave\_scales</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">wavelet</span>  <span style="color:#D4D4D4">=</span>  <span style="color:#9CDCFE">mother</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">sampling\_period</span>  <span style="color:#D4D4D4">=</span>  <span style="color:#9CDCFE">dt</span>

<span style="color:#CCCCCC">\)</span>

However\, working with the wavelet transform requires to think about the scales or frequency bands\, their spacing\, proper definition of time/frequency resolution\, taking care of the cone\-of\-interest etc…

Full code at: [https://davrot\.github\.io/pytutorial/pywavelet](https://davrot.github.io/pytutorial/pywavelet/)[/](https://davrot.github.io/pytutorial/pywavelet/)

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/pywavelet](https://davrot.github.io/pytutorial/pywavelet/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/pywavelet/)</span>

<span style="color:#0070C0"> __Multidimensional __ </span>  <span style="color:#0070C0"> __representations__ </span>

Neural recordings often yield a large number of signals xi\(t\)\.

Typically\, these signals contain a mixture of \(internal and external\) sources sj\(t\)\.  __Example__  __: __ One EEG signal contains the activity of millions of neurons\.

__Goal: __ find the neural sources s\(t\) contained in the signals x\(t\)

__Also:__

Assessment of dimensionality of a representation

Dimensionality reduction\. Get the principal components\.

Remove common sources \(common reference\, line noise\, heartbeat artifacts\, etc\.\)

…

__PCA – __  __principal__  __ __  __component__  __ __  __analysis__

Find sources which are  <span style="color:#C00000">uncorrelated</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">with</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">each</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">other</span> \. Uncorrelated means that the  <span style="color:#C00000">source</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">vectors</span>  <span style="color:#C00000"> S will </span>  <span style="color:#C00000">be</span>  <span style="color:#C00000"> orthogonal </span>  <span style="color:#C00000">to</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">each</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">other</span> \.

PCA finds matrix WPCA such that X is explained by X = S WPCA\.

![](img/T3_DataAnalysis14.png)

remove mean?

remove std?

<span style="color:#000000">W</span>  <span style="color:#000000">PCA</span>  <span style="color:#000000">\-1</span>  <span style="color:#000000"> = W</span>  <span style="color:#000000">PCA</span>  <span style="color:#000000">T</span>  <span style="color:#000000">\, so S = X </span>  <span style="color:#000000">W</span>  <span style="color:#000000">PCA</span>  <span style="color:#000000">T</span>  <span style="color:#000000"> </span>

__Example__  __: n __  __signals__  __ __  __of__  __ __  __duration__  __ t: __

S: \(t x n\) – n source vectors

WPCA: \(n x n\) – mixture matrix

X: \(t x n\) – n observation vectors

<span style="color:#000000"> __Visualization__ </span>  <span style="color:#000000"> __:__ </span>

<span style="color:#000000">W</span>  <span style="color:#000000">PCA</span>  <span style="color:#000000">\[k\, :\] </span>  <span style="color:#000000">shows</span>  <span style="color:#000000"> </span>  <span style="color:#000000">how</span>  <span style="color:#000000"> </span>  <span style="color:#000000">the</span>  <span style="color:#000000"> k\-</span>  <span style="color:#000000">th</span>  <span style="color:#000000"> </span>  <span style="color:#000000">component</span>  <span style="color:#000000"> </span>  <span style="color:#000000">contributes</span>  <span style="color:#000000"> </span>  <span style="color:#000000">to</span>  <span style="color:#000000"> </span>  <span style="color:#000000">the</span>  <span style="color:#000000"> n </span>  <span style="color:#000000">observations</span>  <span style="color:#000000">: </span>

![](img/T3_DataAnalysis15.png)

![](img/T3_DataAnalysis16.png)

__PCA – __  __principal__  __ __  __component__  __ __  __analysis__  __: Python__

Use  <span style="color:#0070C0"> __class__ </span>  <span style="color:#0070C0"> __ PCA __ </span> from  <span style="color:#0070C0"> __sklearn\.decomposition__ </span>  module:

![](img/T3_DataAnalysis17.png)

After defining an instance\, you can use  <span style="color:#0070C0"> __fit__ </span>  for fitting a transform\, and  <span style="color:#0070C0"> __transform__ </span>  for transforming X to S\.

<span style="color:#0070C0"> __fit\_transform__ </span>  combines these steps\, and  <span style="color:#0070C0"> __inverse\_transform__ </span>  <span style="color:#0070C0"> __ __ </span> does the transfrom from S to X\.

The attribute  <span style="color:#0070C0"> __components__ </span>  <span style="color:#0070C0"> __\___ </span>  will contain the PCA transformation components

Components will be  <span style="color:#C00000">sorted</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">with</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">descending</span>  <span style="color:#C00000"> \(</span>  <span style="color:#C00000">explained</span>  <span style="color:#C00000">\) </span>  <span style="color:#C00000">variance</span> \.

<span style="color:#C586C0">from</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">sklearn</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#4EC9B0">decomposition</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#C586C0">import</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">PCA</span>

<span style="color:#339933">\# </span>  <span style="color:#339933">transform</span>  <span style="color:#339933"> x </span>  <span style="color:#339933">to</span>  <span style="color:#339933"> s</span>  <span style="color:#9CDCFE">pca</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">PCA</span>  <span style="color:#CCCCCC">\(\)</span>

<span style="color:#9CDCFE">s</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">pca</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#DCDCAA">fit\_transform</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">x</span>  <span style="color:#CCCCCC">\)</span>

<span style="color:#9CDCFE">w\_pca</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">pca</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#9CDCFE">components</span>  <span style="color:#9CDCFE">\_</span>

<span style="color:#00B050">\# </span>  <span style="color:#00B050">transform</span>  <span style="color:#00B050"> s </span>  <span style="color:#00B050">to</span>  <span style="color:#00B050"> x</span>

<span style="color:#9CDCFE">x\_recover</span>  <span style="color:#9CDCFE"> = </span>  <span style="color:#9CDCFE">pca\.</span>  <span style="color:#DCDCAA">inverse\_transform</span>  <span style="color:#9CDCFE">\(s\)</span>

<span style="color:#9CDCFE">also\_x\_recover</span>  <span style="color:#9CDCFE"> = </span>  <span style="color:#9CDCFE">s@w\_pca</span>

<span style="color:#000000">W</span>  <span style="color:#000000">PCA</span>  <span style="color:#000000">\-1</span>  <span style="color:#000000"> = W</span>  <span style="color:#000000">PCA</span>  <span style="color:#000000">T</span>  <span style="color:#000000">\, so S = X </span>  <span style="color:#000000">W</span>  <span style="color:#000000">PCA</span>  <span style="color:#000000">T</span>  <span style="color:#000000"> </span>

<span style="color:#C00000"> __Take care\! __ </span>  <span style="color:#C00000"> __Instead__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __of__ </span>  <span style="color:#C00000"> __ X __ </span>  <span style="color:#C00000"> __= S __ </span>  <span style="color:#C00000"> __W__ </span>  <span style="color:#C00000"> __PCA__ </span>  <span style="color:#C00000"> __\, __ </span>  <span style="color:#C00000"> __the__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __transform__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __is__ </span>  <span style="color:#C00000"> __ also __ </span>  <span style="color:#C00000"> __often__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __defined__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __as__ </span>  <span style="color:#C00000"> __ X‘ __ </span>  <span style="color:#C00000"> __= __ </span>  <span style="color:#C00000"> __W__ </span>  <span style="color:#C00000"> __PCA__ </span>  <span style="color:#C00000"> __ S‘\. This __ </span>  <span style="color:#C00000"> __makes__ </span>  <span style="color:#C00000"> __ X‘\, S‘ \(n x t\) __ </span>  <span style="color:#C00000"> __instead__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __of__ </span>  <span style="color:#C00000"> __ \(t x n\) __ </span>  <span style="color:#C00000"> __matrices__ </span>  <span style="color:#C00000"> __\!__ </span>

__SVD – Singular Value __  __Decomposition__

The singular value decomposition decmposes a matrix  __M__  into two unitary matrices U and V\, and a diagonal matrix ∑:  <span style="color:#0070C0"> __M = U__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __∑ V\* __ </span>

Assumptions are UTU = UUT = I\, and VTV = VVT = I with I being the unit matrix\.

![](img/T3_DataAnalysis18.png)

__Relation __  __to__  __ PCA: __ Consider m denotes ‚time‘ t\,and n <=t\. Then M are the observations X\, V\* will be WPCA\, and S = U ∑ the uncorrelated principal components\, related via:  __X = S W__  __PCA__ \.

__ICA – __  __independent__  __ __  __component__  __ __  __analysis__

ICA assumes also a  <span style="color:#C00000">linear </span>  <span style="color:#C00000">mixture</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">of</span>  <span style="color:#C00000"> ‚</span>  <span style="color:#C00000">sources</span>  <span style="color:#C00000">‘ via X = S </span>  <span style="color:#C00000">W</span>  <span style="color:#C00000">ICA </span> \. However\, here the goal is to find sources which are  <span style="color:#C00000">statistically</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">independent</span>  <span style="color:#C00000"> </span> to each other\.

__The ICA __  __transform__  __ __  __is__  __ not __  __unique__  __ __  __and__  __ __  __depends__  __ on __  __the__  __ __  __independence__  __ __  __criterion__  __\!__

remove mean?

remove std?

is STS trivially diagonal?

![](img/T3_DataAnalysis19.png)

When might ICA be more appropriate than PCA?  __Example__  __:__  __ __

__Independence __  __criteria__  __:__

minimization of mutual information

maximization of non\-Gaussianity

__ICA – __  __independent__  __ __  __component__  __ __  __analysis__  __: Python__

Use  <span style="color:#0070C0"> __class__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __FastICA__ </span>  <span style="color:#0070C0"> __ __ </span> from  <span style="color:#0070C0"> __sklearn\.decomposition__ </span>  module\. The usage is very similar to  <span style="color:#0070C0"> __PCA__ </span> \.

<span style="color:#C586C0">from</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">sklearn</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#4EC9B0">decomposition</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#C586C0">import</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">FastICA</span>

<span style="color:#6A9955">\# </span>  <span style="color:#6A9955">transform</span>  <span style="color:#6A9955"> x </span>  <span style="color:#6A9955">to</span>  <span style="color:#6A9955"> s</span>

<span style="color:#9CDCFE">ica</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">FastICA</span>  <span style="color:#CCCCCC">\(\)</span>

<span style="color:#9CDCFE">s</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">ica</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#DCDCAA">fit\_transform</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">x</span>  <span style="color:#CCCCCC">\)</span>

<span style="color:#9CDCFE">w\_ica</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">ica</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#9CDCFE">components</span>  <span style="color:#9CDCFE">\_</span>

<span style="color:#6A9955">\# </span>  <span style="color:#6A9955">transform</span>  <span style="color:#6A9955"> s </span>  <span style="color:#6A9955">to</span>  <span style="color:#6A9955"> x</span>

<span style="color:#9CDCFE">x\_recover</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">ica</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#DCDCAA">inverse\_transform</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">s</span>  <span style="color:#CCCCCC">\)</span>

remove mean?

remove std?

is STS trivially diagonal?

![](img/T3_DataAnalysis20.png)

We have  __multidimensional __  __samples__  __ X__  and expect that they stem from different ‚classes‘\, e\.g\. spike waveforms where spikes from one particular cell constitute one class\. Samples from a particular class should have smaller distance than samples stemming from different classes:

__The k\-__  __means__  __ Clustering __  __Algorithm__

![](img/T3_DataAnalysis21.png)

_description_  _ _  _and_  _ _  _animation_  _ _  _from_  _ Wikipedia_

![](img/T3_DataAnalysis22.gif)

__cluster\_centers__  __\___

![](img/T3_DataAnalysis23.png)

__The k\-__  __means__  __ Clustering __  __Algorithm__  __: Python__

![](img/T3_DataAnalysis24.png)

![](img/T3_DataAnalysis25.png)

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/scikit\-learn/overview](https://davrot.github.io/pytutorial/scikit-learn/overview/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/scikit-learn/overview/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/scikit\-learn/pca](https://davrot.github.io/pytutorial/scikit-learn/pca/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/scikit-learn/pca/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/scikit\-learn/fast\_ica](https://davrot.github.io/pytutorial/scikit-learn/fast_ica/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/scikit-learn/fast_ica/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/scikit\-learn/kmeans](https://davrot.github.io/pytutorial/scikit-learn/kmeans/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/scikit-learn/kmeans/)</span>

__Classification__  __ __  __yields__  __ __  __information__  __ __  __about__  __ __  __information__  __ in __  __data__  __…__

__Receiver\-operator\-__  __characteristics__  __ \(ROC\): __ a simple tool for quick inspection for both simple and complex data sets

__K\-__  __nearest__  __\-__  __neighbor__  __ __  __classifier__  __ \(__  __kNN__  __\): __ easy to implement\, suited for a quick inspection

__Support __  __vector__  __ __  __machine__  __ \(SVM\): __ an almost state\-of\-the\-art tool for \(non\-\)linear classification of large data sets\. Very useful if you don‘t want to fire up your deep network and NVidia GPU for every almost trivial problem…

<span style="color:#FF0000"> __Important__ </span>  <span style="color:#FF0000"> __: __ </span>  <span style="color:#FF0000">For</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">classification</span>  <span style="color:#FF0000">\, </span>  <span style="color:#FF0000">you</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">need</span>  <span style="color:#FF0000"> a </span>  <span style="color:#FF0000"> __training__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __data__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __set__ </span>  <span style="color:#FF0000">\, </span>  <span style="color:#FF0000">and</span>  <span style="color:#FF0000"> a </span>  <span style="color:#FF0000"> __test__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __data__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __set__ </span>  <span style="color:#FF0000">\. </span>  <span style="color:#FF0000">Each</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">data</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">set</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">contains</span>  <span style="color:#FF0000"> \(a large </span>  <span style="color:#FF0000">number</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">of</span>  <span style="color:#FF0000">\) </span>  <span style="color:#FF0000"> __samples__ </span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">together</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">with</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">their</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000"> __labels__ </span>  <span style="color:#FF0000">\. </span>  <span style="color:#FF0000">You</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">are</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000"> __not __ </span>  <span style="color:#FF0000"> __allowed__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __to__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __use__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __the__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __test__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __set__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __for__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __training__ </span>  <span style="color:#FF0000">\.</span>

![](img/T3_DataAnalysis26.png)

__Receiver\-Operator __  __Characteristics__

The situation: one recorded signal r\, two potential causes „\+“ or „\-“:

__radio__  __ __  __signal__  __ r=__  __enemy__  __ __  __plane __  __\(\-\) __  __or__  __ __  __swarm__  __ __  __of__  __ __  __birds__  __ \(\+\)?__

__How__  __ __  __can__  __ __  __we__  __ __  __distinguish__  __ __  __between__  __ „\+“ __  __and__  __ „\-“?__

Simplest estimator: use threshold z\, if sample r0 is smaller than z\, attribute to „\-“\, otherwise to „\+“

Can we find an  __optimal z__ ? Yes\, the idea is to plot the  __true__  __ positives \(__  __β__  __\) __ against the  __false__  __ positives \(__  __α__  __\)__  while changing z \(ROC curve\)\. Classification accuracy has a  __maximum__  __/__  __minimum__  __ __  __when__  __ __  __the__  __ __  __rates__  __ __  __of__  __ __  __change__  __ __  __are__  __ __  __equal__  __ __  <span style="color:#990099"> __\(__ </span>  <span style="color:#990099"> __slope__ </span>  <span style="color:#990099"> __=1\)__ </span> \.

__Summary: __  __ROC'n'Roll__

…it‘s a nice tool for quick inspection how well a scalar variable allows to discriminate between two situations\!

<span style="color:#660066"> __What's wrong if the ROC curve is under the diagonal?__ </span>

__Discriminability__  __: __ difference of means relative to std:

d‘ := \(r\+\-r\- \)/ σ

__k\-__  __Nearest__  __\-__  __Neighbour__  __ __  __Classifier__  __:__

![](img/T3_DataAnalysis27.png)

Super\-easy to explain\, super\-easy to implement\, super memory consuming\!

The  <span style="color:#FF0000"> __x__ </span>  <span style="color:#FF0000"> __i__ </span>  are samples of the training data set with labels  <span style="color:#FF0000"> __y__ </span>  <span style="color:#FF0000"> __i__ </span> \.

Every sample from the test data set  <span style="color:#0070C0"> __inside__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __the__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __neighborhood__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __of__ </span>  <span style="color:#0070C0"> __ x__ </span>  <span style="color:#0070C0"> __42__ </span>  <span style="color:#0070C0"> __ \(__ </span>  <span style="color:#0070C0"> __Voronoi__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __cell__ </span>  <span style="color:#0070C0"> __\) __ </span> gets assigned the label  <span style="color:#FF0000"> __y__ </span>  <span style="color:#FF0000"> __42__ </span>  \(k=1\)…

…or the majority vote/mixture of the  <span style="color:#0070C0"> __labels__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __of__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __the__ </span>  <span style="color:#0070C0"> __ k __ </span>  <span style="color:#0070C0"> __nearest__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __neighbors__ </span> \.

__The __  __support__  __ __  __vector__  __ __  __machine__  __ \(SVM\)__

You know how a simple perceptron works \(lecture Theoretical Neurosciences\)? The SVM is doing the same thing\, but  <span style="color:#0070C0"> __transforms__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __the__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __data__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __into__ </span>  <span style="color:#0070C0"> __ a __ </span>  <span style="color:#0070C0"> __higher__ </span>  <span style="color:#0070C0"> __\-dimensional __ </span>  <span style="color:#0070C0"> __space__ </span>  <span style="color:#0070C0"> </span> before it performs a  <span style="color:#0070C0"> __linear __ </span>  <span style="color:#0070C0"> __classification__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __by__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __using__ </span>  <span style="color:#0070C0"> __ an __ </span>  <span style="color:#0070C0"> __appropriately__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __placed__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __separating__ </span>  <span style="color:#0070C0"> __ hyperplane__ </span> :

![](img/T3_DataAnalysis28.png)

<span style="color:#0070C0"> __separating__ </span>

<span style="color:#0070C0"> __hyperplane__ </span>

__Python __  __tools__  __ __  __for__  __ __  __elementary__  __ __  __classification__  __ __  __tasks__  __:__

__ROC__  and  __kNN__  – easy to code on your own \(and a good training for you\!\)…

![](img/T3_DataAnalysis29.png)

Learning an  __SVM__  is more tricky\. <span style="color:#0070C0"> __scikit\-learn__ </span>  provides you with a good tool:

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/numpy/roc](https://davrot.github.io/pytutorial/numpy/roc/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/numpy/roc/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/numpy/knn](https://davrot.github.io/pytutorial/numpy/knn/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/numpy/knn/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/scikit\-learn/svm](https://davrot.github.io/pytutorial/scikit-learn/svm/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/scikit-learn/svm/)</span>

