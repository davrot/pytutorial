# Creating networks 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

In these days, building networks is very important. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## A fast way to build a network with [Sequential](https://pytorch.org/docs/stable/generated/torch.nn.Sequential.html#torch.nn.Sequential) 

```python
CLASS torch.nn.Sequential(*args: Module)
```

> A sequential container. Modules will be added to it in the order they are passed in the constructor.


Example: 

![image0](network_0.png)

We can just chain the layers together:

```python
import torch

input_number_of_channel: int = 1
input_dim_x: int = 24
input_dim_y: int = 24

number_of_output_channels_conv1: int = 32
number_of_output_channels_conv2: int = 64
number_of_output_channels_flatten1: int
number_of_output_channels_full1: int = 1024
number_of_output_channels_out: int = 10

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

number_of_output_channels_flatten1 = 576

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
    torch.nn.ReLU(),
    torch.nn.Linear(
        in_features=number_of_output_channels_full1,
        out_features=number_of_output_channels_out,
        bias=True,
    ),
)

print(network)
```

```python
Sequential(
  (0): Conv2d(1, 32, kernel_size=(5, 5), stride=(1, 1))
  (1): ReLU()
  (2): MaxPool2d(kernel_size=(2, 2), stride=(2, 2), padding=0, dilation=1, ceil_mode=False)
  (3): Conv2d(32, 64, kernel_size=(5, 5), stride=(1, 1))
  (4): ReLU()
  (5): MaxPool2d(kernel_size=(2, 2), stride=(2, 2), padding=0, dilation=1, ceil_mode=False)
  (6): Flatten(start_dim=1, end_dim=-1)
  (7): Linear(in_features=576, out_features=1024, bias=True)
  (8): ReLU()
  (9): Linear(in_features=1024, out_features=10, bias=True)
)
```

Congratulations you now have the network you wanted.

## Inspecting the network object

```python
print(network.__dict__)
```

The output is:

```python
{'training': True, 
'_parameters': OrderedDict(), 
'_buffers': OrderedDict(), 
'_non_persistent_buffers_set': set(), 
'_backward_pre_hooks': OrderedDict()
'_backward_hooks': OrderedDict(),
'_is_full_backward_hook': None, 
'_forward_hooks': OrderedDict(), 
'_forward_hooks_with_kwargs': OrderedDict(), 
'_forward_pre_hooks': OrderedDict(), 
'_forward_pre_hooks_with_kwargs': OrderedDict(),
'_state_dict_hooks': OrderedDict(), 
'_state_dict_pre_hooks': OrderedDict(), 
'_load_state_dict_pre_hooks': OrderedDict(), 
'_load_state_dict_post_hooks': OrderedDict(), 
'_modules': OrderedDict([('0', Conv2d(1, 32, kernel_size=(5, 5), stride=(1, 1))), ('1', ReLU()), ('2', MaxPool2d(kernel_size=(2, 2), stride=(2, 2), padding=0, dilation=1, ceil_mode=False)), ('3', Conv2d(32, 64, kernel_size=(5, 5), stride=(1, 1))), ('4', ReLU()), ('5', MaxPool2d(kernel_size=(2, 2), stride=(2, 2), padding=0, dilation=1, ceil_mode=False)), ('6', Flatten(start_dim=1, end_dim=-1)), ('7', Linear(in_features=576, out_features=1024, bias=True)), ('8', ReLU()), ('9', Linear(in_features=1024, out_features=10, bias=True))])}
```

The obvious question is: What does this tell us? We see that the network is set to training mode but more importantly we can see our network architecture:

```python
print(network.__dict__["_modules"])
```python

```python
OrderedDict([
    ('0', Conv2d(1, 32, kernel_size=(5, 5), stride=(1, 1))), 
    ('1', ReLU()), 
    ('2', MaxPool2d(kernel_size=(2, 2), stride=(2, 2), padding=0, dilation=1, ceil_mode=False)), 
    ('3', Conv2d(32, 64, kernel_size=(5, 5), stride=(1, 1))), 
    ('4', ReLU()), 
    ('5', MaxPool2d(kernel_size=(2, 2), stride=(2, 2), padding=0, dilation=1, ceil_mode=False)), 
    ('6', Flatten(start_dim=1, end_dim=-1)), 
    ('7', Linear(in_features=576, out_features=1024, bias=True)), 
    ('8', ReLU()), 
    ('9', Linear(in_features=1024, out_features=10, bias=True))])
```

## Using the network

First we need some input data

```python
input_number_of_channel: int = 1
input_dim_x: int = 24
input_dim_y: int = 24

number_of_pattern: int = 111
fake_input = torch.rand(
    (number_of_pattern, input_number_of_channel, input_dim_x, input_dim_y),
    dtype=torch.float32,
)
```

