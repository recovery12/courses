#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        N, num, nextnum, max, i;

   printf("Enter a value for N: ");
   scanf("%d", &N);

   if (N <= 0)
   {
      printf("Enter only positive value or value less than %d\n", MAXINT);
      exit(1);
   }

   printf("Enter value: ");
   scanf("%d", &num);
   max = num;

   if (max < 0)
   {
      printf("Enter only positive values or value less than %d\n", MAXINT);
      exit(2);
   }

   if (N == 1)
   {
      printf("Maximum is %d\n", max);
      exit(0);
   }

   for (i = 1; i <= N-1; i++)
   {
      printf("Enter value: ");
      scanf("%d", &nextnum);

      if (nextnum < 0)
      {
         printf("Enter only positive values or value less than %d\n", MAXINT);
         exit(2);
      }

      if (nextnum > max)
      {
         max = nextnum;
      }
   }

   printf("Maximum of the given %d numbers is %d\n", N,max);
   exit(0);
}
