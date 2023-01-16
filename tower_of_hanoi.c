#include <stdio.h>

void hanoi(int n, char beg, char aux, char end);

int main()
{
    int n;
    char a, b, c;
    printf("Enter number of discs: ");
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
    return 0;
}

void hanoi(int n, char beg, char aux, char end)
{
    if (n <= 0)
    {
        printf("Illegal entry.");
    }
    else if (n == 1)
    {
        printf("\nMove disc from %c to %c.", beg, end);
    }
    else
    {
        hanoi(n - 1, beg, end, aux);
        hanoi(1, beg, aux, end);
        hanoi(n - 1, aux, beg, end);
    }
}