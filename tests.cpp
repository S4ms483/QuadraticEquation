#include "tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "solve.h"
#include "equality.h"
#include "user.h"


int OneTest (const WholeTest* test)
{
    Results results = {0, 0};
    int nRoots = SolveEquation(&test->coeffs, &results);
    if (!(AreEqual(results.x1, (test->resultrefs.x1)) && AreEqual(results.x2, (test->resultrefs.x2)) && (nRoots == test->nRootsref)))
    {
        printf (RED "Test not passed. Results got: x1 = %lg, x2 = %lg, nRoots = %d.\n Results expected: x1 = %lg, x2 = %lg, nRoots = %d.\n" RESET, results.x1, results.x2, nRoots, test->resultrefs.x1, test->resultrefs.x2, test->nRootsref);
        return 1;
    }

    return 0;
}


/// @brief 
/// @return 
bool TestFile()
{
    FILE* testfile = fopen("testfile.txt", "r");

    Coeffs coeffs = {NAN, NAN, NAN};
    Results resultrefs = {NAN, NAN};
    int nRootsref = 0;


    if (testfile == NULL)
    {
        printf(RED "An error occured while reading the text file.\n" RESET);
        return false;
    }

    else
    {
        int failed = 0;
        int nVars = fscanf(testfile, "%lf %lf %lf %lf %lf %d", &(coeffs.a), &(coeffs.b), &(coeffs.c), &(resultrefs.x1), &(resultrefs.x2), &nRootsref);
        while (nVars == 6)
        {
            WholeTest test = {coeffs, resultrefs, nRootsref};

            failed += OneTest(&test);

            nVars = fscanf(testfile, "%lf %lf %lf %lf %lf %d", &(coeffs.a), &(coeffs.b), &(coeffs.c), &(resultrefs.x1), &(resultrefs.x2), &nRootsref);
        }
        fclose(testfile);

        if (failed == 0)
        {
            printf(GREEN "All tests passed.\n\n" RESET);
            return true;
        }
        return false;
    }
}
