#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#include "assert.h"
#include "tests.h"
#include "solve.h"
#include "user.h"


/// @brief Main function
/// @param argc  amount of commands given to the terminal
/// @param argv  array of commands given to the terminal
/// @return returns 0 in case of success and 1 in case of mistake
int main(int argc, char *argv[])
{
    //MyAssert(1 == 0, "Hello world");
    
    if (AdditionalCommands(argc, argv) == Flags::Mistake)
    {
        return 1;
    }

    Coeffs coeffs = {NAN, NAN, NAN};
    Results results = {NAN, NAN};

    printf (UNDERLINED "Quadratic equation solver\n" RESET);
    printf ("Enter a-, b- and c-coefficients:\n");

    Input(&coeffs);

    int RootAmount = SolveEquation(&coeffs, &results);

    EquationOutput(&results, RootAmount);

    return 0;
}


