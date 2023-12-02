# glob -- Finding files in a directory

## Goal
We want to deal with many files in a directory. What is an easy way to get the filename in a directory?

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Creating test files

```python
from pathlib import Path

Path("Testfile_001.mat").touch()
Path("Testfile_002.mat").touch()
Path("Testfile_010.mat").touch()
Path("Testfile_003.mat").touch()
```

