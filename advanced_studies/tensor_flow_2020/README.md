# Deep Networks and Tensor Flow

**When in our modern world a problem is too tedious or too complicated to solve, it is always a good idea to promise an AI solution to handle the problem for us. AI, short for Artificial Intelligence, is the information age's word for magic. In this project, we will take a deeper look into machine learning. Machine learning is typically what the people on the street mean by AI. In machine learning, sophisticated algorithms extract the underlying statistical structure in large data sets, and use this knowledge to make predictions or inferences about incomplete test data (for example, recognizing objects in natural scenes). The exciting news from the vibrant community using these novel techniques is that deep networks are now magic for everybody: with just a little understanding of the underlying general principles, every scientist with basic knowledge in programming is able to use sophisticated techniques for applying machine learning to neuroscientific problems. And we will give you a headstart for diving into this exciting topic...**

First, some introductory words: Machine learning is a collective term for methods which are able to extract complex statistical dependencies from data sets (termed 'training data'). The learned machine is then used on new, formerly unknown, and incomplete data sets (termed 'test data') for making predictions about the missing part of those data. One example: As training data, you have images of handwritten numbers as well as information of what digits they contain (termed 'labels'). You then construct a machine based on this training data. Finally, you take formerly unknown images of some more handwritten numbers without corresponding labels, and give it as input to your machine. The machine's task is to predict which digits those new images contain, i.e. to find their missing labels. A famous data set used for benchmarking machine learning algorithms is the MNIST handwritten digit data base.

