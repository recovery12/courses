#include <stdio.h>
#include <stdlib.h>

#define  MAX           100000
#define  bigint        long long int

void find_numbers(bigint n, bigint a, bigint b);

void printarray(int p[], int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
       printf("%d ", p[i]);
    }
    printf("\n");

    return ;
}

int main()
{
    bigint n, a, b;
    bigint arr[MAX];

    scanf("%lld", &n);
    scanf("%lld", &a);
    scanf("%lld", &b);

    find_numbers(n, a, b);

    exit(0);
}

void find_numbers(bigint n, bigint a, bigint b)
{
    bigint       i, j, val, k = 0;
    bigint       tmp[MAX];

    if (a > (int)n/2)
    {
        printf("NO\n");
        exit(0);
    }

    for (i = b; i >= a; i--)
    {
        if (n == 0)
        {
            break;
        }

        val = (bigint) n/i;
        if (val > 1)
        {
            for (j = 0; j < val; j++)
            {
                printf("%lld ", i);
            }
        }
        else if (val == 1)
        {
            printf("%lld\n", i);
        }
        n = n - val*i;
    }

    return ;
}