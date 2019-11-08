#include <stdio.h>
#include <stdlib.h>

int main()
{
   int                  i;
   long long int        t, tiles, m, n;

   scanf("%lld", &t);

   for (i = 0; i < t; i++)
   {
      tiles = 0;
      scanf("%lld", &m);
      scanf("%lld", &n);
      if (m%2 == 0)
      {
         tiles = tiles + (long long int)(m/2)*n;
      }
      else if (m%2 != 0 && n%2 != 0)
      {
         tiles = tiles + (long long int)(m/2)*n;
         tiles = tiles + (long long int)(n/2)+1;
      }
      else if (m%2 != 0 && n%2 == 0)
      {
         tiles = tiles + (long long int)(m/2)*n;
         tiles = tiles + (long long int)(n/2);
      }
      printf("%lld\n", tiles);
   }

   return 0;
}
