#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <ctype.h>

struct stack {
    int top;
    int *array;
};

extern struct stack* create_stack (int capacity);
extern char pop (struct stack *stack);
extern void push (struct stack *stack, char ch);
extern int compute (char *exp);
extern void intfix_to_postfix(char *exp);

#endif