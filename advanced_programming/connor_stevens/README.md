
## Main equations
$$i_m =\bar{g}_L (V - E_L) + \bar{g}_{Na} m^3 h (V - E_{Na}) + \bar{g}_{K} n^4 (V - E_{K}) + \bar{g}_{A} a^3 b (V-E_A)$$


## alpha-values
$$\alpha_n(V) = \frac{0.02mV^{-1} (V + 45.7mV)}{1 - \exp(-0.1mV^{-1} (V + 45.7mV))}$$

$$\alpha_m(V) = \frac{0.38mV^{-1} (V + 29.7mV)}{1 - \exp(-0.1mV^{-1} (V + 29.7mV))}$$

$$\alpha_h(V) = 0.266 \exp(-0.05mV^{-1} (V + 48.0mV))$$

## beta-values
$$\beta_n(V) = 0.25 \exp(-0.0125mV^{-1} (V + 55.7mV))$$

$$\beta_m(V) = 15.2 \exp(-0.0556mV^{-1} (V + 54.7mV))$$

$$\beta_h(V) = \frac{3.8}{1 + \exp(-0.1mV^{-1} (V + 18mV))}$$

## time constants
$$\tau_n(V) = \frac{1.0ms}{\alpha_n(V) + \beta_n(V)}$$

$$\tau_m(V) = \frac{1.0ms}{\alpha_m(V) + \beta_m(V)}$$

$$\tau_h(V) = \frac{1.0ms}{\alpha_h(V) + \beta_h(V)}$$

$$\tau_a(V) = 0.3632ms + \frac{1.158ms}{1.0 + \exp(0.0497mV^{-1} (V + 55.96mV))}$$

$$\tau_b(V) = 1.24ms + \frac{2.678ms}{1.0 + \exp(0.0624mV^{-1} (V + 50.0mV))}$$

## asymptotic values

$$a_\infty(V) = \left( \frac{0.0761 * \exp(0.0314mV^{-1} (V + 94.22mV))}{1 + \exp(0.0346mV^{-1} (V + 1.17mV))}) \right)^{1 / 3} ms$$
        
$$b_\infty(V) = \left(\frac{1}{1 + \exp(0.0688mV^{-1} (V + 53.3mV))} \right)^4 ms$$
  
$$n_\infty(V) = \alpha_n(V) \tau_n(V)$$

$$m_\infty(V) = \alpha_m(V) \tau_m(V)$$

$$h_\infty(V) = \alpha_h(V) \tau_h(V)$$

## Suitable initial conditions

$$m(t=0) = 0.010$$

$$n(t=0) = 0.156$$

$$h(t=0) = 0.966$$

$$a(t=0) = 0.540$$

$$b(t=0) = 0.289$$

$$V(t=0) = -68.0 mV$$

## Parameter

$$c_m = 0.1 \frac{\mu F}{mm^2}$$

$$\frac{I_e}{A} = 0.35 \frac{\mu A}{mm^2}$$

$$\bar{g}_L = 0.003  \frac{mS}{mm^2}$$

$$\bar{g}_{Na} = 1.2 \frac{mS}{mm^2}$$

$$\bar{g}_{K} =  0.2 \frac{mS}{mm^2}$$

$$\bar{g}_{A} =  0.477 \frac{mS}{mm^2}$$

$$E_L = -17.0 mV$$

$$E_{Na} = 55.0 mV$$

$$E_K = -72.0 mV$$

$$E_A = -75.0 mV$$

