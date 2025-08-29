#ifndef USER_H_
#define USER_H_

#include "solve.h"


#define RESET "\033[0;0m"               ///<- usual color and style
#define UNDERLINED "\033[4m"            ///<- underlined letters for header
#define RED "\033[0;31m"                ///<- red letters for error messages
#define GREEN "\033[2;32m"              ///<- green dimmed letters for success messages


/// @brief Checks whether the input is correct and offers retreying in case of a mistake
/// @param coeffs equation coefficients (a, b and c) are being changed as a result of the correct input
void Input(Coeffs* coeffs);

/// @brief Checks whether any additional commands are being input
/// @param argc  amount of commands
/// @param argv  array of commands
/// @return enum numbers for each case
int AdditionalCommands(int argc, char* argv[]);

/// @brief Shows the result of the program based on the amount of roots
/// @param results     equation resukts (x1 and x2)
/// @param RootAmount  amount of roots (nRoots)
void EquationOutput(Results* results, int RootAmount);

enum Flags
{
    NoFlag,             ///<- no additional commands
    Mistake,            ///<- undefined flag or unsuccessful tests
    NoMistake           ///<- test flag and successful tests
};

#endif //USER_H_
