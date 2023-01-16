#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(stack *s)
{
    if ((s->top) == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *s)
{
    if ((s->top) == (s->size) - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void peek(stack *s)
{
    if (isEmpty == 1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("%d", s->arr[s->top]);
    }
}

void push(stack *s)
{
    if (isFull(s) == 1)
    {
        printf("Stack is full!");
    }
    else
    {
        (s->top)++;
        printf("Enter the element you want to push: ");
        scanf("%d", &(s->arr[s->top]));
    }
}

void pop(stack *s)
{
    if (isEmpty(s) == 1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("Popped %d", s->arr[s->top]);
        s->top--;
    }
}

void display(stack *s)
{
    int empty = isEmpty(s);
    if (empty == 1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("\nThe elements in sacks are:");
        for (int i = (s->top); i >= 0; i--)
            printf("\n\t%d", s->arr[i]);
        printf("\nPress next choice");
    }
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    printf("Enter the size of stack: ");
    scanf("%d", &s->size);
    s->arr = (int *)malloc((s->size) * sizeof(int));
    s->top = -1;
    int choice;
    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push(s);
            break;
        }
        case 2:
        {
            pop(s);
            break;
        }
        case 3:
        {
            display(s);
            break;
        }
        case 4:
        {
            printf("\nExiting!");
            break;
        }
        default:
        {
            printf("\nPlease enter a valid choice(1/2/3/4)");
        }
        }
    } while (choice != 4);
    return 0;
}