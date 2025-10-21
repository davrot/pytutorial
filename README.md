# How to Python in computational neuroscience, data mining, and more 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

All the tutorials are tested with Python 3.11.x. Older version might have a problem with the new versions of type anotations. 

## Flow chart
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)

## Workflow
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Python: The Basics of the basics
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Python: Special topics
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Numpy: The Basics of the basics
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Numpy: Special topics
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Numpy: Matlab topics
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Matplotlib.pyplot
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)

## Pandas 
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Sci-kit Learn
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)

## SciPy
[Lives now here](https://mscneuro.neuro.uni-bremen.de/index.php/Python_Tutorial)


## Python: Questions of spectral nature
* [PyWavelets: Wavelet Transforms in Python](pywavelet/README.md)
* [Instantanious Spectral Coherence](data_analysis/spectral_coherence/README.md)
* [Linearize the spectral coherence](data_analysis/spectral_coherence_scale/README.md)


## Python: Daily little helper
* [TQDM: Make your progress visible](helper/TQDM/README.md)
* [Argh: Organize your command line arguments](helper/argh/README.md)
* [psutil vs os.cpu_count: How many "CPUs" do I have?](helper/psutil/README.md)
* [ZeroMQ: Microservices as well as connecting computers via message queue](helper/ZeroMQ/README.md)
* [Austin: Time and memory profiling](helper/austin/README.md)

## OpenCV2 and Python
* [OpenCV2: Play, write, read a video](cv2/write_read_play/README.md)
* [How to read a webcam with CV2](cv2/webcam/README.md)

## PyTorch 
* [Get CUDA ready!](pytorch/cuda/README.md)
* [Converting the original MNIST files into numpy](pytorch/MNIST/README.md) 
* [Interfacing Data](pytorch/interfacing_data/README.md)
* [Data augmentation](pytorch/augmentation/README.md)
* [Layers](pytorch/layers/README.md)
* [Creating networks](pytorch/networks/README.md)
* [Train the network](pytorch/train/README.md)
* [Fisher Exact Test: Test if your performance difference is significant](scipy/scipy.stats.fisher_exact/README.md)
* [Write your own layer](pytorch/own_layer/README.md)
  - [Replace the automatic autograd with your own torch.autograd.Function](pytorch/replace_autograd/README.md)
* [How to take advantage of an optimizer for your non-Pytorch project](pytorch/optimizer_special/README.md)
* [How to take advantage of a learning rate scheduler for your non-Pytorch project](pytorch/scheduler_special/README.md)
* [Unfold: How to manually calculate the indices for a sliding 2d window](pytorch/Unfold/README.md)

## PyBind11
* [Expanding Python with C++ modules](PyBind11/basics/README.md)
* [The fast and furious way (CPU and GPU CUDA)](PyBind11/direct/README.md)
* [PyBind11 Stub-Generation](PyBind11/stubs/README.md)

## Tensorflow / Keras 
* [A fast non-introduction](tensorflow/intro/README.md)

## Sympy
* [Symbolic Computation](sympy/intro/README.md)

## Numerical Integration, Differentiation, and Differential Equations
* [Integration and Differentiation](numpy/7/README.md) 
* [Differential Equations](numpy/8/README.md) 

## Arduino
* [Basics with Python / Matlab](arduino/basics/README.md)

## Matlab: Basics

{: .topic-optional}
This pages are in a rough state. e.g. equations are broken. Don't know why...

* [Basic Commands and Variables](matlab/3/README.md)
* [Graphics](matlab/4/README.md)
* [Vectorization and Vector Calculus in Matlab](matlab/6/README.md)
* [Data Analysis](matlab/9/README.md)


## Other topics 
* [Open Source Tools](other/open_source_tools/README.md)
* [Machine Learning Resources](other/ml_resources/README.md)
* [Datasets](other/datasets/README.md)

## S1: Advanced Programming (last update 16.02.2024)
* [S1 Advanced programming and data analysis](advanced_programming/overview_2024/README.md)
* [Preperations](advanced_programming/preperations/README.md)
* [Task 1 -- Classycal neurons: Simulation and Mathematical Anaylsis](advanced_programming/task_1/README.md)
* [Task 2 -- Collective coherent cortices: Data analysis](advanced_programming/task_2/README.md)
* Neuron Models Equations
  - For detailed descriptions, please see: ['Neuronal Dynamics' textbook](https://neuronaldynamics.epfl.ch/online) ['Theoretical Neuroscience' textbook](https://boulderschool.yale.edu/sites/default/files/files/DayanAbbott.pdf)
* Neuron Models Equations -- Rate-based neurons
  - [DivInE-model for MT neurons](advanced_programming/DivInE/README.md)
* Neuron Models Equations -- Spiking neurons without explicit spike generation mechanism
  - [Leaky Integrate-and-Fire](advanced_programming/leaky_integrate_and_fire/README.md)
  - [Exponential Integrate-and-Fire](advanced_programming/exponential_integrate_and_fire/README.md)
  - [Quadratic Integrate-and-Fire](advanced_programming/quadratic_integrate_and_fire/README.md)
  - [Connor Stevens](advanced_programming/connor_stevens/README.md)
* [References](advanced_programming/references/README.md)
* Task 1 -- Pictures for comparision
  - [Mandatory Tasks](advanced_programming/task_1_result_pictures/README.md)
* Task 2 -- Pictures for comparision
  - [Mandatory Tasks](advanced_programming/task_2_result_pictures/README.md)
  - [Voluntary Tasks: Preprocessing](advanced_programming/task_2_result_pictures_preprocessing/README.md)
  - [Voluntary Tasks: More Information!](advanced_programming/task_2_result_pictures_information/README.md)

## Advanced Studies
* Material from ages past
  - [2022: Preparation -- Python class with and without classes](advanced_studies/python_preparation_2022/README.md)
  - [2022: Deep Networks and Pytorch](advanced_studies/pytorch_2022/README.md)
  - [2022: Divisive inhibition: a dynamical circuit for change detection](advanced_studies/divisive_inhibition_2022/README.md)
  - [2022: Synchronization and dynamic oscillations in the visual system](advanced_studies/synchronization_2022/README.md)
  - [2020: Deep Networks and Tensor Flow](advanced_studies/tensor_flow_2020/README.md)
  - [2020: Divisive Normalization -- a Universal Concept for Adaptive Dynamics and Function of Cortical Circuits](advanced_studies/divisive_normalization_2020/README.md)
  - [2020: Recurrent networks: Temporal dynamics and synchronization](advanced_studies/recurrent_networks_2020/README.md)
  - [2017: Oscillations and information routing: CTC model](advanced_studies/CTC_2017/README.md)
  - [2017: Change detection: The DivInE-Model](advanced_studies/DivInE_2017/README.md)
  - [2017: Contour Integration](advanced_studies/contour_integration_2017/README.md)
  - [2017: Computation Spike by Spike](advanced_studies/sbs_2017/README.md)
  - [2017: Natural scenes and sparse coding in visual cortex](advanced_studies/sparse_coding_2017/README.md)


# Non Python tutorials:
* [Computer admin tutorials](admin/README.md)
  




