#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

int main()
{
    boolean weiss,schwarz;

    weiss = TRUE;
    schwarz = FALSE;

    if (schwarz)
    {
        printf("Schwarz!");
    }
    if (weiss)
    {
        printf("Weiss!");
    }
    return 0;
}
