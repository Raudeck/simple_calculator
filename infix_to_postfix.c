#include "header.h"
#include "string.h"
#include "stdlib.h"

struct stack* create_stack (int capacity) 
{
    struct stack *stack = (struct stack*)malloc(sizeof(struct stack));

    if(!stack) 
        return NULL;
    
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int) * capacity);

    return stack;
}

char pop (struct stack *stack) 
{
    if(stack->top != -1)
        return stack->array[stack->top--];
}

void push (struct stack *stack, char ch)
{
    stack->array[++stack->top] = ch;
}

char peek (struct stack *stack)
{
    return stack->array[stack->top];
}

int precedence (char ch)
{
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void intfix_to_postfix(char *exp)
{
    size_t i, j = 0;

    struct stack *stack = create_stack(strlen(exp));

    for (i = 0, j = 0; *(exp + i) != '\0'; i++) {
        if (isalnum(exp[i])) {
            exp[j++] = exp[i];
        } else if (exp[i] == '(') {
            push(stack, exp[i]);
        } else if (exp[i] == ')') {
            while (peek(stack) != '(') {
                exp[j++] = pop(stack);  
            }         
            if (peek(stack)=='(')
                pop(stack);
        }
        else {
            while (precedence(stack->array[stack->top]) >= precedence(exp[i])) 
                exp[j++] = pop(stack);
            push(stack, exp[i]);
        }
    }

    while (stack->top != -1) {
        exp[j++] = pop(stack);
    }
    exp[j] = '\0';
}
