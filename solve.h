#ifndef SOLVE_H_
#define SOLVE_H_

/// @brief Structure for equation coefficients
struct Coeffs
{
    double a, b, c;
};


/// @brief Structure for equation results
struct Results
{
    double x1, x2;
};

/// @brief Checks whether the equation is quadratic or linear
/// @param coeffs   equation coefficients (a, b and c)
/// @param results  equation results (x1 and x2) are changed as a result
/// @return amount of roots (nRoots)
int SolveEquation(const Coeffs* coeffs, Results* results);

/// @brief Solves a linear equation
/// @param coeffs   equation coefficients (b and c)
/// @param results  equation results (x1 and x2) are changed as a result
/// @return amount of roots (nRoots)
int Linear(const Coeffs* coeffs, Results* results);

/// @brief Solves a quadratic equation
/// @param coeffs   equation coefficients (a, b and c)
/// @param results  equation results (x1 and x2) are changed as a result
/// @param d        discriminant of the equation
/// @return amount of roots (nRoots)
int Square(const Coeffs* coeffs, Results* results, double d);


enum NumOfRoots
{
    INFROOTS = -1,    ///<- infinite amount of roots
    NOROOTS,          ///<- no roots
    ONEROOT,          ///<- one root
    TWOROOTS          ///<- two roots
};


#endif //  SOLVE_H_
