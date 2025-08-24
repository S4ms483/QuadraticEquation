#include "solve.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "equality.h"

int SolveEquation(double a, double b, double c,
                        double* x1, double* x2)                     /*решение уравнения*/
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    int nRoots = 0;
    double d;                                       /*дискриминант*/
    d = b*b - 4*a*c;

    (AreEqual(a, 0))
        ? (nRoots = Linear(b, c, x1))
        : (nRoots = Square(a, b, c, d, x1, x2));
    return nRoots;
}



int Linear(double b, double c, double* x1)                          /*случай линейной функции*/
{
    assert(x1 != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (AreEqual(b, 0))
    {
        if (AreEqual(c, 0))                               /*корней бесконечно много*/
        {
            return NumOfRoots::INFROOTS;
        }

        else
        {
            return NumOfRoots::NOROOTS;                                /*(0x^2 + 0x + c = 0) корней нет*/
        }
    }


    else
    {                   /*(bx + c = 0) 1 корень*/
        *x1 = -c/b;
        return NumOfRoots::ONEROOT;
    }
}


int Square(double a, double b, double c, double d,
                  double* x1, double* x2)                           /*квадратное уравнение*/
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (AreEqual(d, 0))                                   /*полный квадрат - 1 корень*/
    {
        *x1 = -b/(2*a);
        return NumOfRoots::ONEROOT;
    }
                                                 /*дискриминант меньше нуля - 0 корней*/
    else if (d < 0)
    {
        return NumOfRoots::NOROOTS;
    }
                                                  /*положительный дискриминант - 2 корня*/
    else
    {
        *x1 = (-b - sqrt(d))/(2*a);
        *x2 = (-b + sqrt(d))/(2*a);
        return NumOfRoots::TWOROOTS;
    }
}
