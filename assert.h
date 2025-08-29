#ifndef ASSERT_H_
#define ASSERT_H_

#include <stdlib.h>

/// @brief Assert function
/// @param assertion  statement that needs to be checked
/// @param str        string to be shown in case of unsuccessful assertion
/// @param file       name of file in which the func is called
/// @param line       number of line where the func is called
void AnotherAssert(bool assertion, const char* str, const char* file, int line);

#define MyAssert(assertion, str) AnotherAssert(assertion, str, __FILE__, __LINE__)                                         

#endif //ASSERT_H_