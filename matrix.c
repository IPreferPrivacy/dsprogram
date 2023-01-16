#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10], i, j, k, m, n, p, q, sum, choice;
    do
    {
printf("1.Enter 1st \n 2.Enter 2nd \n3. Display 1st \n 4.Display 2nd \n5. Add \n6. Subtract\n7. Multiply\n 8.Result");
printf("Enter the choice");
scanf("%d",&choice);
switch(choice)
{
        case 1:
            printf("Enter m and n:");
            scanf("%d %d", &m, &n);
            printf("Enter the 1st matrix:");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("Enter");
                    scanf("%d", (*(a + i) + j));
                }
            }
            break;
        case 2:
            printf("Enter p and q:");
            scanf("%d %d", &p, &q);
            printf("\nEnter the 2nd matrix:");
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < q; j++)
                {
                    printf("Enter");
                    scanf("%d", (*(b + i) + j));
                }
            }
            break;
        case 3:
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("%d ", *(*(a + i) + j));
                }
                printf("\n");
            }
            break;
        case 4:
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < q; j++)
                {
                    printf("%d ", *(*(b + i) + j));
                }
                printf("\n");
            }
            break;
        case 5:
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    *(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
                }
            }
            break;
        case 6:
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    *(*(c + i) + j) = *(*(a + i) + j) - *(*(b + i) + j);
                }
            }
            break;
        case 7:
            if (n != p)
            {
                printf("Multiplication cannot be done\n");
            }
            else
                for (i = 0; i < m; i++)
                {
                    for (j = 0; j < q; j++)
                    {
                        sum = 0;
                        for (k = 0; k < m; k++)
                        {
                            sum += *(*(a + i) + k) * *(*(b + k) + j);
                        }
                        *(*(c + i) + j) = sum;
                    }
                }
        case 8:
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < q; j++)
                {
                    printf("%d", *(*(c + i) + j));
                }
                printf("\n");
            }
            break;
        default:
            printf("Not Valid");
}
    } while (choice != 9);
    return 0;
}