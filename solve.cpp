#include "solve.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "equality.h"

int SolveEquation(double a, double b, double c,
                        double* x1, double* x2)                     
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    int nRoots = 0;
    double d;                                       
    d = b*b - 4*a*c;

    (AreEqual(a, 0))
        ? (nRoots = Linear(b, c, x1))
        : (nRoots = Square(a, b, c, d, x1, x2));
    return nRoots;
}



int Linear(double b, double c, double* x1)                         
{
    assert(x1 != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (AreEqual(b, 0))
    {
        if (AreEqual(c, 0))                               
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
        *x1 = -c/b;
        return NumOfRoots::ONEROOT;
    }
}


int Square(double a, double b, double c, double d,
                  double* x1, double* x2)                           
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (AreEqual(d, 0))                                   
    {
        *x1 = -b/(2*a);
        return NumOfRoots::ONEROOT;
    }
                                                
    else if (d < 0)
    {
        return NumOfRoots::NOROOTS;
    }
                                                  
    else
    {
        *x1 = (-b - sqrt(d))/(2*a);
        *x2 = (-b + sqrt(d))/(2*a);
        return NumOfRoots::TWOROOTS;
    }
}

