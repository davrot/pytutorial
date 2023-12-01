# [TQDM](https://tqdm.github.io/) -- Make your progress visible
## Goal
Introducing a nice progress bar for for loops.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install tqdm
```

## trange
You can just replace range by trange:

```python
from tqdm import trange
import time

for i in trange(0, 10):
    time.sleep(1)
```

```python console
 30%|███       | 3/10 [00:03<00:07,  1.12s/it]
```

Beside trange, [TQDM](https://tqdm.github.io/) can be used for more elaborated setups. 

