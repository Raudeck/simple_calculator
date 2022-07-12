#include "header.h"
#include <string.h>
#include <math.h>

int compute (char *exp)
{
    struct stack *stack = create_stack(strlen(exp));
    size_t i;
    int val1, val2;

    for (i = 0; *(exp + i) != '\0'; i++) {
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0');
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
                case '+' :
                    push(stack, val1 + val2);
                    break;
                case '-' :
                    push(stack, val1 - val2);
                    break;
                case '*' :
                    push(stack, val1 * val2);
                    break;
                case '/' :
                    push(stack, val1 / val2);
            }
        }
    }
    return pop(stack);
}