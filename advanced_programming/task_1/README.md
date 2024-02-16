# Classycal neurons: Simulation and Mathematical Anaylsis

Simulating neurons is an ideal project for training systematic programming. Classes can be used to implement a hierarchy of different neuron models. Inheritance can be used to recycle common code for neurons that only minimally differ from each other. Methods can be defined for all the actions you can perform on neurons. In addition, this project will help you to train using type annotations and to organize your code into meaningful blocks or modules. Since some of the neuron models are mathematically sufficiently simple, we can use symbolic computation in parallel to validate numerical results and vice versa. Finally, for integrating more complex (systems of) differential equations, you can now get rid of poor old Euler and incorporate more sophisticated solvers such as Runge Kutta schemes.

**Trained concepts in this project: type annotations, classes, symbolic computation, modularization, numerical analysis, error handling and debugging**

## Mandatory tasks


1. Goal of this project is to compare different neuron models. Think about how you would organize those models in a hierarchy of Python classes. Which attributes and methods would you like to define for those classes? The neurons you have to cover are the leaky integrate-and-fire neuron (LIAF), quadratic integrate-and-fire neuron (QIAF), the conductance-based Connor-Stevens neuron, exponential integrate-and-fire neuron (EIAF), and a rate-based MT neuron (DivInE model). **We will ask some of you to present your thoughts on this task before you are going to implement the class hierarchy.**
2. Implement and test your neuron models by driving them with a constant input current $I$. Plot their membrane potentials or outputs over time. For integrating the DEQs, you can use the standard Euler scheme with appropriately chosen step width $\Delta t$.
3. Compute the neurons's gain functions $g$ as the average firing rate $r=g(I)$ numerically (for the MT neuron: in a suitable interval from $[0, T]$). For the LIAF neuron, compute the gain function also with sympy and plot it in comparison to the numerical curve.
4. Replace the Euler scheme for the Connor-Stevens neuron by the Python solver implementing the adaptive Runge-Kutta 4th/5th order scheme. Compare it with the Euler scheme. How small do you have to choose $\Delta t$ to obtain approximately the same precision as with Runge-Kutta?
5. Determine whether the neuron models are of **type-I** or **type-II** (see the ['Neuronal Dynamics' textbook](https://neuronaldynamics.epfl.ch), if you do not know what this means) by assessing the slope of the gain curve you obtained numerically. 

## Voluntary tasks: Neurons...

1. For fluffing up your class hierarchy, you can add the original Hodgkin-Huxley model, and/or you can add adaptation to the Connor-Stevens model and the Exponential integrate-and-fire neuron.
2. Compute the gain functions with sympy also for the QIAF neuron and the MT neuron, and plot them in comparison to the numerical curves. Note that you have to use commensurable time constants for the MT neuron to be able to solve the differential equations analytically.
3. Extend your class(es) such that you can drive your neurons with a time-varying current $I(t)$.

## Voluntary tasks: ...and cables

Neurons collect incoming signals on their dendritic tree and conduct the corresponding electric currents towards the soma. Passive conduction is described by the (passive) cable partial differential equation for the voltage $V(t, x)$, which in its normalized form reads
$$\frac{\partial V(t, x)}{\partial t} = a \frac{\partial^2 V(t, x)}{\partial x^2} + b V(t, x) + I_{ext}(t, x)$$
with parameters $a>0$, $b<0$, and external current $I_{ext}(t, x)$.

In this task, you can implement numerical schemes for solving the cable equation, and use a model neuron to provide input.

1. Approximate the temporal and spatial derivatives by finite differences with respect to a discretization $\Delta t$ and $\Delta x$ in time and space. Write down the forward Euler scheme for solving the partial differential equation using these expressions.
2. Implement a numerical integration routine for the passive cable in Python. Take care at the boundaries! We will use sealed ends, i.e. require that the current flowing through the ends of your cable is zero.
3. Test your cable with $a=1$ and $b=-1$: Give it a length $L=1$, and discretise it into $100$ segments.
4. Give an external current pulse at $t=0$ and $x_0=0.1$, and observe how the voltage profile changes over time for an interval of $T=0.1$ (you could show this in an animated graph). Theory tells us that numerical stability requires $\Delta t < 0.5 \Delta x^2$.
5. Plot the time courses of the membrane potential at different distances $x$ from $x_0$ into the same graph. If you would be a brain-'designer', where would you place a synapse that should have a large impact on the postsynaptic cell?
6. Create the same plot, but now provide input pulses with a frequency of 10 per time unit, for $T=1$, and set $b=-100$.
7. Numerical stability: Observe what happens if the condition on $\Delta t$ stated above does not hold. To circumvent those problems, you can use much larger time steps if you implement the **Crank-Nicholson** algorithm for integrating the cable equation (have a look at Wikipedia for [Crank-Nicolson](https://en.wikipedia.org/wiki/Crank%E2%80%93Nicolson_method) and the [Thomas-algorithm](https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm); they can be implemented with a few more lines of code).
8. Experiment with your cable: connect one end to your Connor-Stevens neuron, drive the neuron with a constant supra-threshold input current, and observe how the generated spikes propagate over the dendrite. You can also couple a 'receiving' neuron to the end of the cable.
9. How about wrapping your cable into a class? Can you find a Python module which provides an alternative integration scheme for this PDE such as **py-pde**?

