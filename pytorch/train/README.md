# Train the network 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Training the weights and biases of the network.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## An example setup

### Network

```python
import torch

# Some parameters
input_number_of_channel: int = 1
input_dim_x: int = 24
input_dim_y: int = 24

number_of_output_channels_conv1: int = 32
number_of_output_channels_conv2: int = 64
number_of_output_channels_flatten1: int = 576
number_of_output_channels_full1: int = 10

kernel_size_conv1: tuple[int, int] = (5, 5)
kernel_size_pool1: tuple[int, int] = (2, 2)
kernel_size_conv2: tuple[int, int] = (5, 5)
kernel_size_pool2: tuple[int, int] = (2, 2)

stride_conv1: tuple[int, int] = (1, 1)
stride_pool1: tuple[int, int] = (2, 2)
stride_conv2: tuple[int, int] = (1, 1)
stride_pool2: tuple[int, int] = (2, 2)

padding_conv1: int = 0
padding_pool1: int = 0
padding_conv2: int = 0
padding_pool2: int = 0

network = torch.nn.Sequential(
    torch.nn.Conv2d(
        in_channels=input_number_of_channel,
        out_channels=number_of_output_channels_conv1,
        kernel_size=kernel_size_conv1,
        stride=stride_conv1,
        padding=padding_conv1,
    ),
    torch.nn.ReLU(),
    torch.nn.MaxPool2d(
        kernel_size=kernel_size_pool1, stride=stride_pool1, padding=padding_pool1
    ),
    torch.nn.Conv2d(
        in_channels=number_of_output_channels_conv1,
        out_channels=number_of_output_channels_conv2,
        kernel_size=kernel_size_conv2,
        stride=stride_conv2,
        padding=padding_conv2,
    ),
    torch.nn.ReLU(),
    torch.nn.MaxPool2d(
        kernel_size=kernel_size_pool2, stride=stride_pool2, padding=padding_pool2
    ),
    torch.nn.Flatten(
        start_dim=1,
    ),
    torch.nn.Linear(
        in_features=number_of_output_channels_flatten1,
        out_features=number_of_output_channels_full1,
        bias=True,
    ),
    torch.nn.Softmax(dim=1),
)
```

### Data augmentation

```python
import torchvision

test_processing_chain = torchvision.transforms.Compose(
    transforms=[torchvision.transforms.CenterCrop((24, 24))],
)

train_processing_chain = torchvision.transforms.Compose(
    transforms=[torchvision.transforms.RandomCrop((24, 24))],
)
```

## [What makes it learn?](https://pytorch.org/docs/stable/optim.html)

### [Optimizer Algorithms](https://pytorch.org/docs/stable/optim.html#algorithms)

This is just a small selection of optimizers (i.e. the algorithm that learns the weights based on a loss). Nevertheless, typically [Adam](https://pytorch.org/docs/stable/generated/torch.optim.Adam.html#torch.optim.Adam) or [SGD](https://pytorch.org/docs/stable/generated/torch.optim.SGD.html#torch.optim.SGD) will be the first algorithm you will try.

|||
|---|---|
|[Adagrad](https://pytorch.org/docs/stable/generated/torch.optim.Adagrad.html#torch.optim.Adagrad)|	Implements Adagrad algorithm.|
|[Adam](https://pytorch.org/docs/stable/generated/torch.optim.Adam.html#torch.optim.Adam)|	Implements Adam algorithm.|
|[ASGD](https://pytorch.org/docs/stable/generated/torch.optim.ASGD.html#torch.optim.ASGD)|	Implements Averaged Stochastic Gradient Descent.|
|[RMSprop](https://pytorch.org/docs/stable/generated/torch.optim.RMSprop.html#torch.optim.RMSprop)|	Implements RMSprop algorithm.|
|[Rprop](https://pytorch.org/docs/stable/generated/torch.optim.Rprop.html#torch.optim.Rprop)|	Implements the resilient backpropagation algorithm.|
|[SGD](https://pytorch.org/docs/stable/generated/torch.optim.SGD.html#torch.optim.SGD)https://pytorch.org/docs/stable/generated/torch.optim.SGD.html#torch.optim.SGD|	Implements stochastic gradient descent (optionally with momentum).|


### [Learning rate scheduler](https://pytorch.org/docs/stable/optim.html#how-to-adjust-learning-rate)

"torch.optim.lr_scheduler provides several methods to adjust the learning rate based on the number of epochs."

Why do you want to reduce the learning rate: Well, typically you want to start with a large learning rate for jumping over local minima but later you want to anneal the learning rate because otherwise the optimizer will jump over / oscillate around the minima.  

A non-representative selection is

|||
|---|---|
|[lr_scheduler.StepLR](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.StepLR.html#torch.optim.lr_scheduler.StepLR)|	Decays the learning rate of each parameter group by gamma every step_size epochs.|
|[lr_scheduler.MultiStepLR](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.MultiStepLR.html#torch.optim.lr_scheduler.MultiStepLR)|	Decays the learning rate of each parameter group by gamma once the number of epoch reaches one of the milestones.|
|[lr_scheduler.ConstantLR](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.ConstantLR.html#torch.optim.lr_scheduler.ConstantLR)|	Decays the learning rate of each parameter group by a small constant factor until the number of epoch reaches a pre-defined milestone: total_iters.|
|[lr_scheduler.LinearLR](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.LinearLR.html#torch.optim.lr_scheduler.LinearLR)|	Decays the learning rate of each parameter group by linearly changing small multiplicative factor until the number of epoch reaches a pre-defined milestone: total_iters.|
|[lr_scheduler.ExponentialLR](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.ExponentialLR.html#torch.optim.lr_scheduler.ExponentialLR)	|Decays the learning rate of each parameter group by gamma every epoch.|
|[lr_scheduler.ReduceLROnPlateau](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.ReduceLROnPlateau.html#torch.optim.lr_scheduler.ReduceLROnPlateau)|	Reduce learning rate when a metric has stopped improving.|

However, typically I only use [lr_scheduler.ReduceLROnPlateau](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.ReduceLROnPlateau.html#torch.optim.lr_scheduler.ReduceLROnPlateau).
