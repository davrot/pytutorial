# How to Python in computational neuroscience, data mining, and more 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

All the tutorials are tested with Python 3.11.x. Older version might have a problem with the new versions of type anotations. 

## Flow chart
* [Basic Structure of a Computer](matlab/1/README.md)
* [Representation of Numbers in the Computer](matlab/2/README.md)
* [Flow chart symbols](flow/overview/README.md)
* [Examples](flow/examples/README.md)
* [Flow chart for baking bread](flow/baking_bread/README.md)

## Workflow
* [Python installation](workflow/python_pure/README.md)
* [VS Code installation](workflow/vscode_install/README.md)
* [VS Code configuration](workflow/vscode_config/README.md)
* [VS Code Microsoft Tutorials](workflow/microsoft_tutorials/README.md)
* [VS Code Python Interactive window](workflow/vscode_interactive/README.md)
* [VS Code Markdown](workflow/vscode_markdown/README.md)
* [VS Code Debugging](workflow/vscode_debug/README.md)
* [VS Code Working remotely via ssh](workflow/vscode_ssh/README.md)

Important VS Code notes:
* You can mark segments of source node with your mouse (or keyboard) and use the TAB key to increase the level of the indentation or use SHIFT + TAB do decrease the indentation level. ​
* Linux: CTRL + SHIFT + 7 toggles between comment and normal source code.​
* The function key F2 allows you to change variable and function names. VS Code goes through all the node in your Project directory and changes all occurrences of the function or variable name accordingly. The same is true if you change a file name in a project directory.   

## Python: The Basics of the basics
* [Overview](python_basics/where_to_start/README.md)
* [Hello, Python](python_basics/hello_python/README.md)
  - [input, print, string, int, float](python_basics/input_output_string_int_float/README.md)
* [Style Rulez](python_basics/style_rulez/README.md)
* [Programming Recommendations](python_basics/programming_recommendations/README.md)
  - [Assert](python_basics/assert/README.md) 
* [Basic Math Operations](python_basics/basic_math_operations/README.md)
* [Truth Value Testing](python_basics/truth_value_testing/README.md)
* [Formatted String Literals](python_basics/formatted_string_literals/README.md)
* [Flow Control Overview](python_basics/flow_control_overview/README.md)
  - [Flow Control: if, elif, else](python_basics/if/README.md)
  - [Flow Control: for-loop](python_basics/for/README.md)
  - [Flow Control: while, pass, break, continue](python_basics/while/README.md)
  - [Flow Control: match case](python_basics/match/README.md)
* Sequence Types
  - [Lists](python_basics/list/README.md)
    + [List Comprehensions​](python_basics/list_comprehensions/README.md)
  - [Tuple](python_basics/tuple/README.md)
    + [zip](python_basics/zip/README.md)
* Mapping Types
  - [Dict​](python_basics/dict/README.md)
* [Functions](python_basics/functions/README.md)
* [Type annotations](python_basics/python_typing/README.md)
* [Files](python_basics/files/README.md)
* [JSON and dict for parameter files](python_basics/json/README.md)
* [Creating order via sub-directories: os.makedirs](python_basics/os_makedirs/README.md)
* [Finding files in a directory: glob](python_basics/glob/README.md)
* [Class](python_basics/class/README.md)
* [Exceptions (try / except)](python_basics/exceptions/README.md)
* [Importing Modules](python_basics/modules/README.md)
* [Built-in Functions](python_basics/built_in/README.md)
* [Built-in Keywords](python_basics/keywords/README.md)

## Python: Special topics
* [pickle: save and load Python objects](python_basics/pickle/README.md)
* [The Python Standard Library​](python_basics/standard_libraries/README.md)
* [Dataclass](python_basics/dataclass/README.md)
* [Organizing parameters: dataclasses and dataconf](python_basics/dataconf/README.md)
* [ProcessPoolExecutor: A fast way to implement multiprocessing](python_basics/ProcessPoolExecutor/README.md)
* [Logging](python_basics/logger/README.md)
* [Python Scopes and Namespaces](python_basics/namespaces/README.md)
* [Collection of distinct hashable objects -- set and frozenset](python_basics/set_frozenset/README.md)

## Numpy: The Basics of the basics
* [The N-dimensional array (ndarray)​](numpy/ndarray/README.md)
  - [set_printoptions](numpy/set_printoptions/README.md)
* [Dimensions and shape](numpy/dimensions/README.md)
  - [Broadcasting: Automatic adaption of dimensions​](numpy/broadcasting/README.md)
