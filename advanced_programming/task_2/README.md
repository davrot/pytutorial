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


