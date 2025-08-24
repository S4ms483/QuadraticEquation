#ifndef SOLVE_H_
#define SOLVE_H_

int SolveEquation(double a, double b, double c, double* x1, double* x2);
int Linear(double b, double c, double* x1);
int Square(double a, double b, double c, double d, double* x1, double* x2);
bool AreEqual(double n, double m);

enum NumOfRoots
{
    INFROOTS = -1,
    NOROOTS,
    ONEROOT,
    TWOROOTS
};


#endif //  SOLVE_H_