Output:

```python
output = network(fake_input)
print(fake_input.shape)  # -> torch.Size([111, 1, 24, 24])
print(output.shape)  # -> torch.Size([111, 10])
```

## Flatten -> Linear Problem

If you want to use a linear layer after the flatten layer, you need to know the output dimensions of the flatten layer. If you know, everything is good. If not what to do then? There are two main alternatives:

### [LazyLinear Layer](https://pytorch.org/docs/stable/generated/torch.nn.LazyLinear.html)

```python
CLASS torch.nn.LazyLinear(out_features, bias=True, device=None, dtype=None)
```

> A torch.nn.Linear module where in_features is inferred.
> 
> In this module, the weight and bias are of torch.nn.UninitializedParameter class. They will be initialized after the first call to forward is done and the module will become a regular torch.nn.Linear module. The in_features argument of the Linear is inferred from the input.shape[-1].
> 
> Check the torch.nn.modules.lazy.LazyModuleMixin for [further documentation](https://pytorch.org/docs/stable/generated/torch.nn.modules.lazy.LazyModuleMixin.html#torch.nn.modules.lazy.LazyModuleMixin) on lazy modules and their limitations.

**If you want to manipulate the weights and such of this layer before using it then this can get ugly.** If possible you should try to use alternative 2:

### Building your network iteratively

Let us build the network layer by layer and assume we don't know **number_of_output_channels_flatten1 = 576**. But we know that the input has 1 input channel and 24x24 pixel in the spatial domain. 

```python
import torch

input_number_of_channel: int = 1
input_dim_x: int = 24
input_dim_y: int = 24

number_of_output_channels_conv1: int = 32
number_of_output_channels_conv2: int = 64
number_of_output_channels_flatten1: int
number_of_output_channels_full1: int = 1024
number_of_output_channels_out: int = 10

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


fake_input = torch.zeros((1, input_number_of_channel, input_dim_x, input_dim_y))
print(fake_input.shape)  # -> torch.Size([1, 1, 24, 24])

network = torch.nn.Sequential()

network.append(
    torch.nn.Conv2d(
        in_channels=input_number_of_channel,
        out_channels=number_of_output_channels_conv1,
        kernel_size=kernel_size_conv1,
        stride=stride_conv1,
        padding=padding_conv1,
    )
)
fake_input = network[-1](fake_input)
print(fake_input.shape)  # -> torch.Size([1, 32, 20, 20])

network.append(torch.nn.ReLU())
fake_input = network[-1](fake_input)
print(fake_input.shape)  # -> torch.Size([1, 32, 20, 20])

network.append(
    torch.nn.MaxPool2d(
        kernel_size=kernel_size_pool1, stride=stride_pool1, padding=padding_pool1
    )
)
fake_input = network[-1](fake_input)
print(fake_input.shape)  # -> torch.Size([1, 32, 10, 10])


network.append(
    torch.nn.Conv2d(
        in_channels=number_of_output_channels_conv1,
        out_channels=number_of_output_channels_conv2,
        kernel_size=kernel_size_conv2,
        stride=stride_conv2,
        padding=padding_conv2,
    )
)
fake_input = network[-1](fake_input)
print(fake_input.shape)  # -> torch.Size([1, 64, 6, 6])


network.append(torch.nn.ReLU())
fake_input = network[-1](fake_input)
print(fake_input.shape)  # -> torch.Size([1, 64, 6, 6])


network.append(
    torch.nn.MaxPool2d(
        kernel_size=kernel_size_pool2, stride=stride_pool2, padding=padding_pool2
    )
)
fake_input = network[-1](fake_input)
print(fake_input.shape)  # -> torch.Size([1, 64, 3, 3])


network.append(
    torch.nn.Flatten(
        start_dim=1,
    )
)
fake_input = network[-1](fake_input)
print(fake_input.shape)  # torch.Size([1, 576])

number_of_output_channels_flatten1 = fake_input.shape[1]

network.append(
    torch.nn.Linear(
        in_features=number_of_output_channels_flatten1,
        out_features=number_of_output_channels_full1,
        bias=True,
    )
)
fake_input = network[-1](fake_input)
print(fake_input.shape)  # torch.Size([1, 1024])


network.append(torch.nn.ReLU())
fake_input = network[-1](fake_input)
print(fake_input.shape)  # torch.Size([1, 1024])

network.append(
    torch.nn.Linear(
        in_features=number_of_output_channels_full1,
        out_features=number_of_output_channels_out,
        bias=True,
    )
)
fake_input = network[-1](fake_input)
print(fake_input.shape)  # torch.Size([1, 10])


print(network)
```

