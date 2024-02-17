# Deep Networks and Pytorch

**When in our modern world a problem is too tedious or too complicated to solve, it is always a good idea to promise an AI solution to handle the problem for us. AI, short for Artificial Intelligence, is the information age’s word for magic. In this project, we will take a deeper look into machine learning. Machine learning is typically what the people on the street mean by AI. In machine learning, sophisticated algorithms extract the underlying statistical structure in large data sets, and use this knowledge to make predictions or inferences about incomplete test data (for example, recognizing objects in natural scenes). The exciting news from the vibrant community using these novel techniques is that deep networks are now magic for everybody: with just a little understanding of the underlying general principles, every scientist with basic knowledge in programming is able to use sophisticated techniques for applying machine learning to neuroscientific problems. And we will give you a headstart for diving into this exciting topic...**

First, some introductory words: Machine learning is a collective term for methods which are able to extract complex statistical dependencies from data sets (termed ’training data’). The learned machine is then used on new, formerly unknown, and incomplete data sets (termed ’test data’) for making predictions about the missing part of those data. 

One example: As training data, you have images of handwritten numbers as well as information of what digits they contain (termed ’labels’). You then construct a machine based on this training data. Finally, you take formerly unknown images of some more handwritten numbers without corresponding labels, and give it as input to your machine. The machine’s task is to predict which digits those new images contain, i.e. to find their missing labels. A famous data set used for benchmarking machine learning algorithms is the MNIST handwritten digit data base.


**A comprehensive introduction into deep learning is given in [1], and will help you in getting acquainted with the concepts, and in setting up a network for processing the data set which you select together with your supervisor.**

**Conduct research on your model (second \& third week):**

## 1. Setting up an exemplary deep network and training it to recognize handwritten digits

### a.
Build a PyTorch network for the MNIST dataset. The structure of the network shall be:

* Layer 1: 2D convolutional layer, 5x5 kernel with 1x1 stride, ReLU activation function and bias, 32 features/neurons
* Layer 2: Max pooling layer, 2x2 kernel with 2x2 stride
* Layer 3: 2D convolutional layer 5x5 kernel with 1x1 stride, ReLU activation function and bias, 64 features/neurons
* Layer 4: Max pooling layer, 2x2 kernel with 2x2 stride
* Layer 5: Dense layer with 1024 neurons, ReLU activation function and bias
* Layer 6 (Output layer): Dense layer with 10 neurons, Softmax activation function

### b.
Use an Adam optimizer for training. Check how the performance changes over several epochs (one epoch means all the training data was used once)

### c.
Save the weights for the first layer and for good measures the whole network, too.

### d.
Play with the parameters and investigate their impact on performance: Number of features/neurons, padding, kernel size \& strides, activation function and types of pooling layers, optimizers...

### e.
Switch from the MNIST database to the fashion MNIST database.

As reading material please look into the following parts of [1] taken from [https://d2l.ai](https://d2l.ai):

* Introduction
* Preliminaries
* Linear Neural Networks
* Multilayer Perceptrons
* Convolutional Neural Networks

Please don't lose too much time on their examples. Your goal is NOT to understand everything in those chapters. Your goal is to understand what is happening here:

* Prepare example data: \py{https://www.neurotec.uni-bremen.de/drupal/node/29}
* Data augmentation: \py{https://www.neurotec.uni-bremen.de/drupal/node/30}
* Interfacing your data: \py{https://www.neurotec.uni-bremen.de/drupal/node/32}
* Everything is a layer: \py{https://www.neurotec.uni-bremen.de/drupal/node/52}
* Creating networks: \py{https://www.neurotec.uni-bremen.de/drupal/node/53}
* Train the network: \py{https://www.neurotec.uni-bremen.de/drupal/node/54}


BTW, understanding means:
\vspace*{-1.3\topsep}
\begin{enumerate}[a)]
\setlength\itemsep{-0.5em}
\item Reproduce the MNIST network on your own.
\item If somebody ask you what the stuff means, you should be able to explain it to them.
\end{enumerate}

\textbf{Hint:} If you don't know what a PyTorch command is doing then there is an extensive documentation under: \py{https://pytorch.org}.
Just put the command in the search box...

\textbf{2. Now you are on your own...}

We will give you a dataset and then you have to deal with it on your own...

\phraselast

\literature{[1] A. Zhang, Z.C. Lipton, M. Li and A.J. Smola (2021), Dive into Deep Learning, \href{https://d2l.ai/d2l-en-pytorch.pdf}{https://d2l.ai/d2l-en-pytorch.pdf}}
