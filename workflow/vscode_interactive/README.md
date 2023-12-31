# Python Interactive window
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Python Interactive window allows you to interactively develop code with VS Code. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Please use # %% with .py files instead of .ipynb Jupyter notebook files for interactive cells!!!**

If you don't know what I am talking about, please read: [Python Interactive window](https://code.visualstudio.com/docs/python/jupyter-support-py)

## Executing a cell

In the cell mode (# %%) you can use
* SHIFT + ENTER to execute a cell or
* CTRL + ENTER.

The former moves the cursor into the next cell, while the later keeps the cursor that the original position.

## [Interactive plotting in # %% cells​](https://matplotlib.org/ipympl/)

```shell
pip install ipympl
```

We can activate the interactive plotting mode via ​

```python
%matplotlib widget ​
```
The first time we use this command, vs code will need to download a plugin).

Here an example:

```python
# %%
%matplotlib widget

import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()

plt.plot(np.sin(np.linspace(0, 20, 100)))
```

Yes, mypy will give you an error and yes, you can not suppress it... but non you can zoom and pan the figure... You can not have everything at once!

### Modifing a plot

First we plot something but keep the handle:

```python
# %%
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
line = plt.plot(np.sin(np.linspace(0, 20, 100)))
```

Then we can use to change the plot using the handle:

```python
# %%
line[0].remove()
line = plt.plot(np.sin(5.0*np.linspace(0, 20, 100)))
```

If you don't know the handle, you can retrieve it like this: 

```python
# %%
handles = fig.gca().get_children()
print(handles)
```

```python
[<matplotlib.lines.Line2D object at 0x7fe130f75310>, <matplotlib.spines.Spine object at 0x7fe130f1d710>, <matplotlib.spines.Spine object at 0x7fe130f1dcd0>, <matplotlib.spines.Spine object at 0x7fe130f1e210>, <matplotlib.spines.Spine object at 0x7fe130f1e750>, <matplotlib.axis.XAxis object at 0x7fe130f1ecd0>, <matplotlib.axis.YAxis object at 0x7fe1310b7350>, Text(0.5, 1.0, ''), Text(0.0, 1.0, ''), Text(1.0, 1.0, ''), <matplotlib.patches.Rectangle object at 0x7fe130f3cf10>]
```

This allows us to do this: 

```python
# %%
fig.gca().get_children()[0].remove()
```

### Re-Plotting

You can use

```python
# %%
display(fig)
```

for replotting the plot. However you will get a message from VS Code that display is not defined. It is defined but it doesn't know it. 




