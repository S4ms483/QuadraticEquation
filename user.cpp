#include <stdio.h>
#include <assert.h>
#include "user.h"
#include "solve.h"


void Input(double* a, double* b, double* c)                         /*проверка корректности ввода - не менее 3 чисел*/
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    int s = scanf("%lf %lf %lf", a, b, c);
    int ch = getchar();

    while ((s < 3) || ((ch != ' ') && (ch != EOF) && (ch != '\n')))
    {
        printf("Incorrect input. Try again\n");

        ch = getchar();
        while (ch != '\n')
        {
            ch = getchar();
        }

        s = scanf("%lf %lf %lf", a, b, c);
        ch = getchar();

    }

}



int EquationOutput(double x1, double x2, int RootAmount)            /*вывод решений уравнения*/
{
    switch(RootAmount)
    {
        case NumOfRoots::INFROOTS:
            printf("The equation has an infinite amount of roots");
            break;

        case NumOfRoots::NOROOTS:
            printf("The equation has no roots");
            break;

        case NumOfRoots::ONEROOT:
            printf("The equation has one root: %lg", x1);
            break;

        case NumOfRoots::TWOROOTS:
            printf("The equation has two roots: %lg and %lg", x1, x2);
            break;
        default:
            assert(0); // cho sluchilos???
    }
    return 0;
}

