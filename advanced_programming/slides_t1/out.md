<span style="color:#FFFFCC"> __Topic \#1__ </span>  <span style="color:#FFCC00"> __Advanced__ </span>  <span style="color:#FFCC00"> __ __ </span>  <span style="color:#FFCC00"> __Programming__ </span>  <span style="color:#FFCC00"> __ __ </span>  <span style="color:#FFCC00"> __Concepts__ </span>

![](img/T1_AdvancedProgramming-Concepts0.png)

<span style="color:#0070C0"> __Type __ </span>  <span style="color:#0070C0"> __annotations__ </span>

__What__  __ __  __is__  __ __  __it__  __?__

Type annotations specify which type a variable is\.It‘s  <span style="color:#C00000">optional</span> \, but  <span style="color:#C00000">very</span>  <span style="color:#C00000"> </span>  <span style="color:#C00000">useful</span> \!

![](img/T1_AdvancedProgramming-Concepts1.png)

__What__  __ __  __is__  __ __  __it__  __ __  __good__  __ __  __for__  __?__

PEP 484 – Type Hints \(29\-Sep\-2014\):

<span style="color:#0070C0"> _“This _ </span>  <span style="color:#0070C0"> _PEP aims to provide a standard syntax for type annotations\, opening up Python code to easier static analysis and refactoring\, potential runtime type checking\, and \(perhaps\, in some contexts\) code generation utilizing type information_ </span>  <span style="color:#0070C0"> _\._ </span>

<span style="color:#0070C0"> _Of _ </span>  <span style="color:#0070C0"> _these goals\, static analysis is the most important\. This includes support for off\-line type checkers such as _ </span>  <span style="color:#0070C0"> _mypy_ </span>  <span style="color:#0070C0"> _\, as well as providing a standard notation that can be used by IDEs for code completion and refactoring_ </span>  <span style="color:#0070C0"> _\._ </span>

<span style="color:#0070C0"> _\[…\]_ </span>

<span style="color:#0070C0"> _It _ </span>  <span style="color:#0070C0"> _should also be emphasized that Python will remain a dynamically typed language\, and the authors have no desire to ever make type hints mandatory\, even by convention_ </span>  <span style="color:#0070C0"> _\.”_ </span>

__David’s redefinition:__

It is a part of your  <span style="color:#C00000">automatic documentation </span> \(like with meaningful variable names\)\. If another person gets your source code they understand it easier\.

Your  <span style="color:#C00000">editor might thank you</span> \. Do to some new features in Python 3\.10\, the modern editors that do syntax highlighting and error checking have a harder time to infer what you mean\. The more it need to think about what you mean\, the slower your editor might get or even fail to show you syntax highlighting\.

<span style="color:#C00000">Static </span>  <span style="color:#C00000">code analysis is really helpful</span> \. It showed me any problems ahead that I would have figured out the hard way otherwise\.

Packages like the just\-in\-time compiler  <span style="color:#C00000">numba</span>  <span style="color:#C00000"> can produce better results </span> if you can tell it what the variables are\.

__When__  __ __  __and__  __ __  __how__  __ do __  __we__  __ do __  __it__  __?__

…mostly when we introduce new variables or define functions or classes:

![](img/T1_AdvancedProgramming-Concepts2.png)

![](img/T1_AdvancedProgramming-Concepts3.png)

![](img/T1_AdvancedProgramming-Concepts4.png)

![](img/T1_AdvancedProgramming-Concepts5.png)

![](img/T1_AdvancedProgramming-Concepts6.png)

Variables with different types:

![](img/T1_AdvancedProgramming-Concepts7.png)

…could also be explicit list with ‚or‘ separators…

![](img/T1_AdvancedProgramming-Concepts8.png)

__Functions__  __\, __  __more__  __ __  __complex__  __ __  __types__  __…__

![](img/T1_AdvancedProgramming-Concepts9.png)

![](img/T1_AdvancedProgramming-Concepts10.png)

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

