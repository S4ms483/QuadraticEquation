#ifndef TESTS_H_
#define TESTS_H_

#include "solve.h"

/// @brief structure for all the variables needed for a test
struct WholeTest
{
    Coeffs coeffs;              ///<- coefficients 
    Results resultrefs;         ///<- result references
    int nRootsref;              ///<- reference for the amount of roots
};

/// @brief Runs one test using the SilveEquation func to get results and amount of roots and comparing it with references
/// @param test coefficients and references for results
/// @return true if all the tests went successfully and false in case of any error
int OneTest (const WholeTest* test);

/// @brief Runs all the tests from the test file
/// @return true in case of success and false otherwise
bool TestFile();


#endif //TESTS_H_
