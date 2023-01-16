#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}node;

node *top;

void push(){
    node *ptr = (node *) malloc(sizeof(node));
    int value;
    printf("Enter the element you want to push: ");
    scanf("%d", &value);
    if (top==NULL)
    {
        ptr->val = value;
        ptr->next = NULL;
        top = ptr;
    }
    else{
        ptr->val = value;
        ptr->next = top;
        top = ptr;
    }
    printf("\n%d pushed to stack.\n", value);
}

void pop(){
    node *ptr = (node *) malloc(sizeof(node));
    int item;
    if (top == NULL){
        printf("Stack underflow.");
    }
    else{
        item = top->val;
        ptr = top;
        top = top->next;
        free(ptr);
        printf("%d popped.", item);
    }
}

void display(){
    int i;
    struct node *ptr;
    ptr = top;
    if (top == NULL){
        printf("Stack is empty!");
    }
    else
    {
        printf("Printing stack elements \n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}

int main(){
    int choice = 0;
    printf("\n*********Stack operations using linked list*********\n");
    printf("\n----------------------------------------------\n");
    while (choice != 4)
    {
        printf("\n\nChose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
    return 0;
}