[https://davrot\.github\.io/pytutorial/python\_basics/python\_typing](https://davrot.github.io/pytutorial/python_basics/python_typing/)[/](https://davrot.github.io/pytutorial/python_basics/python_typing/)

__What__  __ __  __is__  __ a __  __class__  __?__

A class is a  <span style="color:#0070C0"> __container__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __for__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __data__ </span>  <span style="color:#0070C0"> __ \(__ </span>  <span style="color:#0070C0"> __attributes__ </span>  <span style="color:#0070C0"> __\)__ </span>  and  <span style="color:#0070C0"> __functions__ </span>  <span style="color:#0070C0"> __ \(__ </span>  <span style="color:#0070C0"> __methods__ </span>  <span style="color:#0070C0"> __\)__ </span> \. They bundle properties of ‚objects‘ and actions that can be performed with/on them\.

Classes help to  <span style="color:#0070C0"> __modularize__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __and__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __organize__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __your__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __code__ </span>  <span style="color:#0070C0"> __ __ </span> even more than functions\.

<span style="color:#0070C0"> __Class __ </span>  <span style="color:#0070C0"> __hierarchies__ </span>  <span style="color:#0070C0"> __ __ </span> are useful for re\-using code which is common for different ‚objects‘

<span style="color:#0070C0"> __Dataclasses__ </span>  <span style="color:#0070C0"> __ __ </span> are specific classes in Python intended to represent data that ‚belongs together‘\.

__Vehicle__  __:__

<span style="color:#C00000">wheels</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">int</span>

<span style="color:#C00000">speed</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#1233AE">accelerate</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">speed</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">float</span>  <span style="color:#1233AE">\)</span>

<span style="color:#1233AE">stop</span>  <span style="color:#1233AE">\(\)</span>

__Bus\(__  __Vehicle__  __\):__

<span style="color:#C00000">passengers</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">int</span>

<span style="color:#C00000">routenr</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">int</span>

<span style="color:#C00000">intake</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#1233AE">board</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">nrpass</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">int</span>  <span style="color:#1233AE">\)</span>

__Car\(__  __Vehicle__  __\):__

<span style="color:#C00000">passengers</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">int</span>

<span style="color:#1233AE">board</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">nrpass</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">int</span>  <span style="color:#1233AE">\)</span>

__Truck\(__  __Vehicle__  __\):__

<span style="color:#C00000">company</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">str</span>

<span style="color:#C00000">weight</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#1233AE">load</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">weight</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">float</span>  <span style="color:#1233AE">\)</span>

<span style="color:#00B050"> _parent_ </span>  <span style="color:#00B050"> _ _ </span>  <span style="color:#00B050"> _class_ </span>  <span style="color:#00B050"> _ / _ </span>  <span style="color:#00B050"> _superclass_ </span>

<span style="color:#C00000">wheels</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">int</span>

<span style="color:#C00000">speed</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#C00000">passengers</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">int</span>

<span style="color:#C00000">litres</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#C00000">kwh</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#1233AE">accelerate</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">speed</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">float</span>  <span style="color:#1233AE">\)</span>

<span style="color:#1233AE">stop</span>  <span style="color:#1233AE">\(\)</span>

<span style="color:#1233AE">board</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">nrpass</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">int</span>  <span style="color:#1233AE">\)</span>

<span style="color:#1233AE">fill</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">litres</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">float</span>  <span style="color:#1233AE">\)</span>

<span style="color:#1233AE">charge</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">kwh</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">float</span>  <span style="color:#1233AE">\)</span>

__Electric__  __\(Car\):__

<span style="color:#C00000">kwh</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#1233AE">charge</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">kwh</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">float</span>  <span style="color:#1233AE">\)</span>

__Petrol\(Car\):__

<span style="color:#C00000">litres</span>  <span style="color:#C00000">: </span>  <span style="color:#C00000">float</span>

