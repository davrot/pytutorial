
## alpha-values
$$alpha_n = (0.02 * (v + 45.7)) / (1 - np.exp(-0.1 * (v + 45.7)))$$

$$alpha_m = (0.38 * (v + 29.7)) / (1 - np.exp(-0.1 * (v + 29.7)))$$

$$alpha_h = 0.266 * np.exp(-0.05 * (v + 48.0))$$

## beta-values
$$beta_n = 0.25 * np.exp(-0.0125 * (v + 55.7))$$

$$beta_m = 15.2 * np.exp(-0.0556 * (v + 54.7))$$

$$beta_h = 3.8 / (1 + np.exp(-0.1 * (v + 18)))$$

## time constants
$$tau_n = 1.0 / (alpha_n + beta_n)$$

$$tau_m = 1.0 / (alpha_m + beta_m)$$

$$tau_h = 1.0 / (alpha_h + beta_h)$$

$$tau_a = 0.3632 + 1.158 / (1.0 + np.exp(0.0497 * (v + 55.96)))$$

$$tau_b = 1.24 + 2.678 / (1.0 + np.exp(0.0624 * (v + 50.0)))$$


