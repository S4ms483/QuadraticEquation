#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#include "tests.h"
#include "solve.h"
#include "user.h"


int main(void)
{
    RunTest();

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int RootAmount = 0;

    printf ("Quadratic equation solver\n");
    printf ("Enter a-, b- and c-coefficients:\n");

    Input(&a, &b, &c);

    RootAmount = SolveEquation(a, b, c, &x1, &x2);  

    EquationOutput(x1, x2, RootAmount);             

    return 0;
}

