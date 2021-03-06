.. _arb-hypgeom:

**arb_hypgeom.h** -- hypergeometric functions of real variables
==================================================================================

See :ref:`acb-hypgeom` for the implementation of hypergeometric functions.

For convenience, this module provides corresponding functions for direct
use with the real types :type:`arb_t` and :type:`arb_poly_t`.
Most methods are simple wrappers around the complex versions, with
a tiny amount of extra overhead for conversions, but in some cases the 
functions in this module will be faster. In the future, code that is further
optimized specifically for real variables might be added to this module.

Generalized hypergeometric function
-------------------------------------------------------------------------------

.. function:: void arb_hypgeom_pfq(arb_t res, arb_srcptr a, slong p, arb_srcptr b, slong q, const arb_t z, int regularized, slong prec)

    Computes the generalized hypergeometric function `{}_pF_{q}(z)`,
    or the regularized version if *regularized* is set.

Confluent hypergeometric functions
-------------------------------------------------------------------------------

.. function:: void arb_hypgeom_0f1(arb_t res, const arb_t a, const arb_t z, int regularized, slong prec)

    Computes the confluent hypergeometric limit function
    `{}_0F_1(a,z)`, or `\frac{1}{\Gamma(a)} {}_0F_1(a,z)` if *regularized*
    is set.

.. function:: void arb_hypgeom_m(arb_t res, const arb_t a, const arb_t b, const arb_t z, int regularized, slong prec)

    Computes the confluent hypergeometric function
    `M(a,b,z) = {}_1F_1(a,b,z)`, or
    `\mathbf{M}(a,b,z) = \frac{1}{\Gamma(b)} {}_1F_1(a,b,z)` if *regularized* is set.

.. function:: void arb_hypgeom_1f1(arb_t res, const arb_t a, const arb_t b, const arb_t z, int regularized, slong prec)

    Alias for :func:`arb_hypgeom_m`.

.. function:: void arb_hypgeom_u(arb_t res, const arb_t a, const arb_t b, const arb_t z, slong prec)

    Computes the confluent hypergeometric function `U(a,b,z)`.

Gauss hypergeometric function
-------------------------------------------------------------------------------

.. function:: void arb_hypgeom_2f1(arb_t res, const arb_t a, const arb_t b, const arb_t c, const arb_t z, int regularized, slong prec)

    Computes the Gauss hypergeometric function
    `{}_2F_1(a,b,c,z)`, or
    `\mathbf{F}(a,b,c,z) = \frac{1}{\Gamma(c)} {}_2F_1(a,b,c,z)`
    if *regularized* is set.

    Additional evaluation flags can be passed via the *regularized*
    argument; see :func:`acb_hypgeom_2f1` for documentation.

Error functions and Fresnel integrals
-------------------------------------------------------------------------------

.. function:: void arb_hypgeom_erf(arb_t res, const arb_t z, slong prec)

    Computes the error function `\operatorname{erf}(z)`.

.. function:: void _arb_hypgeom_erf_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_erf_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the error function of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_erfc(arb_t res, const arb_t z, slong prec)

    Computes the complementary error function
    `\operatorname{erfc}(z) = 1 - \operatorname{erf}(z)`.
    This function avoids catastrophic cancellation for large positive *z*.

.. function:: void _arb_hypgeom_erfc_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_erfc_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the complementary error function of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_erfi(arb_t res, const arb_t z, slong prec)

    Computes the imaginary error function
    `\operatorname{erfi}(z) = -i\operatorname{erf}(iz)`.

.. function:: void _arb_hypgeom_erfi_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_erfi_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the imaginary error function of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_fresnel(arb_t res1, arb_t res2, const arb_t z, int normalized, slong prec)

    Sets *res1* to the Fresnel sine integral `S(z)` and *res2* to
    the Fresnel cosine integral `C(z)`. Optionally, just a single function
    can be computed by passing *NULL* as the other output variable.
    The definition `S(z) = \int_0^z \sin(t^2) dt` is used if *normalized* is 0,
    and `S(z) = \int_0^z \sin(\tfrac{1}{2} \pi t^2) dt` is used if
    *normalized* is 1 (the latter is the Abramowitz & Stegun convention).
    `C(z)` is defined analogously.

.. function:: void _arb_hypgeom_fresnel_series(arb_ptr res1, arb_ptr res2, arb_srcptr z, slong zlen, int normalized, slong len, slong prec)

.. function:: void arb_hypgeom_fresnel_series(arb_poly_t res1, arb_poly_t res2, const arb_poly_t z, int normalized, slong len, slong prec)

    Sets *res1* to the Fresnel sine integral and *res2* to the Fresnel
    cosine integral of the power series *z*, truncated to length *len*.
    Optionally, just a single function can be computed by passing *NULL*
    as the other output variable.

Exponential and trigonometric integrals
-------------------------------------------------------------------------------

.. function:: void arb_hypgeom_ei(arb_t res, const arb_t z, slong prec)

    Computes the exponential integral `\operatorname{Ei}(z)`.

.. function:: void _arb_hypgeom_ei_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_ei_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the exponential integral of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_si(arb_t res, const arb_t z, slong prec)

    Computes the sine integral `\operatorname{Si}(z)`.

.. function:: void _arb_hypgeom_si_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_si_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the sine integral of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_ci(arb_t res, const arb_t z, slong prec)

    Computes the cosine integral `\operatorname{Ci}(z)`.
    The result is indeterminate if `z < 0` since the value of the function would be complex.

.. function:: void _arb_hypgeom_ci_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_ci_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the cosine integral of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_shi(arb_t res, const arb_t z, slong prec)

    Computes the hyperbolic sine integral `\operatorname{Shi}(z) = -i \operatorname{Si}(iz)`.

.. function:: void _arb_hypgeom_shi_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_shi_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the hyperbolic sine integral of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_chi(arb_t res, const arb_t z, slong prec)

    Computes the hyperbolic cosine integral `\operatorname{Chi}(z)`.
    The result is indeterminate if `z < 0` since the value of the function would be complex.

.. function:: void _arb_hypgeom_chi_series(arb_ptr res, arb_srcptr z, slong zlen, slong len, slong prec)

.. function:: void arb_hypgeom_chi_series(arb_poly_t res, const arb_poly_t z, slong len, slong prec)

    Computes the hyperbolic cosine integral of the power series *z*,
    truncated to length *len*.

.. function:: void arb_hypgeom_li(arb_t res, const arb_t z, int offset, slong prec)

    If *offset* is zero, computes the logarithmic integral
    `\operatorname{li}(z) = \operatorname{Ei}(\log(z))`.

    If *offset* is nonzero, computes the offset logarithmic integral
    `\operatorname{Li}(z) = \operatorname{li}(z) - \operatorname{li}(2)`.

    The result is indeterminate if `z < 0` since the value of the function would be complex.

.. function:: void _arb_hypgeom_li_series(arb_ptr res, arb_srcptr z, slong zlen, int offset, slong len, slong prec)

.. function:: void arb_hypgeom_li_series(arb_poly_t res, const arb_poly_t z, int offset, slong len, slong prec)

    Computes the logarithmic integral (optionally the offset version)
    of the power series *z*, truncated to length *len*.

