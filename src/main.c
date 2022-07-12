#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    /* Change this value if you need to compute */
    char exp[] = "(1+2)*3";
    intfix_to_postfix(exp);
    printf("%d\n", compute(exp));
    system("pause");
}