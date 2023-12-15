# How to take advantage of an optimizer for your non-Pytorch project
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Pytorch provides you with optimizer. Their job is to update your parameter (e.g. weights) with a gradient. How can we use it for our own stimulation, without using the rest of PyTorch? 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

In a first step we build a dummy torch layer from a **nn.Module**. It contains a registered  parameter: (here it is the weight). 

## Dummy torch layer

```python
import torch

my_module: torch.nn.Module = torch.nn.Module()
my_parameter: torch.nn.Parameter = torch.nn.Parameter(
    torch.ones((10, 5)), requires_grad=True
)
my_module.register_parameter("w", my_parameter)


if my_module._parameters["w"] is None:
    raise Exception("Parameter w is missing.")
else:
    my_gradient = torch.zeros_like(my_module._parameters["w"])
```

The parameter consists of data

```python
my_module._parameters["w"].data
```

and the gradient

```python
my_module._parameters["w"].grad
```

We can interface the gradient and the data of the parameter via **.grad** and **.data**. It is important both are **torch.Tensor** elements and have the same dtype (Probably the dtype is not allowed to change but I didn't tested that.). 

## The optimizer

Now we can connect the parameters to an optimizer . Here I will use Adam: 

```python
optimizer = torch.optim.Adam(my_module.parameters())
```

If we want to use the power of the optimizer we fill our momentary gradient and the old weights into the parameter **.grad** and **.data** and call

```python
optimizer.step()
```

Now we can read the optimized weights from **.data** and put them into our non-PyTorch network. I addition we can add a lr scheduler too. 

Notes:

* Don't replace the my_module._parameters["w"] with a new parameter object. Then the optimizer looses the contact to the parameter. Only use .data and .grad !
* Don't use this for different parameters. Let's say you have two layers. Then you need to create TWO fake layers and TWO optimizers (and TWO lr_scheduler). An optimizer has internal memory thus it should only deal with it's parameter. 
* You need to tell the optimizier if you want to use old parameter - update (default) or  old parameter + update (maximize=True)
 
