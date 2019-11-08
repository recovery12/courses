#include <stdio.h>
#include <stdlib.h>

// 17MCME07 17MCME10  Subash sarangi Mahesh chandra

#define MAX        100

int main(void)
{
   int     i, j, k = 0;
   int     arr[MAX][MAX];

   for (i = 0; i < MAX; i++)
   {
      for (j = 0; j < MAX; j++)
      {
         arr[i][j] = k;
         k++;
      }
   }

   
   for (i = 0; i < MAX; i++)
   {
      for (j = 0; j < MAX; j++)
      {
         printf("%d ", *((*arr+i)+j));
      }
      printf("\n");
   }

   exit(0);
}
