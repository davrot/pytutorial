# glob -- Finding files in a directory

## Goal
We want to deal with many files in a directory. What is an easy way to get the filename in a directory?

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Creating test files

```python
from pathlib import Path

Path("Testfile_1.mat").touch()
Path("Testfile_2.mat").touch()
Path("Testfile_10.mat").touch()
Path("Testfile_3.mat").touch()
```

## Using glob in a for-loop

```python
import glob

for filename in glob.glob("*.mat"):
    print(filename)
```

```python console
Testfile_1.mat
Testfile_2.mat
Testfile_10.mat
Testfile_3.mat
```

## Using glob to create a list

```python
import glob

list = glob.glob("*.mat")
print(list)
```

```python console
['Testfile_1.mat', 'Testfile_2.mat', 'Testfile_10.mat', 'Testfile_3.mat']
```

### Sorting the filenames

```python
import glob

list = sorted(glob.glob("*.mat"))
print(list)
```

```python console
['Testfile_1.mat', 'Testfile_10.mat', 'Testfile_2.mat', 'Testfile_3.mat']
```





