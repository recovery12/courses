#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main(void)
{
   int    i, j, n, count = 0;
   int    array[MAX][MAX];

   scanf("%d", &n);

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &array[i][j]);
      }
   }

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n-1; j++)
      {
            if (array[i][j] == 1 && array[i][j+1] == 1)
            {
                  count++;
            }
      }
   }
   printf("\n%d\n", count);

   exit(0);
}
