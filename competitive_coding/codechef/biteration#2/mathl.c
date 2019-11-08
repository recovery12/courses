#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int           i, t, n, max = 0;
   long long int j, tot = 1, a, b, arr[1000000];

   scanf("%d", &t);

   for (i = 0; i < t; i++)
   {
      scanf("%d", &n);
      b = 1;
      for (j = 1; j < n+1; j++)
      {
         b = (b%(1000000007) * j%(1000000007))%1000000007;
         tot = (tot%1000000007 * b%1000000007)%1000000007;
      }
      printf("%lld\n", tot);
      tot = 1;
   }

   exit(0);
}
