# Python -- Type annotations and static type checking for Python
## Goal
We want to use static type checking and type annotations in our Python code for detecting errors we made. We will use the tool mypy for that. 

```python
a: int = 0
b: float = 0.0
a = b     Incompatible types in assignment (expression has type "float", variable has type "int")
```

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

