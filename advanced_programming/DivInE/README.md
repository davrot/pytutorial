# **DivInE**-model for MT neurons

This model is also termed **DivInE**-model, since it describes the adaptive response properties of MT neurons by means of divisive normalization, for more detailed info see also [this paper](https://journals.plos.org/ploscompbiol/article?id=10.1371/journal.pcbi.1009595):

$$\tau_e \frac{dA_e(t)}{dt} = -A_e(t) + g_e\left( \frac{I(t)}{A_i(t)+\sigma} \right)$$

$$\tau_i \frac{dA_i(t)}{dt} = -A_i(t) + g_i\left( I(t) \right)$$

Here, $g_X$ are gain functions for $x\in\{e,i\}$ with $g_X(I) = m_X(I-\theta_X)$ for $I>\theta_X$, and $0$ otherwise, while $A_e$ and $A_i$ could be interpreted as internal activations.
Default parameters: $\tau_e=10$ ms, $\tau_i=40$ ms, $\theta_{\{e,i\}}=0$, $m_e=m_i=1$ (nA)${}^{-1}$, $I=1$ nA, $\sigma=0.25$. From the activation $A_e$, an output rate can be derived via $r(t) = r_0 A_e(t)$ with, let's say, $r_0=100$ Hz.
