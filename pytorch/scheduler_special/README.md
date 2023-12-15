# How to take advantage of a learning rate scheduler for your non-Pytorch project
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Pytorch provides you with so called lr_scheduler (learning rate scheduler). Their job is to control the learning rate according the development of the loss during learning. How can we use it for our own stimulation, without using the rest of PyTorch? 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

In a first step we build a dummy torch layer from a nn.Module. It contains only the learning rate as a registered parameter: 

```python
my_module = torch.nn.Module()
my_module.register_parameter(
    "something", torch.nn.Parameter(torch.full((1,), 1.0), requires_grad=True)
)
```

Now we fake an optimizer which is working on that module:

```python
lr: float = 1.0
opti = torch.optim.Optimizer(my_module.parameters(), dict(lr=lr))
```

Finally we can apply a lr scheduler on that "optimizer".

I will use as an example the torch.optim.lr_scheduler.ReduceLROnPlateau one (but there are many other alternatives):

```python
torch.optim.lr_scheduler.ReduceLROnPlateau(optimizer, mode='min', factor=0.1, patience=10, threshold=0.0001, threshold_mode='rel', cooldown=0, min_lr=0, eps=1e-08, verbose=False)
```

Reduce learning rate when a metric has stopped improving. Models often benefit from reducing the learning rate by a factor of 2-10 once learning stagnates. 
This scheduler reads a metrics quantity and if no improvement is seen for a ‘patience’ number of epochs, the learning rate is reduced.

Thus:

```python
lr_scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(
    opti,
    factor=lr_scheduler_factor,
    patience=lr_scheduler_patience,
)
``` 

After every batch, we now can report the loss to the scheduler via

```python
lr_scheduler.step(your_loss_scalar)
``` 

and read out the actual learning rate via

```python
opti.param_groups[-1]["lr"]
``` 
