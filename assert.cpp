#include <stdio.h>
#include <stdlib.h>

#include "user.h"
#include "assert.h"


void AnotherAssert(bool assertion, const char* str, const char* file, int line)
{                                                     
    if (!assertion)                                                           
        {                                                                     
            printf(RED "Assertion failed. %s:%d \n%s" RESET, file, line, str);
            abort();                                                          
        }                                                                     
}
