/*
    Copyright (C) 2014 Fredrik Johansson

    This file is part of Arb.

    Arb is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "acb_poly.h"

static ulong choose_M(ulong N, slong target)
{
    return FLINT_MIN(N, target + FLINT_MIN(N / 100, 2000));
}

static void
estimate_mag(mag_t m, const acb_t s, const acb_t a, slong prec)
{
    acb_t t;
    acb_init(t);

    acb_neg(t, s);
    acb_pow(t, a, t, prec);

    if (acb_is_finite(t))
        acb_get_mag(m, t);
    else
        mag_one(m);

    acb_clear(t);
}

void
_acb_poly_zeta_em_choose_param(mag_t bound, ulong * N, ulong * M, const acb_t s, const acb_t a, slong d, slong target, slong prec)
{
    ulong A, B, C, limit;
    mag_t Abound, Bbound, Cbound, tol;

    mag_init(Abound);
    mag_init(Bbound);
    mag_init(Cbound);
    mag_init(tol);

    if (!acb_is_one(a) && arf_cmp_2exp_si(arb_midref(acb_realref(s)), 3) > 0)
    {
        /* estimate zeta(s,a) ~= a^-s */
        estimate_mag(tol, s, a, prec);
        mag_mul_2exp_si(tol, tol, -target);
    }
    else
    {
        mag_set_ui_2exp_si(tol, 1, -target);
    }

    A = 1;
    B = 2;

    /* Hack: allow evaluation very high up in the critical strip... */
    if (arf_cmpabs_2exp_si(arb_midref(acb_imagref(s)), 10) > 0)
        limit = UWORD_MAX / 4;
    else
        limit = 100 * target;  /* but normally, fail more quickly */

    _acb_poly_zeta_em_bound1(Bbound, s, a, B, choose_M(B, target), d, prec);

    if (mag_cmp(Bbound, tol) > 0)
    {
        while (mag_cmp(Bbound, tol) > 0 && B <= limit)
        {
            mag_set(Abound, Bbound);
            A *= 2;
            B *= 2;

            if (B == 0) abort();

            _acb_poly_zeta_em_bound1(Bbound, s, a, B, choose_M(B, target), d, prec);
        }

        /* bisect (-A, B] */
        while (B > A + 4)
        {
            C = A + (B - A) / 2;

            _acb_poly_zeta_em_bound1(Cbound, s, a, C, choose_M(C, target), d, prec);

            if (mag_cmp(Cbound, tol) < 0)
            {
                B = C;
                mag_set(Bbound, Cbound);
            }
            else
            {
                A = C;
                mag_set(Abound, Cbound);
            }
        }
    }

    mag_set(bound, Bbound);
    *N = B;
    *M = choose_M(B, target);

    mag_clear(Abound);
    mag_clear(Bbound);
    mag_clear(Cbound);
    mag_clear(tol);
}

