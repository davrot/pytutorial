
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

        a_endless = np.power(
            (
                (0.0761 * np.exp(0.0314 * (v + 94.22)))
                / (1 + np.exp(0.0346 * (v + 1.17)))
            ),
            1 / 3,
        )
        
$$b_\infty(V) = \left(\frac{1}{1 + \exp(0.0688mV^{-1} (V + 53.3mV))} \right)^4$$
  
$$n_\infty(V) = \alpha_n(V) * \tau_n(V)$$

$$m_\infty(V) = \alpha_m(V) * \tau_m(V)$$

$$h_\infty(V) = \alpha_h(V) * \tau_h(V)$$
