#include "equality.h"

#include <stdio.h>
#include <math.h>

bool AreEqual(double n, double m)
{
    const double eps = 0.000001;
    return (fabs(m - n) < eps);
}
