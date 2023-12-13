# [Mathematical functions](https://numpy.org/doc/stable/reference/routines.math.html)


**I will focus on the important ones. Those will get a link.** 

## [Trigonometric functions](https://numpy.org/doc/stable/reference/routines.math.html#trigonometric-functions)

|||
|---|---|
|[sin](https://numpy.org/doc/stable/reference/generated/numpy.sin.html#numpy.sin)(x, /[, out, where, casting, order, ...])|Trigonometric sine, element-wise.|
|[cos](https://numpy.org/doc/stable/reference/generated/numpy.cos.html#numpy.cos)(x, /[, out, where, casting, order, ...])|Cosine element-wise.|
|[tan](https://numpy.org/doc/stable/reference/generated/numpy.tan.html#numpy.tan)(x, /[, out, where, casting, order, ...])|Compute tangent element-wise.|
|[arcsin](https://numpy.org/doc/stable/reference/generated/numpy.arcsin.html#numpy.arcsin)(x, /[, out, where, casting, order, ...])|Inverse sine, element-wise.|
|[arccos](https://numpy.org/doc/stable/reference/generated/numpy.arccos.html#numpy.arccos)(x, /[, out, where, casting, order, ...])|Trigonometric inverse cosine, element-wise.|
|arctan(x, /[, out, where, casting, order, ...])|Trigonometric inverse tangent, element-wise.|
|hypot(x1, x2, /[, out, where, casting, ...])|Given the "legs" of a right triangle, return its hypotenuse.|
|[arctan2](https://numpy.org/doc/stable/reference/generated/numpy.arctan2.html#numpy.arctan2)(x1, x2, /[, out, where, casting, ...])|Element-wise arc tangent of x1/x2 choosing the quadrant correctly.|
|degrees(x, /[, out, where, casting, order, ...])|Convert angles from radians to degrees.|
|radians(x, /[, out, where, casting, order, ...])|Convert angles from degrees to radians.|
|unwrap(p[, discont, axis, period])|Unwrap by taking the complement of large deltas with respect to the period.|
|deg2rad(x, /[, out, where, casting, order, ...])|Convert angles from degrees to radians.|
|rad2deg(x, /[, out, where, casting, order, ...])|Convert angles from radians to degrees.|

## [Hyperbolic functions](https://numpy.org/doc/stable/reference/routines.math.html#hyperbolic-functions)

|||
|---|---|
|sinh(x, /[, out, where, casting, order, ...]) |Hyperbolic sine, element-wise.|
|cosh(x, /[, out, where, casting, order, ...]) |Hyperbolic cosine, element-wise.|
|tanh(x, /[, out, where, casting, order, ...]) |Compute hyperbolic tangent element-wise.|
|arcsinh(x, /[, out, where, casting, order, ...]) |Inverse hyperbolic sine element-wise.|
|arccosh(x, /[, out, where, casting, order, ...]) |Inverse hyperbolic cosine, element-wise.|
|arctanh(x, /[, out, where, casting, order, ...]) |Inverse hyperbolic tangent element-wise.|

## [Rounding](https://numpy.org/doc/stable/reference/routines.math.html#rounding)

|||
|---|---|
|[round](https://numpy.org/doc/stable/reference/generated/numpy.round.html#numpy.round)(a[, decimals, out])|Evenly round to the given number of decimals.|
|[around](https://numpy.org/doc/stable/reference/generated/numpy.around.html#numpy.around)(a[, decimals, out])|Round an array to the given number of decimals.|
|[rint](https://numpy.org/doc/stable/reference/generated/numpy.rint.html#numpy.rint)(x, /[, out, where, casting, order, ...])|Round elements of the array to the nearest integer.|
|[fix](https://numpy.org/doc/stable/reference/generated/numpy.fix.html#numpy.fix)(x[, out])|Round to nearest integer towards zero.|
|[floor](https://numpy.org/doc/stable/reference/generated/numpy.floor.html#numpy.floor)(x, /[, out, where, casting, order, ...])|Return the floor of the input, element-wise.|
|[ceil](https://numpy.org/doc/stable/reference/generated/numpy.ceil.html#numpy.ceil)(x, /[, out, where, casting, order, ...])|Return the ceiling of the input, element-wise.|
|[trunc](https://numpy.org/doc/stable/reference/generated/numpy.trunc.html#numpy.trunc)(x, /[, out, where, casting, order, ...])|Return the truncated value of the input, element-wise.|

## [Sums, products, differences](https://numpy.org/doc/stable/reference/routines.math.html#sums-products-differences)


|||
|---|---|
|[prod](https://numpy.org/doc/stable/reference/generated/numpy.prod.html#numpy.prod)(a[, axis, dtype, out, keepdims, ...]) |Return the product of array elements over a given axis.|
|[sum](https://numpy.org/doc/stable/reference/generated/numpy.sum.html#numpy.sum)(a[, axis, dtype, out, keepdims, ...])|Sum of array elements over a given axis.|
|[nanprod](https://numpy.org/doc/stable/reference/generated/numpy.nanprod.html#numpy.nanprod)(a[, axis, dtype, out, keepdims, ...])|Return the product of array elements over a given axis treating Not a Numbers (NaNs) as ones.|
|[nansum](https://numpy.org/doc/stable/reference/generated/numpy.nansum.html#numpy.nansum)(a[, axis, dtype, out, keepdims, ...])|Return the sum of array elements over a given axis treating Not a Numbers (NaNs) as zero.|
|[cumprod](https://numpy.org/doc/stable/reference/generated/numpy.cumprod.html#numpy.cumprod)(a[, axis, dtype, out])|Return the cumulative product of elements along a given axis.|
|[cumsum](https://numpy.org/doc/stable/reference/generated/numpy.cumsum.html#numpy.cumsum)(a[, axis, dtype, out])|Return the cumulative sum of the elements along a given axis.|
|[nancumprod](https://numpy.org/doc/stable/reference/generated/numpy.nancumprod.html#numpy.nancumprod)(a[, axis, dtype, out])|Return the cumulative product of array elements over a given axis treating Not a Numbers (NaNs) as one.|
|[nancumsum](https://numpy.org/doc/stable/reference/generated/numpy.nancumsum.html#numpy.nancumsum)(a[, axis, dtype, out])|Return the cumulative sum of array elements over a given axis treating Not a Numbers (NaNs) as zero.|
|[diff](https://numpy.org/doc/stable/reference/generated/numpy.diff.html#numpy.diff)(a[, n, axis, prepend, append])|Calculate the n-th discrete difference along the given axis.|
|ediff1d(ary[, to_end, to_begin])|The differences between consecutive elements of an array.|
|gradient(f, *varargs[, axis, edge_order])|Return the gradient of an N-dimensional array.|
|[cross](https://numpy.org/doc/stable/reference/generated/numpy.cross.html#numpy.cross)(a, b[, axisa, axisb, axisc, axis])|Return the cross product of two (arrays of) vectors.|
|trapz(y[, x, dx, axis])|Integrate along the given axis using the composite trapezoidal rule.|

## [Exponents and logarithms](https://numpy.org/doc/stable/reference/routines.math.html#exponents-and-logarithms)

|||
|---|---|
|[exp](https://numpy.org/doc/stable/reference/generated/numpy.exp.html#numpy.exp)(x, /[, out, where, casting, order, ...])|Calculate the exponential of all elements in the input array.|
|[expm1](https://numpy.org/doc/stable/reference/generated/numpy.expm1.html#numpy.expm1)(x, /[, out, where, casting, order, ...])|Calculate exp(x) - 1 for all elements in the array.|
|[exp2](https://numpy.org/doc/stable/reference/generated/numpy.exp2.html#numpy.exp2)(x, /[, out, where, casting, order, ...])|Calculate 2**p for all p in the input array.|
|[log](https://numpy.org/doc/stable/reference/generated/numpy.log.html#numpy.log)(x, /[, out, where, casting, order, ...])|Natural logarithm, element-wise.|
|[log10](https://numpy.org/doc/stable/reference/generated/numpy.log10.html#numpy.log10)(x, /[, out, where, casting, order, ...])|Return the base 10 logarithm of the input array, element-wise.|
|[log2](https://numpy.org/doc/stable/reference/generated/numpy.log2.html#numpy.log2)(x, /[, out, where, casting, order, ...])|Base-2 logarithm of x.|
|[log1p](https://numpy.org/doc/stable/reference/generated/numpy.log1p.html#numpy.log1p)(x, /[, out, where, casting, order, ...])|Return the natural logarithm of one plus the input array, element-wise.|
|[logaddexp](https://numpy.org/doc/stable/reference/generated/numpy.logaddexp.html#numpy.logaddexp)(x1, x2, /[, out, where, casting, ...])|Logarithm of the sum of exponentiations of the inputs.|
|[logaddexp2](https://numpy.org/doc/stable/reference/generated/numpy.logaddexp2.html#numpy.logaddexp2)(x1, x2, /[, out, where, casting, ...])|Logarithm of the sum of exponentiations of the inputs in base-2.|

## [Other special functions](https://numpy.org/doc/stable/reference/routines.math.html#other-special-functions)

|||
|---|---|
|i0(x)|Modified Bessel function of the first kind, order 0.|
|sinc(x)|Return the normalized sinc function.|

## [Floating point routines](https://numpy.org/doc/stable/reference/routines.math.html#floating-point-routines)

|||
|---|---|
|signbit(x, /[, out, where, casting, order, ...])|Returns element-wise True where signbit is set (less than zero).|
|copysign(x1, x2, /[, out, where, casting, ...])|Change the sign of x1 to that of x2, element-wise.|
|frexp(x[, out1, out2], / [[, out, where, ...])|Decompose the elements of x into mantissa and twos exponent.|
|ldexp(x1, x2, /[, out, where, casting, ...])|Returns x1 * 2**x2, element-wise.|
|nextafter(x1, x2, /[, out, where, casting, ...])|Return the next floating-point value after x1 towards x2, element-wise.|
|spacing(x, /[, out, where, casting, order, ...])|Return the distance between x and the nearest adjacent number.|

## [Rational routines](https://numpy.org/doc/stable/reference/routines.math.html#rational-routines)

|||
|---|---|
|lcm(x1, x2, /[, out, where, casting, order, ...])|Returns the lowest common multiple of \|x1\| and \|x2\||
|gcd(x1, x2, /[, out, where, casting, order, ...])|Returns the greatest common divisor of \|x1\| and \|x2\||


## [Arithmetic operations](https://numpy.org/doc/stable/reference/routines.math.html#arithmetic-operations)

|||
|---|---|
|[add](https://numpy.org/doc/stable/reference/generated/numpy.add.html#numpy.add)(x1, x2, /[, out, where, casting, order, ...])|Add arguments element-wise.|
|[reciprocal](https://numpy.org/doc/stable/reference/generated/numpy.reciprocal.html#numpy.reciprocal)(x, /[, out, where, casting, ...])|Return the reciprocal of the argument, element-wise.|
|positive(x, /[, out, where, casting, order, ...])|Numerical positive, element-wise.|
|negative(x, /[, out, where, casting, order, ...])|Numerical negative, element-wise.|
|[multiply](https://numpy.org/doc/stable/reference/generated/numpy.multiply.html#numpy.multiply)(x1, x2, /[, out, where, casting, ...])|Multiply arguments element-wise.|
|[divide](https://numpy.org/doc/stable/reference/generated/numpy.divide.html#numpy.divide)(x1, x2, /[, out, where, casting, ...])|Divide arguments element-wise.|
|[power](https://numpy.org/doc/stable/reference/generated/numpy.power.html#numpy.power)(x1, x2, /[, out, where, casting, ...])|First array elements raised to powers from second array, element-wise.|
|[subtract](https://numpy.org/doc/stable/reference/generated/numpy.subtract.html#numpy.subtract)(x1, x2, /[, out, where, casting, ...])|Subtract arguments, element-wise.|
|[true_divide](https://numpy.org/doc/stable/reference/generated/numpy.true_divide.html#numpy.true_divide)(x1, x2, /[, out, where, ...])|Divide arguments element-wise.|
|[floor_divide](https://numpy.org/doc/stable/reference/generated/numpy.floor_divide.html#numpy.floor_divide)(x1, x2, /[, out, where, ...])|Return the largest integer smaller or equal to the division of the inputs.|
|[float_power](https://numpy.org/doc/stable/reference/generated/numpy.float_power.html#numpy.float_power)(x1, x2, /[, out, where, ...])|First array elements raised to powers from second array, element-wise.|
|[fmod](https://numpy.org/doc/stable/reference/generated/numpy.fmod.html#numpy.fmod)(x1, x2, /[, out, where, casting, ...])|Returns the element-wise remainder of division.|
|[mod](https://numpy.org/doc/stable/reference/generated/numpy.mod.html#numpy.mod)(x1, x2, /[, out, where, casting, order, ...])|Returns the element-wise remainder of division.|
|[modf](https://numpy.org/doc/stable/reference/generated/numpy.modf.html#numpy.modf)(x[, out1, out2], / [[, out, where, ...])|Return the fractional and integral parts of an array, element-wise.|
|[remainder](https://numpy.org/doc/stable/reference/generated/numpy.remainder.html#numpy.remainder)(x1, x2, /[, out, where, casting, ...])|Returns the element-wise remainder of division.|
|[divmod](https://numpy.org/doc/stable/reference/generated/numpy.divmod.html#numpy.divmod)(x1, x2[, out1, out2], / [[, out, ...])|Return element-wise quotient and remainder simultaneously.|

## [Handling complex numbers](https://numpy.org/doc/stable/reference/routines.math.html#handling-complex-numbers)

|||
|---|---|
|[angle](https://numpy.org/doc/stable/reference/generated/numpy.angle.html#numpy.angle)(z[, deg]) |Return the angle of the complex argument.|
|[real](https://numpy.org/doc/stable/reference/generated/numpy.real.html#numpy.real)(val) |Return the real part of the complex argument.|
|[imag](https://numpy.org/doc/stable/reference/generated/numpy.imag.html#numpy.imag)(val) |Return the imaginary part of the complex argument.|
|[conj](https://numpy.org/doc/stable/reference/generated/numpy.conj.html#numpy.conj)(x, /[, out, where, casting, order, ...]) |Return the complex conjugate, element-wise.|
|[conjugate](https://numpy.org/doc/stable/reference/generated/numpy.conjugate.html#numpy.conjugate)(x, /[, out, where, casting, ...]) |Return the complex conjugate, element-wise.|


## [Extrema Finding](https://numpy.org/doc/stable/reference/routines.math.html#extrema-finding)

|||
|---|---|
|[maximum](https://numpy.org/doc/stable/reference/generated/numpy.maximum.html#numpy.maximum)(x1, x2, /[, out, where, casting, ...]) |Element-wise maximum of array elements.|
|[max](https://numpy.org/doc/stable/reference/generated/numpy.max.html#numpy.max)(a[, axis, out, keepdims, initial, where])|Return the maximum of an array or maximum along an axis.|
|[amax](https://numpy.org/doc/stable/reference/generated/numpy.amax.html#numpy.amax)(a[, axis, out, keepdims, initial, where])|Return the maximum of an array or maximum along an axis.|
|[fmax](https://numpy.org/doc/stable/reference/generated/numpy.fmax.html#numpy.fmax)(x1, x2, /[, out, where, casting, ...])|Element-wise maximum of array elements.|
|[nanmax](https://numpy.org/doc/stable/reference/generated/numpy.nanmax.html#numpy.nanmax)(a[, axis, out, keepdims, initial, where])|Return the maximum of an array or maximum along an axis, ignoring any NaNs.|
|[minimum](https://numpy.org/doc/stable/reference/generated/numpy.minimum.html#numpy.minimum)(x1, x2, /[, out, where, casting, ...])|Element-wise minimum of array elements.|
|[min](https://numpy.org/doc/stable/reference/generated/numpy.min.html#numpy.min)(a[, axis, out, keepdims, initial, where])|Return the minimum of an array or minimum along an axis.|
|[amin](https://numpy.org/doc/stable/reference/generated/numpy.amin.html#numpy.amin)(a[, axis, out, keepdims, initial, where])|Return the minimum of an array or minimum along an axis.|
|[fmin](https://numpy.org/doc/stable/reference/generated/numpy.fmin.html#numpy.fmin)(x1, x2, /[, out, where, casting, ...])|Element-wise minimum of array elements.|
|[nanmin](https://numpy.org/doc/stable/reference/generated/numpy.nanmin.html#numpy.nanmin)(a[, axis, out, keepdims, initial, where])|Return minimum of an array or minimum along an axis, ignoring any NaNs.|

## [Miscellaneous](https://numpy.org/doc/stable/reference/routines.math.html#miscellaneous)

|||
|---|---|
|[convolve](https://numpy.org/doc/stable/reference/generated/numpy.convolve.html#numpy.convolve)(a, v[, mode])|Returns the discrete, linear convolution of two one-dimensional sequences.|
|[clip](https://numpy.org/doc/stable/reference/generated/numpy.clip.html#numpy.clip)(a, a_min, a_max[, out])|Clip (limit) the values in an array.|
|[sqrt](https://numpy.org/doc/stable/reference/generated/numpy.sqrt.html#numpy.sqrt)(x, /[, out, where, casting, order, ...])|Return the non-negative square-root of an array, element-wise.|
|[cbrt](https://numpy.org/doc/stable/reference/generated/numpy.cbrt.html#numpy.cbrt)(x, /[, out, where, casting, order, ...])|Return the cube-root of an array, element-wise.|
|[square](https://numpy.org/doc/stable/reference/generated/numpy.square.html#numpy.square)(x, /[, out, where, casting, order, ...])|Return the element-wise square of the input.|
|[absolute](https://numpy.org/doc/stable/reference/generated/numpy.absolute.html#numpy.absolute)(x, /[, out, where, casting, order, ...])|Calculate the absolute value element-wise.|
|[fabs](https://numpy.org/doc/stable/reference/generated/numpy.fabs.html#numpy.fabs)(x, /[, out, where, casting, order, ...])|Compute the absolute values element-wise.|
|[sign](https://numpy.org/doc/stable/reference/generated/numpy.sign.html#numpy.sign)(x, /[, out, where, casting, order, ...])|Returns an element-wise indication of the sign of a number.|
|[heaviside](https://numpy.org/doc/stable/reference/generated/numpy.heaviside.html#numpy.heaviside)(x1, x2, /[, out, where, casting, ...])|Compute the Heaviside step function.|
|[nan_to_num](https://numpy.org/doc/stable/reference/generated/numpy.nan_to_num.html#numpy.nan_to_num)(x[, copy, nan, posinf, neginf])|Replace NaN with zero and infinity with large finite numbers (default behaviour) or with the numbers defined by the user using the nan, posinf and/or neginf keywords.|
|[real_if_close](https://numpy.org/doc/stable/reference/generated/numpy.real_if_close.html#numpy.real_if_close)(a[, tol])|If input is complex with all imaginary parts close to zero, return real parts.|
|[interp](https://numpy.org/doc/stable/reference/generated/numpy.interp.html#numpy.interp)(x, xp, fp[, left, right, period])|One-dimensional linear interpolation for monotonically increasing sample points.|