<span style="color:#1233AE">fill</span>  <span style="color:#1233AE">\(</span>  <span style="color:#1233AE">litres</span>  <span style="color:#1233AE">: </span>  <span style="color:#1233AE">float</span>  <span style="color:#1233AE">\)</span>

<span style="color:#00B050"> _child_ </span>  <span style="color:#00B050"> _ _ </span>  <span style="color:#00B050"> _class_ </span>  <span style="color:#00B050"> _ / _ </span>  <span style="color:#00B050"> _subclass_ </span>

__Hybrid\(Petrol\, __  __Electric__  __\):__

b\) Including and setting attributes \(variables\):

![](img/T1_AdvancedProgramming-Concepts11.png)

<span style="color:#C00000"> __please__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __don‘t__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __initialize__ </span>  <span style="color:#C00000"> __ in __ </span>  <span style="color:#C00000"> __attribute__ </span>  <span style="color:#C00000"> __ __ </span>  <span style="color:#C00000"> __section__ </span>  <span style="color:#C00000"> __\!__ </span>

a\) Defining and instantiating a class:

![](img/T1_AdvancedProgramming-Concepts12.png)

![](img/T1_AdvancedProgramming-Concepts13.png)

c\) Including and using methods \(functions\):

c\) multiple inheritance

![](img/T1_AdvancedProgramming-Concepts14.png)

![](img/T1_AdvancedProgramming-Concepts15.png)

![](img/T1_AdvancedProgramming-Concepts16.png)

There are special methods for certain purposes:

<span style="color:#0070C0"> __\_\___ </span>  <span style="color:#0070C0"> __init__ </span>  <span style="color:#0070C0"> __\_\_: __ </span> called always when a class is instantiated\. Good for initalizing and setting up a meaningful state for a class instance\.

<span style="color:#0070C0"> __\_\___ </span>  <span style="color:#0070C0"> __str__ </span>  <span style="color:#0070C0"> __\_\_: __ </span> called by  <span style="color:#0070C0"> __str__ </span>  <span style="color:#0070C0"> __\(object\)__ </span>  and the built\-in functions  <span style="color:#0070C0"> __format\(\)__ </span>  and  <span style="color:#0070C0"> __print\(\) __ </span> to compute the “informal” or nicely printable string representation of an object\. See also  <span style="color:#0070C0"> __\_\___ </span>  <span style="color:#0070C0"> __repr__ </span>  <span style="color:#0070C0"> __\_\_ __ </span> for the built\-in function  <span style="color:#0070C0"> __repr__ </span>  <span style="color:#0070C0"> __\(\)__ </span> \.

<span style="color:#0070C0"> __super\(\): __ </span> refers to the parent class\. Good to call functions from that class\.  __Example:__

