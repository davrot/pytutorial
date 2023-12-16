# Debugging Python code
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

We want to debug our Python source code like professionals.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Simple debugging in cell mode 

If we use cells ( # %% ) (i.e. Python Interactive window ) then we can use the Variable button in the interactive Python window to open a variable viewer. 

![image1](2022-04-01_18-40_0.png)

Also you can interact with the Python kernel directly via the command input line (the lower thing in the interactive window). There you can enter a Python command and press Shift + Enter to execute it. 

## Where to find the debugger (normal mode)?

![image2](2022-04-01_21-12.png)

## Where to find the debugger (cell mode)?

![image3](2022-04-01_21-48_1.png)

Note: My first Step Over 
![image4](2022-04-01_21-30_2.png)
click is ignored. Why? I don't know.  

![image5](2022-04-01_21-47_0.png)


## Debugger controls 
### Control toolbar

|||
|---|---|
|![image6](2022-04-01_21-30.png)|	Continue -- Debugger continues to run the code until the next breakpoint is reached or until the program ends. If end of the program is reached, the debugger closes. |
|![image7](2022-04-01_21-30_2.png)|	Step Over|
|![image8](2022-04-01_21-30_3.png)|	Step Into|
|![image9](2022-04-01_21-31.png)|	Step Out|
|![image10](2022-04-01_21-31_1.png)|	Restart -- Starts the debugging process from the beginning. |
|![image11](2022-04-01_21-31_2.png)|	Stop -- Stops the debugging and the debugger closes.|
 

### Continue vs Step Over vs Step Into vs Step Out

Example code:

```python
# %%
def function(x: int) -> int:
    x += 1
    x += 1
    x += 1
    x += 1
    return x


x = 1
x = function(x)
x = function(x)
x = function(x)
```

### Continue

![image12](2022-04-02_00-20.png)

Then ![image13](2022-04-01_21-30.png) Continue:

![image14](2022-04-02_00-22.png)


### Step Over
* ["If the current line contains a function call, Step Over runs the code and then suspends execution at the first line of code after the called function returns."](https://docs.microsoft.com/en-us/visualstudio/debugger/navigating-through-code-with-the-debugger?view=vs-2022#BKMK_Step_over_Step_out)

![image15](2022-04-02_00-25_1.png)

Then ![image16](2022-04-01_21-30_2.png) Step Over:

![image17](2022-04-02_00-26.png)

### Step Into
* ["The debugger steps through code statements, not physical lines."](https://docs.microsoft.com/en-us/visualstudio/debugger/navigating-through-code-with-the-debugger?view=vs-2022#BKMK_Step_into__over__or_out_of_the_code)
* ["But when you step into this line, the debugger treats the condition as one step and the consequence as another."](https://docs.microsoft.com/en-us/visualstudio/debugger/navigating-through-code-with-the-debugger?view=vs-2022#BKMK_Step_into__over__or_out_of_the_code)
* ["On a nested function call, Step Into steps into the most deeply nested function. For example, if you use Step Into on a call like Func1(Func2()), the debugger steps into the function Func2."](https://docs.microsoft.com/en-us/visualstudio/debugger/navigating-through-code-with-the-debugger?view=vs-2022#BKMK_Step_into__over__or_out_of_the_code)


![image18](2022-04-02_00-27.png)

Then ![image19](2022-04-01_21-30_3.png) Step Into:

![image20](2022-04-02_00-31_1.png)


### Step Out

* ["Step Out continues running code and suspends execution when the current function returns. The debugger skips through the current function."](https://docs.microsoft.com/en-us/visualstudio/debugger/navigating-through-code-with-the-debugger?view=vs-2022#BKMK_Step_over_Step_out)

![image21](2022-04-02_00-27.png)

Then ![image22](2022-04-01_21-30_3.png) Step Into:

![image23](2022-04-02_00-31_1_0.png)

Then ![image24](2022-04-01_21-31.png) Step Out :

![image25](2022-04-02_00-32.png)

## Breakpoints

## Normal Breakpoints

**No breakpoint => No debugging.** You need to set breakpoints. Thus the debugger know where you want it to stop and allow you to investigate the state of your program. 

You can create breakpoints by making these red dot  in your source code. You just click left beside the line number (with the left mouse button) and get a new breakpoint. 

![image26](2022-04-01_21-18.png)

If you click again then the red dot vanishes and the breakpoint is removed.

You can use the context menu (right mouse button) do deactivate or enable an existing breakpoint. In the case of a disabled breakpoint it turns gray. 

![image27](2022-04-01_21-20.png)

In the breakpoint window, you see all your breakpoints. The X Symbol removes the breakpoint. Removing a blue checkmark disables the corresponding breakpoint. 

![image28](2022-04-01_21-15_0.png)

### Expression

We can use the context menu (right mouse click) to add "Add Conditional Breakpoint...". Expression allow to define a condition that needs to be true to activate the breakpoint. 

![image29](2022-04-02_00-55.png)

Now is a not fully filled dot. 

![image30](2022-04-02_00-56_0.png)

You can use the context menu to change the condition or delete the breakpoint. 

If you start debugging, this is where the debugger stops as initial breakpoint: 

![image31](2022-04-02_01-00_0.png)

### Hit Count

Hit Count (defined via the context menu) allows to set an integer value for how often a position in a source code needs to be "hit" (i.e. run) until a breakpoint is activated.

![image32](2022-04-02_01-03.png)

![image33](2022-04-02_01-06_0.png)


If you start debugging, this is where the debugger stops as initial breakpoint: 

![image34](2022-04-02_01-07_0.png)

### Log Message / Add Log Point...

Log Message allows you to add the generation debug messages (messages in the debug console). If this "breakpoint" is passed by the debugger then a debug message is generated. However this is not a breakpoint that stops running the program like a normal breakpoint would. The message is defined akin to ["Formatted String Literals"](https://docs.python.org/3/tutorial/inputoutput.html#tut-f-strings) (also called f-string).

![image35](2022-04-02_01-11.png)

![image36](2022-04-02_01-13.png)

Running the debugger creates the following messages in the Debug Console:

![image37](2022-04-02_01-12.png)

### Function Breakpoints

In the Breakpoints window we can add Function Breakpoints. If the function named in the list is called that a breakpoint is initiated. 

Use the + symbol:

![image38](2022-04-02_01-40_0.png)

![image39](2022-04-02_01-38_0.png)

### Raise Exception Breakpoints

You can break on throwing exceptions even if we catch them. However, we need another breakpoint (disabled or enabled) otherwise we cannot enable the Raise Exception breakpoints.   

![image40](2022-04-02_01-46_0.png)

![image41](2022-04-02_01-52_0.png)


## Starting the debug process

When we are happy with the placement of the breakpoints, we click on "Run and Debug". Then we tell the debugger that this is a Python file. 

![image42](2022-04-01_21-25_0.png)

The yellow thingy tells us where in the source code we are in the moment:

![image43](2022-04-01_21-28.png)

If we press **Continue** then the debugger goes to the next breakpoint and we can view the content of the variables:

![image44](2022-04-01_21-44_0.png)

## Watch window

You can add variables to the watch window. This allows to observe variables and we can even watch slices of a numpy array:

![image45](2022-04-02_01-26_0.png)

You can add variables from the variable window via the context menu.

## Debug console

When the debugger waits for the next command from us, we can use the **Debug Console** to interact with the program. For example: We can print the value of variables or replace them with new values. If the console is not open already then you find it in the menu under View -> Debug Console.

![image46](2022-04-01_21-59_0.png)


## References

* [Navigate through code by using the Visual Studio debugger](https://docs.microsoft.com/en-us/visualstudio/debugger/navigating-through-code-with-the-debugger?view=vs-2022)
* [Debugging in VS Code](https://code.visualstudio.com/docs/editor/debugging)
* [Python debugging in VS Code](https://code.visualstudio.com/docs/python/debugging)
