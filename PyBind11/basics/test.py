from PyMyModuleCPU import MyModule
import numpy as np

MyCExtension = MyModule()

X = np.random.random((5, 6))

print("X")
print(X)

if MyCExtension.PutStuffIn(X) is False:
    print("Error (1)\n")
    exit()

Y = MyCExtension.GetStuffOut()

print("X-Y:")
print(X - Y)

if MyCExtension.DoStuff(5.0) is False:
    print("Error (2)\n")
    exit()

Z = MyCExtension.GetStuffOut()

print("X*5-Z:")
print(X * 5.0 - Z)
