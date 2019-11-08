#include <stdio.h>
#include <stdlib.h>

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        N,num,givnum,count,i;

   printf("Enter the value for N: ");
   scanf("%d", &N);

   if (N <= 0)
   {
      printf("Enter a valid input for N\n");
      exit(1);
   }

   printf("Enter the search value: ");
   scanf("%d", &givnum);
   count = 0;

   for (i = 1; i <= N; i++)
   {
      printf("Enter the value: ");
      scanf("%d", &num);

      if (givnum == num)
      {
         count++;
      }
   }
   printf("The frequency of %d in given numbers is %d\n", givnum,count);
   exit(0);
}
