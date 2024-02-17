# Python class with and without classes 

**Programming has to be practiced, it can not be learned from looking at slides alone. Here we give you some simple tasks to implement in Python, which add up to a mini-simulation of synaptic transmission in the end. We structured this exercise such that you can start with simple tasks and add complexity with each additional concept you learn in our lectures.**


## Task 0. Get ready to create Python programs

### a.
[You need a Python with some of the basic packages](https://davrot.github.io/pytutorial/workflow/python_pure/)

### b.
You need a good editor that is compatible with Python! Many people in the world are using VS Code. You can use what you want but don't come to us with tears in your eyes if you use something else.

* [How to install the VS code editor](https://davrot.github.io/pytutorial/workflow/vscode_install/)
* [How to configure the editor for your needs](https://davrot.github.io/pytutorial/workflow/vscode_config/)
* [Working with VS code](https://davrot.github.io/pytutorial/workflow/vscode_interactive/)
* [Collection of general tips](https://davrot.github.io/pytutorial/workflow/microsoft_tutorials/)

Arrival of an action potential at the presynaptic terminal leads to the release of vesicles. Neurotransmitters drift through the synaptic cleft and induce input currents when arriving at the postsynaptic bouton on the dendrite. We will simulate this process in Python:

## Task 1. Variables, Functions, Plotting
The postsynaptic current may be described by a function $PSP(t) = at\exp(-t/b)$ depending on time $t$.
* Plot this function over time for different parameters $a$, $b$ and annotate the axes properly.
* Define a Python function \py{PSP} with default parameters $a$, $b$ which computes and returns $PSP(t)$.

## Task 2. Loops, Conditional Execution, Flow Control
Transport of neurotransmitter from the release site $A$ to the destination $B$ can be simulated by a one-dimensional random walk of particles described by the following rules:


* $n$ particles are released at time $t=0$.
* There are $k$ steps from $A$ to $B$.
* In each time step $t \rightarrow t+1$, each particle moves either one step forward or one step backward, with equal probability.
* Particles at $A$ can only move forward with probability $0.5$.
* Particles arriving at $B$ are absorbed.

For each particle, compute the time it takes until it arrives at $B$. Compute and print the average number of time steps passed until arrival. Count the fractions of particles $h$ arriving at times $t$, and plot the resulting histogram $h(t)$ into a graph with proper annotation. 


## Task 3. Some more plots \& functions

The postsynaptic current is proportional to the amount of neurotransmitter arriving at the postsynaptic terminal.

* Plot $h(t)$ and $PSP(t)$ into the same graph and adjust the parameters $a$, $b$ by hand until you obtain a good fit, use a legend to distinguish the two curves.
* Quantify the fit error by computing the mean quadratic distance $QD(h, PSP) = 1/T \sum_t (h(t)-PSP(t))^2$ between the two curves.
* Define a Python function \py{mqdis} for computing $QD$.

## Task 4. Some more flow control

Fitting by hand is stupid, we have computers for that! Devise a procedure that minimizes $QD$ by adjusting the parameters $a$ and $b$ of the fitting function.

One idea is to start with two initial, positive parameters $a=a_0$ and $b=b_0$ and perform an iterative optimization by repeating the following steps: 

* Compute two new parameters by randomly increasing or decreasing $a$ and $b$ by a small percentage.
* Keep the new parameters if they provide a better fit, otherwise continue with the old parameters.

Implement this fitting procedure in Python and find the parameters $a$, $b$ that best describe your random walk.

## Task 5. Modules 
Put your functions **mqdis** and **psp** into one module, and add a third function which contains your code for simulating the random walk. Put all the plotting stuff of Tasks \#1 to \#3 into a test code section which is only executed when the module is executed as a script.

Modify your code for Task \#4 such that it uses the functions imported from your new module.

## Task 6. Towards classes

Construct an \py{upper}-class which you can use to study random walks, and populate this class with internal variables and methods. Here are some ideas how you might do it:

* The **\_\_init\_\_**-method sets the parameter $k$ for a specific random walk.
* Method **sim(n)** simulates $n$ (additional) particles and stores (adds) their durations (to the existing data).
* Method **avg()** returns the average drift time.
* Method **fit(f, a\_init, b\_init)** performs a fit of an arbitrary function **f** depending on two parameters to the drift time statistics collected so far.



