# PyBind11 Stub-Generation
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## ModuleStubsGenerator

If you editor / syntax highlighting complains then you might need module stubs. This is the way how I automatically generate my pybind11-stubs

(Based on [https://github.com/robotpy/robotpy-build/issues/1#issuecomment-663871072](https://github.com/robotpy/robotpy-build/issues/1#issuecomment-663871072) )

```shell
pip install pybind11-stubgen
```

```python
from pybind11_stubgen import ModuleStubsGenerator  # type: ignore
import glob


def process(module_name: str) -> None:
    module = ModuleStubsGenerator(module_name)
    module.parse()
    module.write_setup_py = False

    with open(module_name + ".pyi", "w") as fp:
        fp.write("#\n# AUTOMATICALLY GENERATED FILE, DO NOT EDIT!\n#\n\n")
        fp.write("\n".join(module.to_lines()))


Files = glob.glob("*.so")

for fid in Files:
    Idx: int = fid.find(".")
    module_name: str = fid[:Idx]
    print("Processing: " + module_name)
    process(module_name)
```
