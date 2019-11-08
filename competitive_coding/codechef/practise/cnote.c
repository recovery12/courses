#include <stdio.h>
#include <stdlib.h>

#define MAX      100000

int main(void)
{
   int        t, i, j, x, y, k, n, p, c, b = 0;

   scanf("%d", &t);

   for (i = 0; i < t; i++)
   {
       scanf("%d", &x);
       scanf("%d", &y);
       scanf("%d", &k);
       scanf("%d", &n);
       for (j = 0; j < n; j++)
       {
          scanf("%d", &p);
          scanf("%d", &c);
          if (k >= c && x - y < p)
          {
             b = 1;
          }
       }
       if (b == 0)
       {
          printf("UnluckyChef\n");
       }
       else
       {
          printf("LuckyChef\n");
       }
       b = 0;
   }

   exit(0);
}
