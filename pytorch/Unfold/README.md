# Unfold: How to manually calculate the indices for a sliding 2d window
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Sometimes it is important to get the all the indices that correspond to the elements in one window position of a CNN or pooling operation. In a simple case you could do it by hand. But what if you have padding, dilation beside the input size, kernel size and stride? Anyway, who would do it by hand if PyTorch can do it for you? 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## The problem

Assume we have a 28x28 input image and a 5x5 kernel & stride of 1x1 then we want the 576 (=24x24) position with 25 (=5x5) elements each. 

This is how we can calculate this information:


```python
import torch


def calculate_output_size(
    value: list[int],
    kernel_size: list[int],
    stride: list[int],
    dilation: list[int],
    padding: list[int],
) -> torch.Tensor:
    assert len(value) == 2
    assert len(kernel_size) == 2
    assert len(stride) == 2
    assert len(dilation) == 2
    assert len(padding) == 2

    coordinates_0, coordinates_1 = get_coordinates(
        value=value,
        kernel_size=kernel_size,
        stride=stride,
        dilation=dilation,
        padding=padding,
    )

    output_size: torch.Tensor = torch.tensor(
        [
            coordinates_0.shape[1],
            coordinates_1.shape[1],
        ],
        dtype=torch.int64,
    )
    return output_size


def get_coordinates(
    value: list[int],
    kernel_size: list[int],
    stride: list[int],
    dilation: list[int],
    padding: list[int],
) -> tuple[torch.Tensor, torch.Tensor]:
    """Function converts parameter in coordinates
    for the convolution window"""

    coordinates_0: torch.Tensor = (
        torch.nn.functional.unfold(
            torch.arange(0, int(value[0]), dtype=torch.float32)
            .unsqueeze(1)
            .unsqueeze(0)
            .unsqueeze(0),
            kernel_size=(int(kernel_size[0]), 1),
            dilation=int(dilation[0]),
            padding=(int(padding[0]), 0),
            stride=int(stride[0]),
        )
        .squeeze(0)
        .type(torch.int64)
    )

    coordinates_1: torch.Tensor = (
        torch.nn.functional.unfold(
            torch.arange(0, int(value[1]), dtype=torch.float32)
            .unsqueeze(0)
            .unsqueeze(0)
            .unsqueeze(0),
            kernel_size=(1, int(kernel_size[1])),
            dilation=int(dilation[1]),
            padding=(0, int(padding[1])),
            stride=int(stride[1]),
        )
        .squeeze(0)
        .type(torch.int64)
    )

    return coordinates_0, coordinates_1


if __name__ == "__main__":
    a, b = get_coordinates(
        value=[28, 28],
        kernel_size=[5, 5],
        stride=[1, 1],
        dilation=[1, 1],
        padding=[0, 0],
    )
    print(a.T)
    print(a.shape)  # -> torch.Size([5, 24])

    print()

    print(b.T)
    print(b.shape)  # -> torch.Size([5, 24])
```

Output:

```python
tensor([[ 0,  1,  2,  3,  4],
        [ 1,  2,  3,  4,  5],
        [ 2,  3,  4,  5,  6],
        [ 3,  4,  5,  6,  7],
        [ 4,  5,  6,  7,  8],
        [ 5,  6,  7,  8,  9],
        [ 6,  7,  8,  9, 10],
        [ 7,  8,  9, 10, 11],
        [ 8,  9, 10, 11, 12],
        [ 9, 10, 11, 12, 13],
        [10, 11, 12, 13, 14],
        [11, 12, 13, 14, 15],
        [12, 13, 14, 15, 16],
        [13, 14, 15, 16, 17],
        [14, 15, 16, 17, 18],
        [15, 16, 17, 18, 19],
        [16, 17, 18, 19, 20],
        [17, 18, 19, 20, 21],
        [18, 19, 20, 21, 22],
        [19, 20, 21, 22, 23],
        [20, 21, 22, 23, 24],
        [21, 22, 23, 24, 25],
        [22, 23, 24, 25, 26],
        [23, 24, 25, 26, 27]])

tensor([[ 0,  1,  2,  3,  4],
        [ 1,  2,  3,  4,  5],
        [ 2,  3,  4,  5,  6],
        [ 3,  4,  5,  6,  7],
        [ 4,  5,  6,  7,  8],
        [ 5,  6,  7,  8,  9],
        [ 6,  7,  8,  9, 10],
        [ 7,  8,  9, 10, 11],
        [ 8,  9, 10, 11, 12],
        [ 9, 10, 11, 12, 13],
        [10, 11, 12, 13, 14],
        [11, 12, 13, 14, 15],
        [12, 13, 14, 15, 16],
        [13, 14, 15, 16, 17],
        [14, 15, 16, 17, 18],
        [15, 16, 17, 18, 19],
        [16, 17, 18, 19, 20],
        [17, 18, 19, 20, 21],
        [18, 19, 20, 21, 22],
        [19, 20, 21, 22, 23],
        [20, 21, 22, 23, 24],
        [21, 22, 23, 24, 25],
        [22, 23, 24, 25, 26],
        [23, 24, 25, 26, 27]])
```
