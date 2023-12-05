# PyTorch: Layers
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Goal

Layers, layers, everywhere. If you understand PyTorch layers then you understand most of PyTorch. Well, and torch.tensor...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Open Book & Website recommendation
If you don't know what these layers mean then don't be ashamed and check out these resources: 

Dive into Deep Learning
[https://d2l.ai/](https://d2l.ai/)

as well as corresponding Youtube channel from [Alex Smola](https://www.youtube.com/playlist?list=PLZSO_6-bSqHQHBCoGaObUljoXAyyqhpFW)



## torch.tensor

Before we can use layers we need to understand [torch.tensor](https://pytorch.org/docs/stable/tensors.html) a bit more. You can understand them as a np.ndarray with additional properties and options. Most of it is like with numpy arrays. However, the tensor can shelter an additional gradient!

There are official tutorials about tensors:

* [Tensors](https://pytorch.org/docs/stable/tensors.html)
* [Introduction to Torch’s tensor library](https://pytorch.org/tutorials/beginner/nlp/pytorch_tutorial.html)
However, I feel that they are a bit useless.

Let's be very blunt here: If you don't understand the basics of [Numpy ndarray](https://numpy.org/doc/stable/reference/arrays.ndarray.html) then you will be lost. If you know the usual stuff about np.ndarrays then you understand most of torch.tensor too. You only need some extra information, which I will try to provide here. 

The [torch.tensor data types](https://pytorch.org/docs/stable/tensors.html#data-types) (for the CPU) are very similar to the Numpy. e.g. np.float32 -> torch.float32

### There and back again (np.ndarray <-> torch.tensor)

Let us convert x_np: np.ndarray into a torch.Tensor:

```python
x_torch: torch.Tensor = torch.tensor(x_np)
```

And we convert it back into a torch.Tensor:

```python
x_np: np.ndarray = x_torch.detach().numpy()
```

or if x_torch is on the GPU:

```python
x_np : np.ndarray= x_torch.cpu().detach().numpy()
```

* [Tensor.detach()](https://pytorch.org/docs/stable/generated/torch.Tensor.detach.html?highlight=detach#torch.Tensor.detach) : Get rid of the gradient.
* [Tensor.numpy()](https://pytorch.org/docs/stable/generated/torch.Tensor.numpy.html#torch.Tensor.numpy) : "Returns self tensor as a NumPy ndarray. This tensor and the returned ndarray share the same underlying storage. Changes to self tensor will be reflected in the ndarray and vice versa."
* [torch.tensor()](https://pytorch.org/docs/stable/generated/torch.tensor.html#torch.tensor) : Put stuff in there and get a torch.tensor out of it.
* [Tensor.type()](https://pytorch.org/docs/stable/generated/torch.Tensor.type.html#torch.Tensor.type) : numpy's .astype()


### GPU interactions

[torch.tensor.to](https://pytorch.org/docs/stable/generated/torch.Tensor.to.html?highlight=#torch-tensor-to)  : tensors and layers can life on different devices e.g. CPU and GPU. You need to move them where you need then. Typically only objects on the same device can interact. 

```python
device_gpu = torch.device("cuda:0")
device_cpu = torch.device("cpu")

something_on_gpu =  something_on_cpu.to(device_gpu)
something_on_cpu =  something_on_gpu.to(device_cpu)
something_on_cpu =  something_on_gpu.cpu()
```

* [torch.cuda.is_available()](https://pytorch.org/docs/stable/generated/torch.cuda.is_available.html#torch.cuda.is_available) : Is there a cuda gpu in my system?
* [torch.cuda.get_device_capability()](https://pytorch.org/docs/stable/generated/torch.cuda.get_device_capability.html#torch.cuda.get_device_capability) : If you need to know what your gpu is capable of. You get a number and need to check [here](https://en.wikipedia.org/wiki/CUDA#Version_features_and_specifications) what this number means.  
* [torch.cuda.get_device_name()](https://pytorch.org/docs/stable/generated/torch.cuda.get_device_name.html#torch.cuda.get_device_name) : In the case you forgot what GPU you bought or if you have sooo many GPUs in your system and don't know which is what.
* [torch.cuda.get_device_properties()](https://pytorch.org/docs/stable/generated/torch.cuda.get_device_properties.html#torch.cuda.get_device_properties) : The two above plus how much memory the card has.
* [torch.Tensor.device](https://pytorch.org/docs/stable/generated/torch.Tensor.device.html#torch.Tensor.device) : Where does this tensor life?

### Dimensions 

* [torch.squeeze()](https://pytorch.org/docs/stable/generated/torch.squeeze.html#torch.squeeze) : get rid of (a selected) dimension with size 1
* [torch.unsqueeze()](https://pytorch.org/docs/stable/generated/torch.unsqueeze.html#torch.unsqueeze) : add a dimension of size 1 at a defined position


## Layers (i.e. [basic building blocks](https://pytorch.org/docs/stable/nn.html))

Obviously there are **a lot** of available layer. I want to list only the relevant ones for the typical daily use.

Please note the first upper case letter. If the thing you want to use doesn't have a first upper case letter then something is wrong and it is not a layer.

I will skip the following layer types (because you will not care about them):

* [Sparse Layers](https://pytorch.org/docs/stable/nn.html#sparse-layers)
* [Vision Layers](https://pytorch.org/docs/stable/nn.html#vision-layers)
* [Shuffle Layers](https://pytorch.org/docs/stable/nn.html#vision-layers)
* [DataParallel Layers (multi-GPU, distributed)](https://pytorch.org/docs/stable/nn.html#dataparallel-layers-multi-gpu-distributed)
* [Distance Functions](https://pytorch.org/docs/stable/nn.html#distance-functions)

In the following I will mark the relevant layers.

### [Convolution Layers](https://pytorch.org/docs/stable/nn.html#convolution-layers)

|||
|---|---|
|**[torch.nn.Conv1d](https://pytorch.org/docs/stable/generated/torch.nn.Conv1d.html#torch.nn.Conv1d)** |Applies a 1D convolution over an input signal composed of several input planes.|
|**[torch.nn.Conv2d](https://pytorch.org/docs/stable/generated/torch.nn.Conv2d.html#torch.nn.Conv2d)**|Applies a 2D convolution over an input signal composed of several input planes.|
|**[torch.nn.Conv3d](https://pytorch.org/docs/stable/generated/torch.nn.Conv3d.html#torch.nn.Conv3d)**|Applies a 3D convolution over an input signal composed of several input planes.|
|torch.nn.ConvTranspose1d|Applies a 1D transposed convolution operator over an input image composed of several input planes.|
|torch.nn.ConvTranspose2d|Applies a 2D transposed convolution operator over an input image composed of several input planes.|
|torch.nn.ConvTranspose3d|Applies a 3D transposed convolution operator over an input image composed of several input planes.|
|torch.nn.LazyConv1d|A torch.nn.Conv1d module with lazy initialization of the in_channels argument of the Conv1d that is inferred from the input.size(1).|
|torch.nn.LazyConv2d|A torch.nn.Conv2d module with lazy initialization of the in_channels argument of the Conv2d that is inferred from the input.size(1).|
|torch.nn.LazyConv3d|A torch.nn.Conv3d module with lazy initialization of the in_channels argument of the Conv3d that is inferred from the input.size(1).|
|torch.nn.LazyConvTranspose1d|A torch.nn.ConvTranspose1d module with lazy initialization of the in_channels argument of the ConvTranspose1d that is inferred from the input.size(1).|
|torch.nn.LazyConvTranspose2d|A torch.nn.ConvTranspose2d module with lazy initialization of the in_channels argument of the ConvTranspose2d that is inferred from the input.size(1).|
|torch.nn.LazyConvTranspose3d|A torch.nn.ConvTranspose3d module with lazy initialization of the in_channels argument of the ConvTranspose3d that is inferred from the input.size(1).|
|torch.nn.Unfold|Extracts sliding local blocks from a batched input tensor.|
|torch.nn.Fold|Combines an array of sliding local blocks into a large containing tensor.|


### [Pooling layers](https://pytorch.org/docs/stable/nn.html#pooling-layers)

|||
|---|---|
|**[torch.nn.MaxPool1d](https://pytorch.org/docs/stable/generated/torch.nn.MaxPool1d.html#torch.nn.MaxPool1d)**|Applies a 1D max pooling over an input signal composed of several input planes.|
|**[torch.nn.MaxPool2d](https://pytorch.org/docs/stable/generated/torch.nn.MaxPool2d.html#torch.nn.MaxPool2d)**|Applies a 2D max pooling over an input signal composed of several input planes.|
|**[torch.nn.MaxPool3d](https://pytorch.org/docs/stable/generated/torch.nn.MaxPool3d.html#torch.nn.MaxPool3d)**|Applies a 3D max pooling over an input signal composed of several input planes.|
|torch.nn.MaxUnpool1d|Computes a partial inverse of MaxPool1d.|
|torch.nn.MaxUnpool2d|Computes a partial inverse of MaxPool2d.|
|torch.nn.MaxUnpool3d|Computes a partial inverse of MaxPool3d.|
|**[torch.nn.AvgPool1d](https://pytorch.org/docs/stable/generated/torch.nn.AvgPool1d.html#torch.nn.AvgPool1d)**|Applies a 1D average pooling over an input signal composed of several input planes.|
|**[torch.nn.AvgPool2d](https://pytorch.org/docs/stable/generated/torch.nn.AvgPool2d.html#torch.nn.AvgPool2d)**|Applies a 2D average pooling over an input signal composed of several input planes.|
|**[torch.nn.AvgPool3d](https://pytorch.org/docs/stable/generated/torch.nn.AvgPool3d.html#torch.nn.AvgPool3d)**|Applies a 3D average pooling over an input signal composed of several input planes.|
|torch.nn.FractionalMaxPool2d|Applies a 2D fractional max pooling over an input signal composed of several input planes.|
|torch.nn.FractionalMaxPool3d|Applies a 3D fractional max pooling over an input signal composed of several input planes.|
|torch.nn.LPPool1d|Applies a 1D power-average pooling over an input signal composed of several input planes.|
|torch.nn.LPPool2d|Applies a 2D power-average pooling over an input signal composed of several input planes.|
|torch.nn.AdaptiveMaxPool1d|Applies a 1D adaptive max pooling over an input signal composed of several input planes.|
|torch.nn.AdaptiveMaxPool2d|Applies a 2D adaptive max pooling over an input signal composed of several input planes.|
|torch.nn.AdaptiveMaxPool3d|Applies a 3D adaptive max pooling over an input signal composed of several input planes.|
|torch.nn.AdaptiveAvgPool1d|Applies a 1D adaptive average pooling over an input signal composed of several input planes.|
|torch.nn.AdaptiveAvgPool2d|Applies a 2D adaptive average pooling over an input signal composed of several input planes.|
|torch.nn.AdaptiveAvgPool3d|Applies a 3D adaptive average pooling over an input signal composed of several input planes.|

## [Padding Layers](https://pytorch.org/docs/stable/nn.html#padding-layers)

|||
|---|---|
|torch.nn.ReflectionPad1d|Pads the input tensor using the reflection of the input boundary.|
|torch.nn.ReflectionPad2d|Pads the input tensor using the reflection of the input boundary.|
|torch.nn.ReflectionPad3d|Pads the input tensor using the reflection of the input boundary.|
|torch.nn.ReplicationPad1d|Pads the input tensor using replication of the input boundary.|
|torch.nn.ReplicationPad2d|Pads the input tensor using replication of the input boundary.|
|torch.nn.ReplicationPad3d|Pads the input tensor using replication of the input boundary.|
|torch.nn.ZeroPad1d|Pads the input tensor boundaries with zero.|
|torch.nn.ZeroPad2d|Pads the input tensor boundaries with zero.|
|torch.nn.ZeroPad3d|Pads the input tensor boundaries with zero.|
|torch.nn.ConstantPad1d|Pads the input tensor boundaries with a constant value.|
|torch.nn.ConstantPad2d|Pads the input tensor boundaries with a constant value.|
|torch.nn.ConstantPad3d|Pads the input tensor boundaries with a constant value.|


## [Non-linear Activations (weighted sum, nonlinearity)](https://pytorch.org/docs/stable/nn.html#non-linear-activations-weighted-sum-nonlinearity)

|||
|---|---|
|torch.nn.nn.ELU|Applies the Exponential Linear Unit (ELU) function, element-wise, as described in the paper: Fast and Accurate Deep Network Learning by Exponential Linear Units (ELUs).|
|torch.nn.nn.Hardshrink|Applies the Hard Shrinkage (Hardshrink) function element-wise.|
|torch.nn.nn.Hardsigmoid|Applies the Hardsigmoid function element-wise.|
|torch.nn.nn.Hardtanh|Applies the HardTanh function element-wise.|
|torch.nn.nn.Hardswish|Applies the Hardswish function, element-wise, as described in the paper: Searching for MobileNetV3.|
|**[torch.nn.nn.LeakyReLU](https://pytorch.org/docs/stable/generated/torch.nn.LeakyReLU.html#torch.nn.LeakyReLU)**|Applies the element-wise function:|
|torch.nn.nn.LogSigmoid|Applies the element-wise function:|
|torch.nn.nn.MultiheadAttention |Allows the model to jointly attend to information from different representation subspaces as described in the paper: Attention Is All You Need.|
|torch.nn.nn.PReLU|Applies the element-wise function:|
|**[torch.nn.nn.ReLU](https://pytorch.org/docs/stable/generated/torch.nn.ReLU.html#torch.nn.ReLU)**|Applies the rectified linear unit function element-wise:|
|torch.nn.nn.ReLU6|Applies the element-wise function:|
|torch.nn.nn.RReLU|Applies the randomized leaky rectified liner unit function, element-wise, as described in the paper:|
|torch.nn.nn.SELU|Applied element-wise...|
|torch.nn.nn.CELU|Applies the element-wise function...|
|torch.nn.nn.GELU|Applies the Gaussian Error Linear Units function:|
|**[torch.nn.nn.Sigmoid](https://pytorch.org/docs/stable/generated/torch.nn.Sigmoid.html#torch.nn.Sigmoid)**|Applies the element-wise function:...|
|torch.nn.nn.SiLU|Applies the Sigmoid Linear Unit (SiLU) function, element-wise.|
|torch.nn.nn.Mish|Applies the Mish function, element-wise.|
|torch.nn.nn.Softplus|Applies the Softplus function |
|torch.nn.nn.Softshrink|Applies the soft shrinkage function elementwise:|
|torch.nn.nn.Softsign|Applies the element-wise function:...|
|**[torch.nn.nn.Tanh](https://pytorch.org/docs/stable/generated/torch.nn.Tanh.html#torch.nn.Tanh)**|Applies the Hyperbolic Tangent (Tanh) function element-wise.|
|torch.nn.nn.Tanhshrink |Applies the element-wise function:|
|torch.nn.nn.Threshold |Thresholds each element of the input Tensor.|
|torch.nn.nn.GLU |Applies the gated linear unit function |




### Transformer Layers