* [Making a matrix from numerical ranges](numpy/numerical_ranges​/README.md)
* [Convert other data into numpy arrays e.g. asarray](numpy/convert_into_ndarray/README.md)
* [New matrix](numpy/new_matrix/README.md)
* [Save and load](numpy/load_save/README.md)
* [Reshape and flatten](numpy/reshape/README.md)
* [Slices and Views](numpy/slices_views/README.md)
* [Concatenate Matrices and arrays](numpy/concatenate/README.md)
* [Merging matrices](numpy/merging/README.md)
* [Unique](numpy/unique/README.md)
* [Where](numpy/where/README.md)
  - [Piecewise](numpy/piecewise​/README.md)
* [Extending an existing matrix: tile, repeat, pad](numpy/extending/README.md)
* [Boolean matricies and logic functions](numpy/bool_matrix/README.md)
* [Advanced Indexing](numpy/advanced_indexing/README.md)
  - [Ravel and UnRavel](numpy/ravel_unravel/README.md)
* [Available dtypes](numpy/dtype/README.md)
* [Constants](numpy/constants/README.md)
* [Math functions](numpy/math_functions/README.md)
* [Linear algebra](numpy/linear_alg/README.md)
* [Random numbers the non-legacy way](numpy/random/README.md)
* [Statistics](numpy/statistics/README.md)
* [FFT](numpy/fft/README.md)
  - [rfft and spectral power](numpy/numpy_fft_1/README.md)
* [Meshgrid](numpy/mesh_grid/README.md)
* [Flip, rot90, and roll a matrix](numpy/reverse_an_axis/README.md)
* Iterate
  - [ndenumerate](numpy/ndenumerate/README.md)
  - [ndindex](numpy/ndindex/README.md)
  - [flat](numpy/flat/README.md)

## Numpy: Special topics
* [Einstein summation](numpy/einstein/README.md)
* [Numba: Numpy just in time compiler -- speeding Numpy up](numpy/numba/README.md)
* [Memory layout of Numpy matrices](numpy/layout/README.md)
* [Stack and Split, Compress](numpy/stack_split/README.md)
* [Beyond normal np.save](numpy/save_special/README.md)
* [Trim Zeros of a 1d array](numpy/trim_zeros/README.md)
* Iterating over an array / matrix
  - [nditer provides many ways to visit all the elements of one or more arrays](numpy/nditer/README.md)
  - [Replacing an inner for loop with apply_along_axis](numpy/iterating/README.md)
  - [nested_iters](numpy/nested_iters/README.md)
* [Manipulation of integers and their bits](numpy/bits_and_integers​/README.md)
* [Numpy <-> JSON over Pandas](numpy/JSON/README.md)
* [Resize: Compensation for bad planning? Don't!](numpy/resize/README.md)
* [Dealing with the main diagonal / triangles of a matrix](numpy/diagonal_triangles/README.md)

## Numpy: Matlab topics
* [Dealing with Matlab files](numpy/mat_files/README.md)
* [Matlab is also just a Python package](matlab/matlab_as_a_python_pakage/README.md)
* [Running Python remotely from Matlab](matlab/python_used_by_matlab/README.md)

In the case you know Matlab check here: 
[NumPy for MATLAB users](numpy/matlab_guide/README.md)

## Matplotlib.pyplot
* [Simple plot and imshow examples](matplotlib/basics/README.md)
* [Subplot](matplotlib/subplot/README.md)
* [subplots and gridspec: A more flexible placement](matplotlib/subplots/README.md)
* [Overview of the available functions](matplotlib/overview/README.md)
* [Animation and Slider](matplotlib/animation_and_slider/README.md)

## Pandas 
* [Basics](pandas/basics/README.md)


## Sci-kit Learn 
* [Overview](scikit-learn/overview/README.md)
* [KMeans](scikit-learn/kmeans/README.md)
* [PCA](scikit-learn/pca/README.md)
* [FastICA](scikit-learn/fast_ica/README.md)


## SciPy
* [Remove a common signal from your data](scipy/SVD_data_cleaning/README.md)
* [scipy.signal: Butterworth low, high and band-pass](scipy/scipy.signal_butterworth/README.md)


## Python: Questions of spectral nature
* [PyWavelets: Wavelet Transforms in Python](pywavelet/README.md)


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

## Numerical Integration, Differentiation and Differential Equations (Matlab and Python code)
* [Integration and Differentiation](matlab/7/README.md) 
* [Differential Equations](matlab/8/README.md) 

## Arduino
* [Basics with Python / Matlab](arduino/basics/README.md)

## Matlab: Basics

{: .topic-optional}
This pages are in a rough state. e.g. equations are broken. Don't know why...

* [Basic Commands and Variables](matlab/3/README.md)
* [Graphics](matlab/4/README.md)
* [Systematic Programming](matlab/5/README.md)
* [Vectorization and Vector Calculus in Matlab](matlab/6/README.md)
* [Data Analysis](matlab/9/README.md)


## Other topics 
* [Open Source Tools](other/open_source_tools/README.md)
* [Machine Learning Resources](other/ml_resources/README.md)
* [Datasets](other/datasets/README.md)


