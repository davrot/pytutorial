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

### Data interfacing

```python
import torch
import numpy as np

class MyDataset(torch.utils.data.Dataset):

    # Initialize
    def __init__(self, train: bool = False) -> None:
        super(MyDataset, self).__init__()

        if train is True:
            self.pattern_storage: np.ndarray = np.load("train_pattern_storage.npy")
            self.label_storage: np.ndarray = np.load("train_label_storage.npy")
        else:
            self.pattern_storage = np.load("test_pattern_storage.npy")
            self.label_storage = np.load("test_label_storage.npy")

        self.pattern_storage = self.pattern_storage.astype(np.float32)
        self.pattern_storage /= np.max(self.pattern_storage)

        # How many pattern are there?
        self.number_of_pattern: int = self.label_storage.shape[0]

    def __len__(self) -> int:
        return self.number_of_pattern

    # Get one pattern at position index
    def __getitem__(self, index: int) -> tuple[torch.Tensor, int]:

        image = torch.tensor(self.pattern_storage[index, np.newaxis, :, :])
        target = int(self.label_storage[index])

        return image, target
```

### Data loader

```python
dataset_train = MyDataset(train=True)
dataset_test = MyDataset(train=False)
batch_size_train = 100
batch_size_test = 100

train_data_load = torch.utils.data.DataLoader(
    dataset_train, batch_size=batch_size_train, shuffle=True
)

test_data_load = torch.utils.data.DataLoader(
    dataset_test, batch_size=batch_size_test, shuffle=False
)
```

