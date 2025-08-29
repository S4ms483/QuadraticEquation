#include "user.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "solve.h"
#include "equality.h"
#include "tests.h"


void Input(Coeffs* coeffs)
{
    assert (coeffs != NULL);

    int s = scanf("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c));
    int ch = getchar();

    while ((s < 3) || ((ch != ' ') && (ch != EOF) && (ch != '\n')))
    {
        printf(RED "Incorrect input. Try again\n" RESET);

        ch = getchar();
        while (ch != '\n')
        {
            ch = getchar();
        }

        s = scanf("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c));
        ch = getchar();

    }

}



int AdditionalCommands(int argc, char* argv[])
{
    if (argc == 1)
    {
        return Flags::NoFlag;
    }
    else if (argc == 2 && strcmp(argv[1], "--test") == 0)
    {
        if (TestFile())
        {
            return Flags::NoMistake;
        }
        return Flags::Mistake;
    }
    printf(RED "Flag unidentified" RESET);
    return Flags::Mistake;
}



void EquationOutput(Results* results, int RootAmount)
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
            printf("The equation has one root: %lg", results->x1);
            break;

        case NumOfRoots::TWOROOTS:
            printf("The equation has two roots: %lg and %lg", results->x1, results->x2);
            break;
        default:
            assert(0 && "cho sluchilos???");
    }
}

