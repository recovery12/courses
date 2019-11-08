#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
void find_num(int n, int d);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        n, d;

   printf("Specify the range: ");
   scanf("%d", &n);

   printf("Enter the digit: ");
   scanf("%d", &d);

   find_num(n, d);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void find_num(int n, int d)
{
   int        i, num, num_sp, rem;

   printf("These numbers contain the digit %d\n\n", d);
   for (i = 1; i < n+1; i++)
   {
      num = i;
      num_sp = i;

      while (num_sp != 0)
      {
         rem = num_sp % 10;
         num_sp = num_sp / 10;

         if (rem == d)
         {
            printf("%d ", num);
            break;
         }
      }
   }
   printf("\n");

   return ;
}
