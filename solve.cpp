#include "solve.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "equality.h"


int SolveEquation(const Coeffs* coeffs, Results* results)
{
    assert(results != NULL);
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    int nRoots = 0;
    double d;
    d = (coeffs->b)*(coeffs->b) - 4*(coeffs->a)*(coeffs->c);

    (AreEqual(coeffs->a, 0))
        ? (nRoots = Linear(coeffs, results))
        : (nRoots = Square(coeffs, results, d));
    return nRoots;
}



int Linear(const Coeffs* coeffs, Results* results)
{
    assert(results != NULL);
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    if (AreEqual(coeffs->b, 0))
    {
        if (AreEqual(coeffs->c, 0))
        {
            return NumOfRoots::INFROOTS;
        }

        else
        {
            return NumOfRoots::NOROOTS;
        }
    }


    else
    {
        results->x1 = -(coeffs->c)/(coeffs->b);
        results->x1 = AreEqual(results->x1, 0) ? 0 : results->x1;

        return NumOfRoots::ONEROOT;
    }
}


int Square(const Coeffs* coeffs, Results* results, double d)
{
    assert(results != NULL);
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    if (AreEqual(d, 0))
    {
        results->x1 = -(coeffs->b)/(2*(coeffs->a));

        results->x1 = AreEqual(results->x1, 0) ? 0 : results->x1;

        return NumOfRoots::ONEROOT;
    }

    else if (d < 0)
    {
        return NumOfRoots::NOROOTS;
    }

    else
    {
        results->x1 = (-(coeffs->b) - sqrt(d))/(2*(coeffs->a));
        results->x2 = (-(coeffs->b) + sqrt(d))/(2*(coeffs->a));
        results->x1 = AreEqual(results->x1, 0) ? 0 : results->x1;
        results->x2 = AreEqual(results->x2, 0) ? 0 : results->x2;

        return NumOfRoots::TWOROOTS;
    }
}
