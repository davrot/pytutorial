
## Main equations

$$c_m \frac{d V}{dt} = -i_m + \frac{I_e}{A}$$

$$t_m(V) \frac{d m}{dt} = m_{\infty}(V) - m$$

$$t_h(V) \frac{d h}{dt} = h_{\infty}(V) - h$$

$$t_n(V) \frac{d n}{dt} = n_{\infty}(V) - n$$

$$t_a(V) \frac{d a}{dt} = a_{\infty}(V) - a$$

$$t_b(V) \frac{d b}{dt} = b_{\infty}(V) - b$$


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

## Transient Ca2+ Conductance

$$M_{\infty} = \frac{1}{1+ \exp(-(V+57mV) / 6.2mV)}$$

$$H_{\infty} = \frac{1}{1+ \exp(-(V+81mV) / 4mV)}$$

$$\tau_M = 0.612 ms + \frac{1ms}{\exp(-(V+132mV)/16.7 mV) + \exp((V+16.8mV)/18.2 mV)}$$

if $V < -80 mV$:

$$\tau_H = 1ms \exp((V+467mV)/66.6mV)$$

else:

$$\tau_H = 28ms + 1ms \exp(-(V+22mV)/10.5mV)$$

## Ca2+- depentdent K+ Conducatance

$$c_\infty = \left( \frac{[Ca^{2+}]}{[Ca^{2+}] + 3 \mu M} \right) \frac{1}{1+\exp(-V+28.3mV)/12.6mV}$$

$$\tau_C = 90.3ms - \frac{75.1ms}{1+\exp(-V+46mV)/22.7mV}$$

