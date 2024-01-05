# Your own layer
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## Writing a layer based on linear

I am rewriting the code for [Linear](https://pytorch.org/docs/stable/_modules/torch/nn/modules/linear.html#Linear) as my own layer. 

\_\_init\_\_() : It contains a tensor for the weights and optionally a second tensor for the bias. Both tensors are wrapped within the torch.nn.Parameter class. This is necessary, otherwise the optimizer will not find them. Afterwards the tensors will be initialized via reset_parameters(self).

reset_parameters(): I copied it from the original code. 

forward(): We get an input tensor and need to produce an output tensor. Please remember that dimension 0 contains the batch. Here we just multiply the input with the weights and add the bias to it (if available).

extra_repr(): Plots the information about the layer in a nice fashion. 


```python
import torch
import math


class MyOwnLayer(torch.nn.Module):
    def __init__(
        self,
        in_features: int,
        out_features: int,
        bias: bool = True,
    ) -> None:
        super().__init__()

        assert in_features > 0
        assert out_features > 0

        self.in_features: int = in_features
        self.out_features: int = out_features

        self.weight = torch.nn.Parameter(
            torch.empty(
                (out_features, in_features),
            )
        )
        if bias:
            self.bias = torch.nn.Parameter(
                torch.empty(
                    out_features,
                )
            )
        else:
            self.register_parameter("bias", None)
        self.reset_parameters()

    def reset_parameters(self) -> None:
        torch.nn.init.kaiming_uniform_(self.weight, a=math.sqrt(5))
        if self.bias is not None:
            fan_in, _ = torch.nn.init._calculate_fan_in_and_fan_out(self.weight)
            bound = 1 / math.sqrt(fan_in) if fan_in > 0 else 0
            torch.nn.init.uniform_(self.bias, -bound, bound)

    def forward(
        self,
        input: torch.Tensor,
    ) -> torch.Tensor:
        output = (self.weight.unsqueeze(0) * input.unsqueeze(1)).sum(dim=-1)

        if self.bias is not None:
            output = output + self.bias.unsqueeze(0)

        return output

    def extra_repr(self) -> str:
        return f"in_features={self.in_features}, out_features={self.out_features}, bias={self.bias is not None}"
```

![image0](Figure_1,png)