and you need the data from [here](https://davrot.github.io/pytutorial/pytorch/MNIST/)


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
|[SGD](https://pytorch.org/docs/stable/generated/torch.optim.SGD.html#torch.optim.SGD)|	Implements stochastic gradient descent (optionally with momentum).|


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

## [Tensorboard](https://pytorch.org/docs/stable/tensorboard.html)

We want to monitor our progress and will use Tensorboard for this.

In the beginning we need to open a Tensorboard session

```python
import os
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

from torch.utils.tensorboard import SummaryWriter
tb = SummaryWriter()
```

Afterwards we need to close the Tensorboard session again

```python
tb.close()
```

During learning we can flush the information. This allows us to observer the development in parallel in the viewer (a viewer that is build into **VS code** I might add...). 

```python
tb.flush()
```

We can [add histograms](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_histogram) for e.g. weights 

```python
tb.add_histogram("LABEL OF THE VARIABLE", VARIABLE, LEARNING_STEP_NUMBER)
```

or [add scalars](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_scalar) (e.g. performances or loss values)

```python
tb.add_scalar("LABEL OF THE VARIABLE", VARIABLE, LEARNING_STEP_NUMBER)
```

We can also add [images](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_image), [matplotlib figures](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_figure), [videos](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_video), [audio](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_audio), [text](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_text), [graph data](https://pytorch.org/docs/stable/tensorboard.html#torch.utils.tensorboard.writer.SummaryWriter.add_graph), and other stuff. Just because we can doesn't mean that we want to...


We can use the [event_accumulator](https://github.com/tensorflow/tensorboard/blob/master/tensorboard/backend/event_processing/event_accumulator.py) to retrieve the stored information.

* acc = event_accumulator.EventAccumulator(PATH)
* acc.Tags() : Return all tags found as a dictionary (e.g. acc.Tags()['scalars'] and acc.Tags()['histograms']).
* acc.Scalars(tag) : Given a summary tag, return all associated `ScalarEvent`s.
* acc.Graph() : Return the graph definition, if there is one.
* acc.MetaGraph() : Return the metagraph definition, if there is one.
* acc.Histograms(tag) : Given a summary tag, return all associated histograms.
* acc.CompressedHistograms(tag) : Given a summary tag, return all associated compressed histograms.
* acc.Images(tag) : Given a summary tag, return all associated images.
* acc.Audio(tag) : Given a summary tag, return all associated audio.
* acc.Tensors(tag) : Given a summary tag, return all associated tensors.

Here as an example:  

```python
import os

os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"
import matplotlib.pyplot as plt

from tensorboard.backend.event_processing import event_accumulator
import numpy as np

path: str = "./runs/Jan26_18-03-23_doppio/"  # this way tensorboard directory

acc = event_accumulator.EventAccumulator(path)
acc.Reload()

available_scalar = acc.Tags()["scalars"]
available_histograms = acc.Tags()["histograms"]
print("Available Scalars")
print(available_scalar)

print("Available Histograms")
print(available_histograms)

which_scalar = "Train Performance"
te = acc.Scalars(which_scalar)
# %%
temp = []
for te_item in te:
    temp.append((te_item[1], te_item[2]))
temp = np.array(temp)

plt.plot(temp[:, 0], temp[:, 1])
plt.xlabel("Steps")
plt.ylabel("Train Performance")
plt.title(which_scalar)
plt.show()
```

## MNIST with Adam, ReduceLROnPlateau, cross-entropy on CPU

Operations you will see that are not explained yet: 

|||
|---|---|
|[network.train()](https://pytorch.org/docs/stable/generated/torch.nn.Module.html#torch.nn.Module.train)| : "Sets the module in training mode."|
|[optimizer.zero_grad()](https://pytorch.org/docs/stable/generated/torch.optim.Optimizer.zero_grad.html)| : "Sets the gradients of all optimized [torch.Tensor](https://pytorch.org/docs/stable/tensors.html#torch.Tensor)s to zero." For every mini batch we (need to) clean the gradient which is used for training the parameters. |
|[optimizer.step()](https://pytorch.org/docs/stable/generated/torch.optim.Optimizer.step.html#torch.optim.Optimizer.step)| : "Performs a single optimization step (parameter update)."|
|[loss.backward()](https://pytorch.org/docs/stable/generated/torch.Tensor.backward.html)| : "Computes the gradient of current tensor w.r.t. graph leaves."|
|[lr_scheduler.step(train_loss)](https://pytorch.org/docs/stable/generated/torch.optim.lr_scheduler.ReduceLROnPlateau.html#torch.optim.lr_scheduler.ReduceLROnPlateau)| : After an epoch the learning rate (might be) changed. For other [Learning rate scheduler](https://pytorch.org/docs/stable/optim.html#how-to-adjust-learning-rate) .step() might have no parameter.|
|[network.eval()](https://pytorch.org/docs/stable/generated/torch.nn.Module.html#torch.nn.Module.eval)| : "Sets the module in evaluation mode."|
|[with torch.no_grad():](https://pytorch.org/docs/stable/generated/torch.no_grad.html)| : "Context-manager that disabled gradient calculation."|
 

```python
import os

os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

import torch
import torchvision  # type:ignore
import numpy as np
import time
from torch.utils.tensorboard import SummaryWriter


class MyDataset(torch.utils.data.Dataset):
    # Initialize
    def __init__(self, train: bool = False) -> None:
        super(MyDataset, self).__init__()

        if train is True:
            self.pattern_storage: np.ndarray = np.load("train_pattern_storage.npy")
            self.label_storage: np.ndarray = np.load("train_label_storage.npy")
        else:
            self.pattern_storage = np.load("test_pattern_storage.npy")
            self.label_storage = np.load("test_label_storage.npy")

        self.pattern_storage = self.pattern_storage.astype(np.float32)
        self.pattern_storage /= np.max(self.pattern_storage)

        # How many pattern are there?
        self.number_of_pattern: int = self.label_storage.shape[0]

    def __len__(self) -> int:
        return self.number_of_pattern

    # Get one pattern at position index
    def __getitem__(self, index: int) -> tuple[torch.Tensor, int]:
        image = torch.tensor(self.pattern_storage[index, np.newaxis, :, :])
        target = int(self.label_storage[index])

        return image, target


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

test_processing_chain = torchvision.transforms.Compose(
    transforms=[torchvision.transforms.CenterCrop((24, 24))],
)

train_processing_chain = torchvision.transforms.Compose(
    transforms=[torchvision.transforms.RandomCrop((24, 24))],
)

dataset_train = MyDataset(train=True)
dataset_test = MyDataset(train=False)
batch_size_train = 100
batch_size_test = 100

train_data_load = torch.utils.data.DataLoader(
    dataset_train, batch_size=batch_size_train, shuffle=True
)

test_data_load = torch.utils.data.DataLoader(
    dataset_test, batch_size=batch_size_test, shuffle=False
)

# -------------------------------------------

# The optimizer
optimizer = torch.optim.Adam(network.parameters(), lr=0.001)

# The LR Scheduler
lr_scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(optimizer)

number_of_test_pattern: int = dataset_test.__len__()
number_of_train_pattern: int = dataset_train.__len__()

number_of_epoch: int = 50

tb = SummaryWriter(log_dir="run")

loss_function = torch.nn.CrossEntropyLoss()

for epoch_id in range(0, number_of_epoch):
    print(f"Epoch: {epoch_id}")
    t_start: float = time.perf_counter()

    train_loss: float = 0.0
    train_correct: int = 0
    train_number: int = 0
    test_correct: int = 0
    test_number: int = 0

    # Switch the network into training mode
    network.train()

    # This runs in total for one epoch split up into mini-batches
    for image, target in train_data_load:
        # Clean the gradient
        optimizer.zero_grad()

        output = network(train_processing_chain(image))

        loss = loss_function(output, target)

        train_loss += loss.item()
        train_correct += (output.argmax(dim=1) == target).sum().numpy()
        train_number += target.shape[0]
        # Calculate backprop
        loss.backward()

        # Update the parameter
        optimizer.step()

    # Update the learning rate
    lr_scheduler.step(train_loss)

    t_training: float = time.perf_counter()

    # Switch the network into evalution mode
    network.eval()
    with torch.no_grad():
        for image, target in test_data_load:
            output = network(test_processing_chain(image))

            test_correct += (output.argmax(dim=1) == target).sum().numpy()
            test_number += target.shape[0]

    t_testing = time.perf_counter()

    perfomance_test_correct: float = 100.0 * test_correct / test_number
    perfomance_train_correct: float = 100.0 * train_correct / train_number

    tb.add_scalar("Train Loss", train_loss, epoch_id)
    tb.add_scalar("Train Number Correct", train_correct, epoch_id)
    tb.add_scalar("Test Number Correct", test_correct, epoch_id)

    print(f"Training: Loss={train_loss:.5f} Correct={perfomance_train_correct:.2f}%")
    print(f"Testing: Correct={perfomance_test_correct:.2f}%")
    print(
        f"Time: Training={(t_training-t_start):.1f}sec, Testing={(t_testing-t_training):.1f}sec"
    )
    torch.save(network, "Model_MNIST_A_" + str(epoch_id) + ".pt")
    print()

    tb.flush()

tb.close()
```

## Mean square error

You might be inclined to use the MSE instead of the cross entropy.

But be aware that you need to change more than just the loss function from

```python
loss_function = torch.nn.CrossEntropyLoss()
```
to 

```python
loss_function = torch.nn.MSELoss()
```

Why? Because the input changes from the correct class represented by an integer into a one hot encoded vector. 

A fast way to do so is this function which uses in-place scatter 

```python
def class_to_one_hot(
    correct_label: torch.Tensor, number_of_neurons: int
) -> torch.Tensor:

    target_one_hot: torch.Tensor = torch.zeros(
        (correct_label.shape[0], number_of_neurons)
    )
    target_one_hot.scatter_(
        1, correct_label.unsqueeze(1), torch.ones((correct_label.shape[0], 1))
    )

    return target_one_hot
```

 Obviously, we also need to modify this line

```python
        loss = loss_function(output, target)
```

 to

```python
        loss = loss_function(
            output, class_to_one_hot(target, number_of_output_channels_full1)
        )
```
