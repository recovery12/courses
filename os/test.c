#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main()
{
   int        i, j;
   int        arr[MAX][MAX];
   long int     start, end;

   start = clock();
   printf("abc\n");
   for (i = 0; i < 1000; i++)
   {
   printf("abc\n");
      for (j = 0; i < 300; j++)
      {
         arr[i][j] = 0;
      }
   }
   end = clock();
   printf("abc\n");

   printf("Time taken: %ld\n", end-start);
   exit(0);
}
