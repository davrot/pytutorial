# Expanding Python with C++ modules
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


```Makefile
PYBIN=~/P3.9/bin/
COMPILER=clang

PYBIND11INCLUDE=`$(PYBIN)python3 -m pybind11 --includes`

PARAMETERS= -O3 -std=c++14 -fPIC  $(PYBIND11INCLUDE) -Wall

THEMODULENAME=themodule`$(PYBIN)python3-config --extension-suffix`

all: themodule

MyModule.o: MyModule.h MyModule.cpp 
	$(COMPILER) $(PARAMETERS) -c MyModule.cpp -o MyModule.o

themodule.o: MyModule.h themodule.cpp 
	$(COMPILER) $(PARAMETERS) -c themodule.cpp -o themodule.o

themodule: MyModule.o themodule.o
	$(COMPILER) -shared -o themodule MyModule.o themodule.o -lm -lstdc++ -Wall
	cp themodule $(THEMODULENAME)

clean:
	rm -f $(THEMODULENAME)
	rm -f themodule
	rm -f *.o
```