![](img/T1_AdvancedProgramming-Concepts17.png)

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/python\_basics/class](https://davrot.github.io/pytutorial/python_basics/class/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/python_basics/class/)</span>

The  __dat__  __a__  __class__  is very similar to normal classes\, but it requires  __type __  __annotations__  __ __ thus serving a good programming style\. You have to  <span style="color:#0070C0"> __import__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __from__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __dataclasses__ </span>  <span style="color:#0070C0"> __ __ </span> and use a decorator  <span style="color:#0070C0"> __@__ </span>  <span style="color:#0070C0"> __dataclass__ </span>  <span style="color:#0070C0"> __ __ </span> when you define a dataclass:

![](img/T1_AdvancedProgramming-Concepts18.png)

<span style="color:#FF0000"> __there__ </span>  <span style="color:#FF0000"> __ will __ </span>  <span style="color:#FF0000"> __be__ </span>  <span style="color:#FF0000"> __ an __ </span>  <span style="color:#FF0000"> __error__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __without__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __these__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __annotations__ </span>  <span style="color:#FF0000"> __\!__ </span>

__A __  __dataclass__  __ __  __has__  __ an __  __automatic__  __ \_\___  __init__  __\_\_\(\) __  __method__  __ __  __which__  __ __  __can__  __ __  __be__  __ __  __used__  __ __  __to__  __ __  __populate__  __ __  __the__  __ __  __attributes__  __…__

__Further Features I__

![](img/T1_AdvancedProgramming-Concepts19.png)

<span style="color:#0070C0"> __default\_factory__ </span>  can be used to specify automatic generation of default values\.

TestClassA\(name=''\, number\_of\_electrodes=0\, dt=0\.0\, sample\_rate\_in\_hz=0\.0\)

__Further Features I__

![](img/T1_AdvancedProgramming-Concepts20.png)

<span style="color:#FF0000">defaults</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">can</span>  <span style="color:#FF0000"> also </span>  <span style="color:#FF0000">be</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">specified</span>  <span style="color:#FF0000"> in </span>  <span style="color:#FF0000">the</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">class</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">definiton</span>  <span style="color:#FF0000"> \(</span>  <span style="color:#FF0000">please</span>  <span style="color:#FF0000"> do not do </span>  <span style="color:#FF0000">this</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">to</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">mutables</span>  <span style="color:#FF0000">\!\)</span>

<span style="color:#00B050">attributes</span>  <span style="color:#00B050"> </span>  <span style="color:#00B050">can</span>  <span style="color:#00B050"> </span>  <span style="color:#00B050">be</span>  <span style="color:#00B050"> </span>  <span style="color:#00B050">spared</span>  <span style="color:#00B050"> </span>  <span style="color:#00B050">from</span>  <span style="color:#00B050"> </span>  <span style="color:#00B050">initialization</span>

<span style="color:#990099">attributes</span>  <span style="color:#990099"> </span>  <span style="color:#990099">can</span>  <span style="color:#990099"> </span>  <span style="color:#990099">explicitly</span>  <span style="color:#990099"> </span>  <span style="color:#990099">be</span>  <span style="color:#990099"> </span>  <span style="color:#990099">specified</span>  <span style="color:#990099"> </span>  <span style="color:#990099">as</span>  <span style="color:#990099"> </span>  <span style="color:#990099">keywords</span>

![](img/T1_AdvancedProgramming-Concepts21.png)

![](img/T1_AdvancedProgramming-Concepts22.png)

<span style="color:#0070C0"> __\_\___ </span>  <span style="color:#0070C0"> __post\_init__ </span>  <span style="color:#0070C0"> __\_\_\(\) __ </span> if you have to do some init of your own…

<span style="color:#0070C0"> __\_\___ </span>  <span style="color:#0070C0"> __str__ </span>  <span style="color:#0070C0"> __\_\_\(\) __ </span> for a nice printout\!

__Why__  __ __  __dataclasses__  __?__

putting data together into meaningful containers…

appropriate type handling…

versatile and safe initialization methods…

__makes__  __ __  __comparing__  __ __  __data__  __ __  __sets__  __ easy…\!__

![](img/T1_AdvancedProgramming-Concepts23.png)

![](img/T1_AdvancedProgramming-Concepts24.png)

![](img/T1_AdvancedProgramming-Concepts25.png)

![](img/T1_AdvancedProgramming-Concepts26.png)

__…__  __compare__  __ __  __everything__

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

[https://davrot\.github\.io/pytutorial/python\_basics/dataclass](https://davrot.github.io/pytutorial/python_basics/dataclass/)[/](https://davrot.github.io/pytutorial/python_basics/dataclass/)

<span style="color:#0070C0"> __Catch __ </span>  <span style="color:#0070C0"> __me__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __if__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __you__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __can__ </span>  <span style="color:#0070C0"> __\!__ </span>

![](img/T1_AdvancedProgramming-Concepts27.png)

syntax errors

logical errors

data inconsistencies

exceptions

inadequate usage or user input

…

Assert checks if a condition is true\. If not\, it issues and error and stops program execution\. Example:

![](img/T1_AdvancedProgramming-Concepts28.png)

Use it often to make your code safe to use\, or to discover inconsistencies in input data\!

<span style="color:#C586C0">import</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">numpy</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#C586C0">as</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">np</span>

<span style="color:#569CD6">def</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#DCDCAA">solve\_quadratic</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#CCCCCC">: </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">b</span>  <span style="color:#CCCCCC">: </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">c</span>  <span style="color:#CCCCCC">: </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\) \-> </span>  <span style="color:#4EC9B0">tuple</span>  <span style="color:#CCCCCC">\[</span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\]:</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">assert</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#DCDCAA">isinstance</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\)\, </span>  <span style="color:#CE9178">"</span>  <span style="color:#CE9178">argument</span>  <span style="color:#CE9178"> 'a' must </span>  <span style="color:#CE9178">be</span>  <span style="color:#CE9178"> </span>  <span style="color:#CE9178">float</span>  <span style="color:#CE9178">\!"</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">assert</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#DCDCAA">isinstance</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\)\, </span>  <span style="color:#CE9178">"</span>  <span style="color:#CE9178">argument</span>  <span style="color:#CE9178"> 'b' must </span>  <span style="color:#CE9178">be</span>  <span style="color:#CE9178"> </span>  <span style="color:#CE9178">float</span>  <span style="color:#CE9178">\!"</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">assert</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#DCDCAA">isinstance</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">c</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\)\, </span>  <span style="color:#CE9178">"</span>  <span style="color:#CE9178">argument</span>  <span style="color:#CE9178"> 'c' must </span>  <span style="color:#CE9178">be</span>  <span style="color:#CE9178"> </span>  <span style="color:#CE9178">float</span>  <span style="color:#CE9178">\!"</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">assert</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">a</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">\!=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#B5CEA8">0</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#CE9178">"</span>  <span style="color:#CE9178">argument</span>  <span style="color:#CE9178"> a must </span>  <span style="color:#CE9178">be</span>  <span style="color:#CE9178"> non\-zero\, </span>  <span style="color:#CE9178">otherwise</span>  <span style="color:#CE9178"> </span>  <span style="color:#CE9178">it's</span>  <span style="color:#CE9178"> not a </span>  <span style="color:#CE9178">quadratic</span>  <span style="color:#CE9178"> </span>  <span style="color:#CE9178">equation</span>  <span style="color:#CE9178">\!"</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#9CDCFE">sqrt\_arg</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#B5CEA8">4</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">c</span>  <span style="color:#D4D4D4">\+</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#D4D4D4">\*\*</span>  <span style="color:#B5CEA8">2</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">assert</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">sqrt\_arg</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">>=</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#B5CEA8">0</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#CE9178">"</span>  <span style="color:#CE9178">root</span>  <span style="color:#CE9178"> </span>  <span style="color:#CE9178">argument</span>  <span style="color:#CE9178"> must </span>  <span style="color:#CE9178">be</span>  <span style="color:#CE9178"> positive </span>  <span style="color:#CE9178">for</span>  <span style="color:#CE9178"> non\-</span>  <span style="color:#CE9178">imaginary</span>  <span style="color:#CE9178"> </span>  <span style="color:#CE9178">solutions</span>  <span style="color:#CE9178">\!"</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#9CDCFE">x1</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> \(</span>  <span style="color:#D4D4D4">\+</span>  <span style="color:#4EC9B0">np</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#9CDCFE">sqrt</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#B5CEA8">4</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">c</span>  <span style="color:#D4D4D4">\+</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#D4D4D4">\*\*</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">/</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#9CDCFE">x2</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> \(</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#4EC9B0">np</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#9CDCFE">sqrt</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#B5CEA8">4</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">c</span>  <span style="color:#D4D4D4">\+</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#D4D4D4">\*\*</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">/</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">return</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">x1</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">x2</span>

<span style="color:#C586C0">import</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">numpy</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#C586C0">as</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">np</span>

<span style="color:#569CD6">def</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#DCDCAA">solve\_quadratic</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#CCCCCC">: </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">b</span>  <span style="color:#CCCCCC">: </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">c</span>  <span style="color:#CCCCCC">: </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\) \-> </span>  <span style="color:#4EC9B0">tuple</span>  <span style="color:#CCCCCC">\[</span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#4EC9B0">float</span>  <span style="color:#CCCCCC">\]:</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#9CDCFE">x1</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> \(</span>  <span style="color:#D4D4D4">\+</span>  <span style="color:#4EC9B0">np</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#9CDCFE">sqrt</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#B5CEA8">4</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">c</span>  <span style="color:#D4D4D4">\+</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#D4D4D4">\*\*</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">/</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#9CDCFE">x2</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#D4D4D4">=</span>  <span style="color:#CCCCCC"> \(</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#4EC9B0">np</span>  <span style="color:#CCCCCC">\.</span>  <span style="color:#9CDCFE">sqrt</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#B5CEA8">4</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">c</span>  <span style="color:#D4D4D4">\+</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#D4D4D4">\*\*</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">\-</span>  <span style="color:#9CDCFE">b</span>  <span style="color:#CCCCCC">\)</span>  <span style="color:#D4D4D4">/</span>  <span style="color:#B5CEA8">2</span>  <span style="color:#D4D4D4">\*</span>  <span style="color:#9CDCFE">a</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">return</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">x1</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#9CDCFE">x2</span>

<span style="color:#DCDCAA">solve\_quadratic</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#CE9178">"A"</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#CE9178">"B"</span>  <span style="color:#CCCCCC">\, </span>  <span style="color:#CE9178">"C"</span>  <span style="color:#CCCCCC">\)</span>

---

Assert is better than if and exception thrown by hand, since ist shorter and ist immediately clear without adding a comment that some checking is performed…

__Try … __  __Except__  __ … Else … __  __Finally__  __ …__

Errors need not terminate your program\. Each error raises an exception\, and you can catch that exception and handle it properly\!

__Example__  __ __  __for__  __ different __  __exceptions__  __…__

![](img/T1_AdvancedProgramming-Concepts29.png)

__…__  __and__  __ __  __example__  __ __  __for__  __ __  __handling__  __ an __  __exception__  __ __  __nicely__  __:__

![](img/T1_AdvancedProgramming-Concepts30.png)

try this piece of code…

![](img/T1_AdvancedProgramming-Concepts31.png)

<span style="color:#C586C0">for</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">i</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#C586C0">in</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">range</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#CCCCCC">n\_files</span>  <span style="color:#CCCCCC">\):</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">try</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# open file\[</span>  <span style="color:#6A9955">i</span>  <span style="color:#6A9955">\] for read</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# read neural activity into temp array</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# normalize temp array by its sum</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">except</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">OSError</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# assign None to data\[</span>  <span style="color:#6A9955">i</span>  <span style="color:#6A9955">\]</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">else</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# assign temp array to data\[</span>  <span style="color:#6A9955">i</span>  <span style="color:#6A9955">\] </span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">finally</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# close file if open</span>

<span style="color:#DCDCAA">print</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#CE9178">"Successfully read existing data files\.\.\."</span>  <span style="color:#CCCCCC">\)</span>

… __if__  __ __  __the__  __ __  __specified__  __ __  __exception__  __ __  __occurred__ \, execute this piece of code  __\(‚__  __error__  __ __  __handling__  __‘\)__ …

… __otherwise__ \, execute this piece of code\. You can put code here which runs only correctly when the exception did not occur…

… __in __  __any__  __ __  __case__ \, execute this piece of code\, irrespectively of errors having occurred/not occurred  __\(‚clean\-__  __up__  __‘\)__ \. When an unhandled exception occurred\, execution stop after this code\!

<span style="color:#990099"> __division__ </span>  <span style="color:#990099"> __ __ </span>  <span style="color:#990099"> __by__ </span>  <span style="color:#990099"> __ __ </span>  <span style="color:#990099"> __zero__ </span>  <span style="color:#990099"> __ __ </span>  <span style="color:#990099"> __occurs__ </span>  <span style="color:#990099"> __\!__ </span>

<span style="color:#0070C0"> __everything__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __is__ </span>  <span style="color:#0070C0"> __ okay\!__ </span>

<span style="color:#FF0000"> __file__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __does__ </span>  <span style="color:#FF0000"> __ not __ </span>  <span style="color:#FF0000"> __exist__ </span>  <span style="color:#FF0000"> __\, __ </span>  <span style="color:#FF0000"> __or__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __is__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __corrupt__ </span>  <span style="color:#FF0000"> __\!__ </span>

__General form\, __  __example__  __:__

<span style="color:#C586C0">for</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#9CDCFE">i</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#C586C0">in</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">range</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#CCCCCC">n\_files</span>  <span style="color:#CCCCCC">\):</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">try</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# open file\[</span>  <span style="color:#6A9955">i</span>  <span style="color:#6A9955">\] for read</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# read neural activity into temp array</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# normalize temp array by its sum</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">except</span>  <span style="color:#CCCCCC"> </span>  <span style="color:#4EC9B0">OSError</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# assign None to data\[</span>  <span style="color:#6A9955">i</span>  <span style="color:#6A9955">\]</span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">else</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# assign temp array to data\[</span>  <span style="color:#6A9955">i</span>  <span style="color:#6A9955">\] </span>

<span style="color:#CCCCCC">    </span>  <span style="color:#C586C0">finally</span>  <span style="color:#CCCCCC">:</span>

<span style="color:#CCCCCC">        </span>  <span style="color:#6A9955">\# close file if open</span>

<span style="color:#DCDCAA">print</span>  <span style="color:#CCCCCC">\(</span>  <span style="color:#CE9178">"Successfully read existing data files\.\.\."</span>  <span style="color:#CCCCCC">\)</span>

__Possible__  __ __  __exceptions__  __…__

![](img/T1_AdvancedProgramming-Concepts32.png)

![](img/T1_AdvancedProgramming-Concepts33.png)

![](img/T1_AdvancedProgramming-Concepts34.png)

…and you can define your own\!

__Exceptions__  __ __  __have__  __ __  __associated__  __ __  __information__  __ in __  __their__  __ __  __attributes__

![](img/T1_AdvancedProgramming-Concepts35.png)

![](img/T1_AdvancedProgramming-Concepts36.png)

__Raising__  __ __  __exceptions__

…or a  __newly__  __ __  __defined__  __ __  __exception__ …

![](img/T1_AdvancedProgramming-Concepts37.png)

When you determine that something goes wrong\, you can yourself raise an exception…

…either a  __matching__  __\, __  __predefined__  __ __  __one__

![](img/T1_AdvancedProgramming-Concepts38.png)

![](img/T1_AdvancedProgramming-Concepts39.png)

<span style="color:#0070C0"> __Using__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __the__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __debugger__ </span>

The VSCode debugger lets you follow\, monitor\, and manipulate the execution of program code…

__Examples__  __ __  __of__  __ __  __actions__  __ __  __possible__  __:__

step over\, step in\, step out

continue

breakpoints\, conditional breakpoints\, function breakpoints

inspection and change of variables

monitoring

…

<span style="color:#FF0000"> __Interactive __ </span>  <span style="color:#FF0000"> __demonstration__ </span>  <span style="color:#FF0000"> __…__ </span>

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/workflow/vscode\_debug](https://davrot.github.io/pytutorial/workflow/vscode_debug/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/workflow/vscode_debug/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/python\_basics/exceptions](https://davrot.github.io/pytutorial/python_basics/exceptions/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/python_basics/exceptions/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/python\_basics/assert](https://davrot.github.io/pytutorial/python_basics/assert/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/python_basics/assert/)</span>

