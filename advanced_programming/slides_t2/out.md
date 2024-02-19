<span style="color:#FFFFCC"> __Topic \#2__ </span>  <span style="color:#FFCC00"> __Numerical__ </span>  <span style="color:#FFCC00"> __ __ </span>  <span style="color:#FFCC00"> __analysis__ </span>  <span style="color:#FFCC00"> __ __ </span>  <span style="color:#FFCC00"> __and__ </span>  <span style="color:#FFCC00"> __ __ </span>  <span style="color:#FFCC00"> __symbolic__ </span>  <span style="color:#FFCC00"> __ __ </span>  <span style="color:#FFCC00"> __computation__ </span>

![](img/T2_NumAnalysis-SymComp0.png)

__What__  __ __  __is__  __ __  __it__  __?__

Numerical analysis

Symbolic computation

__Which__  __ __  __tools__  __ __  __can__  __ __  __we__  __ __  __use__  __?__

 scipy

 sympy

![](img/T2_NumAnalysis-SymComp1.png)

__Background __  __info__  __ – __  __David‘s__  __ __  __compendium__  __ __  __reloaded__  __\!__

[https://davrot\.github\.io/pytutorial](https://davrot.github.io/pytutorial/)[/](https://davrot.github.io/pytutorial/)

__Topics:__

Sympy

Numerical Integration\, Differentiation\, and Differential Equations

__Which__  __ __  __mathematical__  __ __  __problems__  __ __  __are__  __ __  __we__  __ __  __interested__  __ in?__

Solving equations \(only symbolic\)

Integrals over functions

Derivatives of functions

Solving differential equations

__Numerical__  __ __  __solutions__  __ will \(__  __almost__  __\) __  __always__  __ __  __be__  __ __  __approximations__  __\! __

Precision is limited

Range is limited

Algorithm is approximating

Errors can accumulate dramatically \(stability of algorithms\)

__Examples__  __ __  __of__  __ __  __errors__  __:__

Multiplication\, one decimal place: 2\.5 \* 2\.5 = 6\.25

Addition\, 8\-bit unsigned int: 200\+200 = 400

Euler integration of ODE   <span style="color:#FF0000"> __\(__ </span>  <span style="color:#FF0000"> __ Whiteboard\)__ </span>

<span style="color:#0070C0"> __Integrals __ </span>  <span style="color:#0070C0"> __over__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __functions__ </span>  <span style="color:#0070C0"> __ \(‚__ </span>  <span style="color:#0070C0"> __quadrature__ </span>  <span style="color:#0070C0"> __‘\)__ </span>

![](img/T2_NumAnalysis-SymComp2.png)

__Numerical__  __ __  __methods__

Integral = area under curve

Approximate area by many small boxes\, e\.g\. by  _midpoint_  _ _  _rule_ :

![](img/T2_NumAnalysis-SymComp3.png)

![](img/T2_NumAnalysis-SymComp4.png)

_Trapezoidal_  _ _  _rule_  _: _

<span style="color:#FF0000"> __worse__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __than__ </span>  <span style="color:#FF0000"> __ __ </span>  <span style="color:#FF0000"> __midpoint__ </span>  <span style="color:#FF0000"> __\!__ </span>

![](img/T2_NumAnalysis-SymComp5.png)

approximate by parabolas

_Simpson‘s_  _ _  _rule_  _: _

__Numerical__  __ __  __methods__  __:__

![](img/T2_NumAnalysis-SymComp6.png)

__Symbolic__  __ __  __Methods__

We will use module  <span style="color:#0070C0"> __sympy__ </span> \.

For symbolic operations \(i\.e\.\, without concrete numbers\)\, we have to  __declare__  __ variables/__  __symbols__  \(and later functions…\)\.

For  __mathematical__  __ __  __functions__  __ such __  __as__  __ cos\(…\)__ \, use the sympy equivalents \(not from math or numpy modules\!\)

![](img/T2_NumAnalysis-SymComp7.png)

For  __definite __  __integrals__ \, we can specify boundaries a and b by  __creating__  __ a __  __tuple__   <span style="color:#0070C0"> __\(x\, a\, b\)__ </span>  for the second argument\.

The solution can be  __evaluated__  by using the methods  <span style="color:#0070C0"> __\.__ </span>  <span style="color:#0070C0"> __subs__ </span>  <span style="color:#0070C0"> __\(variable\, __ </span>  <span style="color:#0070C0"> __value__ </span>  <span style="color:#0070C0"> __\) __ </span> to substitute a value for a variable and  <span style="color:#0070C0"> __\.__ </span>  <span style="color:#0070C0"> __evalf__ </span>  <span style="color:#0070C0"> __\(\) __ </span> to get a numerical output\.

<span style="color:#0070C0"> __„Genug für heute?“__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/sympy/intro](https://davrot.github.io/pytutorial/sympy/intro/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/sympy/intro/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/numpy/7](https://davrot.github.io/pytutorial/numpy/7/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/numpy/7/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/numpy/8](https://davrot.github.io/pytutorial/numpy/8/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/numpy/8/)</span>

<span style="color:#FF0000"> __Example__ </span>  <span style="color:#FF0000"> __ live\-__ </span>  <span style="color:#FF0000"> __coding__ </span>  <span style="color:#FF0000"> __:__ </span>  <span style="color:#FF0000">integration</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">and</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">differentiation</span>  <span style="color:#FF0000">\, </span>  <span style="color:#FF0000">stability</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">and</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">instability</span>

<span style="color:#0070C0"> __Differentiation __ </span>  <span style="color:#0070C0"> __of__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __functions__ </span>

__Numerical__  __ __  __methods__  __:__

__centered__  __ __  __differentiation__

__right\-sided__  __ __  __differentiation__

![](img/T2_NumAnalysis-SymComp8.png)

---

Note: also important for integration of DEQs, since differential approximated by the same equations


__Symbolic__  __ __  __methods__  __:__

For differentiation\, the corresponding command is  <span style="color:#0070C0"> __diff__ </span> :

![](img/T2_NumAnalysis-SymComp9.png)

<span style="color:#0070C0"> __Integration __ </span>  <span style="color:#0070C0"> __of__ </span>  <span style="color:#0070C0"> __ differential __ </span>  <span style="color:#0070C0"> __equations__ </span>

__Differential __  __quotient__  __ __  __approximated__  __ __  __by__  __ finite __  __difference__ \, like in previous example\. Solution constructed by considering the following aspects:

What do we want to know\, what is known?

Where do we start?   __Initial __  __value__  __ __  __problem__ …

How far do we step?  Smaller than fastest timescale implies  __maximum__  __ __  __step__  __ __  __size__

<span style="color:#FF0000"> __Warning__ </span>  <span style="color:#FF0000"> __:__ </span>

<span style="color:#FF0000">differentiation</span>  <span style="color:#FF0000">/</span>  <span style="color:#FF0000">integration</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">of</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">functions</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">can</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">be</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">performed</span>  <span style="color:#FF0000"> in parallel\, </span>

<span style="color:#FF0000">differential </span>  <span style="color:#FF0000">equations</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">require</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">an iterative </span>  <span style="color:#FF0000">solution</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">which</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">can</span>  <span style="color:#FF0000"> not </span>  <span style="color:#FF0000">be</span>  <span style="color:#FF0000"> </span>  <span style="color:#FF0000">parallelized</span>  <span style="color:#FF0000">\!</span>

<span style="color:#0070C0"> __What__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __about__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __systems__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __of__ </span>  <span style="color:#0070C0"> __ differential __ </span>  <span style="color:#0070C0"> __equations__ </span>  <span style="color:#0070C0"> __?__ </span>

…just solve them in parallel \(see previous slide\)

__Higher\-order __  __methods__

Idea: approximate differential quotient more precisely…

__Solution \(Runge\-__  __Kutta__  __ 2nd __  __order__  __\):__

Go ahead with Euler by half of the stepsize…

…use slope at that position for an Euler with the full stepsize\.

__Numerical__  __ __  __methods__  __:__

![](img/T2_NumAnalysis-SymComp10.png)

![](img/T2_NumAnalysis-SymComp11.png)

__Symbolic__  __ __  __methods__  __:__

In addition to declaring variables\, you need…

…to  __declare__  __ __  __functions__  \(for the solution we are looking for\)

…to  __define__  __ __  __the__  __ \(differential\) __  __equation__

…and the  __command__  __ __  <span style="color:#0070C0"> __dsolve__ </span>  __ __ for \(trying to\) solve the DEQ:

![](img/T2_NumAnalysis-SymComp12.png)

__Symbolic__  __ __  __methods__  __\, __  __cont‘d__  __…__

For including initial conditions\,  <span style="color:#0070C0"> __dsolve__ </span>  <span style="color:#0070C0"> __ __ </span> has the  __optional __  __argument__  __ __  <span style="color:#0070C0"> __ics__ </span> \.

With <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __lambdify__ </span> \, You can  __convert__  __ __  __the__  __ RHS __  __of__  __ __  __the__  __ __  __solution__  __ __  __to__  __ a normal __  __numpy__  __ __  __function__ :

Query the new function as to  __which__  __ __  __arguments__  __ __  __it__  __ __  __takes__ \, and in which order \( <span style="color:#0070C0"> __import__ </span>  <span style="color:#0070C0"> __ __ </span>  <span style="color:#0070C0"> __inspect__ </span>  <span style="color:#0070C0"> __ __ </span> for that purpose\)

![](img/T2_NumAnalysis-SymComp13.png)

__What__  __ __  __about__  __ partial differential __  __equations__  __?__

For example\, the cable equation:

![](img/T2_NumAnalysis-SymComp14.png)

<span style="color:#0070C0"> __More __ </span>  <span style="color:#0070C0"> __information__ </span>  <span style="color:#0070C0"> __:__ </span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/sympy/intro](https://davrot.github.io/pytutorial/sympy/intro/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/sympy/intro/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/numpy/7](https://davrot.github.io/pytutorial/numpy/7/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/numpy/7/)</span>

<span style="color:#000000">[https://davrot\.github\.io/pytutorial/numpy/8](https://davrot.github.io/pytutorial/numpy/8/)</span>  <span style="color:#000000">[/](https://davrot.github.io/pytutorial/numpy/8/)</span>

