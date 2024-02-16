# Collective coherent cortices: Data analysis

## Background

In this exercise, we will investigate physiological recordings from visual areas V1 and V4. The experimental setting is comparable to the paradigm used in [Attention selectively gates afferent signal transmission to area V4](https://www.jneurosci.org/content/38/14/3441):

Each trial started with a baseline period of 500 ms without visual stimulus. Then two morphing shape sequences were presented for at least 1000 ms. The task for the animal was to attend one of the two stimuli, and to signal the reoccurrence of the initial shape of the attended sequence by releasing a lever.

During the experiment, electrophysiological recordings were done with $N=100$ electrodes (arranged in a 10 by 10 grid) in area V1, and a single electrode in area $V4$ whose receptive field (RF) covered both visual stimuli to a similar extent. The morphing shapes (let's name the sequences $A$ and $B$) were tagged with independent luminance variations ('flicker') for allowing the scientists to track visual information in the neural signals. 

Previous work in macaque monkeys established that visual signals are selectively routed in dependence on attention: computing the spectral coherence between V4 LFPs and flicker signals $A$ and $B$ reveals a substantially higher signal content of the attended flicker signal in the physiological data compared to the non-attended flicker signal (see [Attention selectively gates afferent signal transmission to area V4](https://www.jneurosci.org/content/38/14/3441)). In addition, it has been found that selective signal transfer goes along with enhanced phase synchronization between the corresponding visual areas (see [Switching neuronal inputs by differential modulations of gamma-band phase-coherence](https://www.jneurosci.org/content/32/46/16172)).

## Can these results be reproduced?

One for your classmates is a researcher studying selective processing in the visual system. Your classmate has recently read the paper [Attention selectively gates afferent signal transmission to area V4](https://www.jneurosci.org/content/38/14/3441) and now wants to know if results can be reproduces. To figure out, data was provided (The data was generated artificially) from the same experiment and has kindly shared it with you. Now, it's your duty as a good classmate to help answer the question.


## Data set
All data required for this exercise can be found in: [https://nc.uni-bremen.de/index.php/s/os5BC2nZeJGaJ8z](https://nc.uni-bremen.de/index.php/s/os5BC2nZeJGaJ8z)

The main data set **FlickerV1V4\_LFP1kHz.mat** comprises three arrays containing the data with a time resolution $dt = 1ms$ from $M=100$ trial repetitions over $T$ time bins:

**flicker\_signals (M x T x N)** -- flicker time series for stimuli $A$ and $B$

**V1\_lfp (M x T x N)** -- LFPs for $N=100$ V1 electrodes

**V4\_lfp (M x T)** -- LFP for one V4 electrode


## Mandatory Tasks

### 1.
The goal of this project is for you to practice the process of scientific research. Before getting into the tasks, try to think thoroughly about the data set you have and the experiment by which this dataset is obtained. What questions can you investigate having such data? What methods can you propose to utilize in order to explore these questions? How can you handle your data and write your code for having a well-structured solution with re-usable components, which is easy to understand for outsiders (which include YOU after not having looked into the code for two weeks)?
   
**We will ask some of you to present your thoughts on this task before you are going to implement the data analysis.**
    
## 2.
Some scientists believe that (selective) information processing in the visual system is strongly linked to oscillatory and coherent neural activity, which is modulated by attention. Spectral analysis helps you in discovering and pinpointing oscillatory components in neural signals.
  
Use **the wavelet transform** (see [A Practical Guide to Wavelet Analysis](https://doi.org/10.1175/1520-0477(1998)079<0061:APGTWA>2.0.CO;2)) to compute the trial-averaged amplitude spectrum over the whole trial duration and plot it. Make sure to transform your trials to have zero mean and unit standard deviation before applying the wavelet transform. Consider the parameters to choose for the analysis -- what would be an appropriate frequency range and spacing (linear or logarithmic)?

Which part of your result can you trust? -- include the cone-of-influence into your plot. Does the presentation of a stimulus generate oscillatory activity, and if yes, in which frequency band? 

## 3.
If appearance of stimuli is accompanied by enhanced oscillatory activity, you can use this dependence to determine **regions of interest (ROIs)** in the V1 neurons, i.e. sites that have the two visual stimuli in their receptive fields.
    
To do so, you can calculate the power spectrum in a specific frequency band for each channel and compare the oscillatory power across the neural population. Plot your results in a $10\times10$ grid. Where are the regions of interest? Select two neurons exhibiting the most significant power and report their corresponding indices.

## 4.

After performing the previous task, you might know which neurons are driven by visual stimuli, but not which site is responding to which individual stimulus [ie, flicker A or flicker B].

Find out by computing **phase coherence** and **spectral coherence** between the two selected neurons in V1 with each flicker signal. Compare the results.

For two **wavelet-transformed** signals with $a_1(t,f)$, $a_2(t,f)$ being the complex wavelet coefficients, the phase coherence $p(f) \in [0,1]$  is given by:        

$$p(f) = \left |\frac{1}{T}\sum_t^T \frac{a_1(t,f)}{\left| a_1(t,f)  \right |} \frac{\overline{a_2(t,f)}}{\left| a_2(t,f)  \right |} \right |$$
 
Similarly, you can compute the **spectral coherence** of these signals. The spectral coherence $c(f) \in [0,1]$ is given by:

$$c(f) = \frac{\left| \sum_t a_1(t,f) \overline{a_2(t,f)} \right|^2}{1}$$

{ \left( \sum_t \left| a_1(t,f)  \right|^2 \right) \left( \sum_t \left| a_2(t,f) \right|^2 \right)}
$T$ contains time and trials. 

\item 
% task 4
    In the experiment, attention was devoted to one of the visual stimuli. You do not know to which one, but you know that V4 will selectively respond to the attended stimulus.

    Compute the coherence of the V4 signal with each of the flicker signals. We first start with the \textbf{phase coherence}, and next apply the \textbf{spectral coherence}. Which of the two flicker stimuli is attended?

\item
% task 6a
    You might have observed that also V1 activity is modulated by attention (explain which result of your previous analysis supports such a statement!). How well can location of attention be decoded from one recorded electrode?

    % class\_dataset0\_train.npy -> Kobe\_V1\_LFP1kHz\_NotAtt\_train.npy
    % class\_dataset1\_train.npy -> Kobe\_V1\_LFP1kHz\_Att\_train.npy
    % class\_dataset0\_test.npy -> Kobe\_V1\_LFP1kHz\_NotAtt\_test.npy
    % class\_dataset1\_test.npy -> Kobe\_V1\_LFP1kHz\_Att\_test.npy
    Here you will use some machine-learning techniques to classify \textbf{attended} against \textbf{non-attended }signals based on V1 LFPs. For this purpose, you have been provided with:\\
    \texttt{Kobe\_V1\_LFP1kHz\_NotAtt\_train.npy} and\\
    \texttt{Kobe\_V1\_LFP1kHz\_Att\_train.npy}\\
    which contain training data sets for 100 trials recorded from one specific channel, corresponding to the non-attended and attended conditions, respectively. After applying any classifier, you can use  \texttt{Kobe\_V1\_LFP1kHz\_NotAtt\_test.npy} and \texttt{Kobe\_V1\_LFP1kHz\_Att\_test.npy} files to evaluate your results.

    To get started, similar to what was previously done, load these signals and compute their time-frequency spectrum for different frequency bands. Since you need these spectra for all the following sub-tasks, it is recommended that you save your results in separate files.

\item
% task 6b
    Implement the \textbf{ROC analysis} as your own function/module. Then compute the \textbf{ROC curve} for different frequency bands. Plot the ROC accuracy over different frequencies: in which band do you get a better performance? 


