#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main(void)
{
   int    i, j, n, count = 0, val;
   int    array[MAX][MAX];

   scanf("%d", &n);

   if (n <= 0 && n > 10)
   {
      exit(0);
   }
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &val);
         if (val == 1 || val == 0)
            array[i][j] = val;
         else
            exit(0);
      }
   }

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n-1; j++)
      {
         if (array[i][j] == 1 && array[i][j+1] == 1)
         {
            count = count + 1;
         }
      }
   }

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n-1; j++)
      {
         if (array[j][i] == 1 && array[j+1][i] == 1)
         {
            count = count + 1;
         }
      }
   }

   for (i = 0; i < n-1; i++)
   {
      if (array[i][i] == 1 && array[i+1][i+1])
      {
          count++;
      }
   }
   
   for (i = 0; i < n-1; i++)
   {
      if (array[i][n-(i+1)] == 1 && array[n-i-2][n-i-2] == 1)
      {
          count++;
      }
   }
   printf("\n%d\n", count);

   exit(0);
}

