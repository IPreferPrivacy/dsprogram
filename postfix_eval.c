#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack
{
    int top;
    unsigned capacity;
    int *arr;
} stack;

stack *createstack(unsigned capacity)
{
    stack *stack1 = (stack *)malloc(sizeof(stack));
    stack1->capacity = capacity;
    stack1->arr = (int *)malloc(stack1->capacity * (sizeof(int)));
    if (!stack1)
    {
        printf("ERROR!");
        return NULL;
    }
    return stack1;
}

int isEmpty(stack *stack)
{
    return stack->top == -1;
}

char peek(stack *stack)
{
    return stack->arr[stack->top];
}

char pop(stack *stack)
{
    if (!isEmpty(stack))
        return stack->arr[stack->top--];
    return '$';
}

void push(stack *stack, char x)
{
    stack->arr[++stack->top] = x;
}

int postfix_eval(char *exp)
{
    stack *Stack1 = createstack(strlen(exp));
    if (!Stack1)
        return -1;
    for (int i = 0; i < strlen(exp); i++)
    {
        if (isdigit(exp[i]))
        {
            push(Stack1, exp[i] - '0');
        }
        else
        {
            int val1 = pop(Stack1);
            int val2 = pop(Stack1);
            switch (exp[i])
            {
            case '+':
                push(Stack1, val1 + val2);
                break;
            case '-':
                push(Stack1, val1 - val2);
                break;
            case '*':
                push(Stack1, val1 * val2);
                break;
            case '/':
                push(Stack1, val1 / val2);
                break;
            }
        }
    }
    return pop(Stack1);
}

int main()
{
    char exp[20];
    printf("Enter the expression: ");
    scanf("%s", &exp);
    printf("postfix evaluation: %d\n", postfix_eval(exp));
    return EXIT_SUCCESS;
}