State of the art for using deep networks in machine learning is the so-called Tensor Flow framework [https://www.tensorflow.org](https://www.tensorflow.org) for more details) with its Keras API (Application Programming Interface). Tensor Flow is using the programming language Python3 (see [https://www.python.org](https://www.python.org) for more details). The name Python is not based on this type of snake. It is rather based on the [Britisch comedy team](https://en.wikipedia.org/wiki/Monty_Python) (check for references: spanish inquisition, dead parrot, I want to be a lumberjack, cheese shop, the life of Brian, ministry of silly walks, etc.). 

Tensor Flow and Python3 will most likely provide you with some nice surprises in this project. However, instead of feeling joy please be prepared to deal with a programming language that changes all the time and doesn't care about the users' experiences. Screams, tears and temper tantrums are nearly guaranteed. However, you will learn to deal with incomplete and partially outdated information and extract from it what you need to solve the task at hand.

On the other hand, Python3 is THE language in Computational Neurosciences and reached rank number 2 of the most frequently used computer languages in the world and is as such a worthy successor of BASIC.

Coming from Matlab, it is advised to look into this guide:

[https://docs.scipy.org/doc/numpy/user/numpy-for-matlab-users.html](https://docs.scipy.org/doc/numpy/user/numpy-for-matlab-users.html)

A series of short introduction videos can be found under: [Python Programming Tutorials](https://www.youtube.com/watch?v=bY6m6_IIN94&list=PLi01XoE8jYohWFPpC17Z-wWhPOSuh8Er-) (Computer Science) from the Socratica YouTube channel.

The official quick start tutorial for 'numpy': [https://docs.scipy.org/doc/numpy/user/quickstart.html](https://docs.scipy.org/doc/numpy/user/quickstart.html)

The official TensorFlow 2/Keras tutorials: [https://www.tensorflow.org/tutorials](https://www.tensorflow.org/tutorials)

The official Python3 tutorial can be found under: [https://docs.python.org/3/tutorial](https://docs.python.org/3/tutorial)

Besides getting programs done in Python, the main goal of this project is to learn how to train and to use deep neuronal networks to perform classification tasks for us.

The ToDo-list for the project is:

## 1: Installing the Python3 development environment and getting used to jupyter-Lab.

Obviously, we need Python3 to run Python programs. jupyter-lab provides a nice environment for developing programs for Python.

### a.
Go to [https://www.anaconda.com/distribution](https://www.anaconda.com/distribution) and download the free(!) Python 3.7(!) package. Notes for Linux: Install it into your home directory, e.g. **/home/[YOUR USER NAME]/anaconda3**. Anaconda handles your Python installation and additional packages and tools you might need.

### b.
Make sure to install the packages \**numpy**, **matplotlib**, **jupyter-lab**, and **Tensor Flow 2.1.0**. (Hint 1: Open an anaconda prompt (Windows) or a new terminal (Linux) and type **conda**. Hint 2: If Conda shows you only older versions of Tensor Flow, an update of Anaconda via the Conda tool will help).

### c.
Open a juypter notebook (Windows) or get a jupyter-lab instance running in a terminal (Linux), open it with a web browser and create a new notepad.



## 2: Getting familiar with Python

The packages you installed in the previous task together with Python3 allow you to work in a similar way  like you know from Matlab. However, Python3 has a different syntax and is an object-oriented language -- this task will help you to get acquainted with the basic concepts: defining variables, controlling program flow with loops and conditional execution, printing messages and displaying elementary graphics. Please view the short introductory videos from the Socratica YouTube channel (see link above) and try to re-write some older Matlab programs from the CNS-I or Programming lectures -- or simply try to create a set of 10 random numbers as a **numpy**-array and plot it with **matplotlib**.

## 3: Handling data.

If you look at the usual tutorial of Tensor Flow, they will assume that your computer can store all the training and test data in memory at the same time. For most problems with large data sets, this assumption is bad. Thus we will use a so-called 'data generator' which loads the data on-demand.

### a. 
Download the MNIST dataset from [http://yann.lecun.com/exdb/mnist](http://yann.lecun.com/exdb/mnist) and extract the four files using 7-zip (Windows: [https://www.7-zip.org](https://www.7-zip.org)) or gzip (Linux) (Hint: Under Linux use **man gzip** in a terminal for understanding how gzip works).

### b. 
Data is never delivered on a silver platter. Write your own file loader for the images and the labels. The file format is explained at the end of the webpage (Hint: Python3 commands you want to look at: **open** \& **read** \& **close** for files, **numpy.frombuffer** and **numpy.newbyteorder('>')**.

### c. 
Reshape the data you extracted from the MNIST files into 2D pictures. Plot examples of them with **matplotlib**. Save the single pictures with their labels via **numpy.savez** into single files, i.e. one picture plus its label into one file. Training data goes into a **train**-folder and test data goes into a **test**-folder.

### d. 
Build a data generator that uses these files. A data generator is derived from **keras.utils.Sequence** and needs the methods **\_\_init\_\_** , **on\_epoch\_end**, **\_\_getitem\_\_** , **\_\_data\_generation** and **\_\_len\_\_** ( Hint: Obviously we need to load in the data we saved. Use **numpy.load**.)

## 4: Setting up a deep network and training it to recognize handwritten digits

### a.
Build a Tensor flow network. The structure of the network shall be:

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

## ADV 5. Long-Short-Term-Memory (LSTM) networks

If deep convolutional networks were too easy for you and you ended up at this task with nothing else to do, in this optional task you will take a look at Long Short Term Memory networks or in short LSTM networks. LSTM are a class of recurrent neuronal networks (RNNs). While the network in the prior task handled static pictures, LSTMs can be used to work with time series or series of events. After reading and hopefully understanding paper [3], you will try to implement the example from the tensor flow tutorial ['Text generation with an RNN'](https://www.tensorflow.org/tutorials/text/text\_generation), but using LSTMs.

## Literature
[1] Schmidhuber J. (2015). **Deep learning in neural networks**. *Neural Netw.* 61, C (January 2015), 85--117. DOI:https://doi.org/10.1016/j.neunet.2014.09.003

[2] Guo Y., Liu Y., Oerlemans A., Lao S., Wu S., and Lew M. S. (2016). **Deep learning for visual understanding: A review**, *Neurocomputing* 187, 27--48, https://doi.org/10.1016/j.neucom.2015.09.116.

[3] Greff, K., Srivastava, R. K., Koutnik, J., Steunebrink B. R., and Schmidhuber, J. (2017). **LSTM: A Search Space Odyssey**, in: *IEEE Transactions on Neural Networks and Learning Systems* 28(10), 2222--2232.

