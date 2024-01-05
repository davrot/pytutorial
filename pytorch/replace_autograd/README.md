# Replace autograd
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [TORCH.AUTOGRAD.FUNCTION.FUNCTIONCTX.SAVE_FOR_BACKWARD](https://pytorch.org/docs/stable/generated/torch.autograd.function.FunctionCtx.save_for_backward.html)

```python
FunctionCtx.save_for_backward(*tensors)
```

> Saves given tensors for a future call to backward().
> 
> save_for_backward should be called at most once, only from inside the forward() method, and only with tensors.
> 
> All tensors intended to be used in the backward pass should be saved with save_for_backward (as opposed to directly on ctx) to prevent incorrect gradients and memory leaks, and enable the application of saved tensor hooks.
>
> Note that if intermediary tensors, tensors that are neither inputs nor outputs of forward(), are saved for backward, your custom Function may not support double backward. Custom Functions that do not support double backward should decorate their backward() method with @once_differentiable so that performing double backward raises an error. If you’d like to support double backward, you can either recompute intermediaries based on the inputs during backward or return the intermediaries as the outputs of the custom Function. See the [double backward tutorial](https://pytorch.org/tutorials/intermediate/custom_function_double_backward_tutorial.html) for more details.
>
> In backward(), saved tensors can be accessed through the saved_tensors attribute. Before returning them to the user, a check is made to ensure they weren’t used in any in-place operation that modified their content.
>
> **Arguments can also be None.** This is a no-op.

### Save

```python
ctx.save_for_backward(x, y, w, out)
```

Non-tensor (e.g. int):

```python
ctx.z = z
```

### Access

```python
x, y, w, out = ctx.saved_tensors
```

Non-tensor (e.g. int):

```python
z = ctx.z
```


## Example 

```python
class FunctionalLinear(torch.autograd.Function):
    @staticmethod
    def forward(  # type: ignore
        ctx, input: torch.Tensor, weight: torch.Tensor, bias: torch.Tensor
    ) -> torch.Tensor:
        output = (weight.unsqueeze(0) * input.unsqueeze(1)).sum(dim=-1)

        if bias is not None:
            output = output + bias.unsqueeze(0)

        # ###########################################################
        # Save the necessary data for the backward pass
        # ###########################################################
        ctx.save_for_backward(
            input,
            weight,
            bias,
        )

        return output

    @staticmethod
    @torch.autograd.function.once_differentiable
    def backward(  # type: ignore
        ctx, grad_output: torch.Tensor
    ) -> tuple[torch.Tensor | None, torch.Tensor | None, torch.Tensor | None]:
        # ##############################################
        # Get the variables back
        # ##############################################
        (
            input,
            weight,
            bias,
        ) = ctx.saved_tensors

        # ##############################################
        # Default output
        # ##############################################
        grad_input: torch.Tensor | None = None
        grad_weight: torch.Tensor | None = None
        grad_bias: torch.Tensor | None = None

        grad_weight = grad_output.unsqueeze(-1) * input.unsqueeze(-2)

        if bias is not None:
            grad_bias = grad_output.detach().clone()

        grad_input = (grad_output.unsqueeze(-1) * weight.unsqueeze(0)).sum(dim=1)

        return grad_input, grad_weight, grad_bias
```

We can now add it to our own class. First we have to add it to the class via 

```python
self.functional_linear = FunctionalLinear.apply
```

in the \_\_init\_\_() function. Then we have to use it in the forward function:

```python
return self.functional_linear(input, self.weight, self.bias)
```

In the forward function we should / can combine it with normal autograd operations. **Not everything needs to be in our own autograd function. In fact, try to put as little as possible into your own autograd function and let the rest handle by torch's autograd. Less is more.** 


```python
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

        self.functional_linear = FunctionalLinear.apply

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
        return self.functional_linear(input, self.weight, self.bias)

    def extra_repr(self) -> str:
        return f"in_features={self.in_features}, out_features={self.out_features}, bias={self.bias is not None}"
```
        
![Figure_1.png](Figure_1.png)
