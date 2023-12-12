# JSON and dict
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [json -- JSON encoder and decoder](https://docs.python.org/3/library/json.html)

### [dump](https://docs.python.org/3/library/json.html#json.dump)

```python
import json

a = dict(one=1, two=2, three=3)

with open("data_out.json", "w") as file:
    json.dump(a, file)
```

Content of data_out.json: 

```json
{"one": 1, "two": 2, "three": 3}
```

### [load](https://docs.python.org/3/library/json.html#json.load)


```python
import json

with open("data_out.json", "r") as file:
    b = json.load(file)

print(b)
```

Output:

```python
{'one': 1, 'two': 2, 'three': 3}
```

## [jsmin](https://github.com/tikitu/jsmin/) and [loads](https://docs.python.org/3/library/json.html#json.loads)

```shell
pip install jsmin
```

Maybe you want to have comments in your config file. 

Content of data_in.json: 
```json
// This an important comment...
{
    "one": 1,
    "two": 2,
    "three": 3
}
```

Note: You need to change the filetype from **JSON** to **JSON with comments**. Lower right corner. 

 The normal JSON functions fails:

```python
import json

with open("data_in.json", "r") as file:
    b = json.load(file)

print(b)
```
Output: 

```python
JSONDecodeError: Expecting value: line 1 column 1 (char 0)
```

With jsmin: 

```python
import json
from jsmin import jsmin

with open("data_in.json", "r") as file:
    minified = jsmin(file.read())
    
b = json.loads(minified)

print(b)
```

Output: 

```python
{'one': 1, 'two': 2, 'three': 3}
```
