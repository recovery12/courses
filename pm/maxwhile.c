#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        num, nextnum, max;

   printf("Enter the value: ");
   scanf("%d", &num);

   if (num == -1)
   {
      printf("No numbers are entered\n");
      exit(1);
   }
   else if (num < 0 && num != -1)
   {
      printf("Enter only positive numbers or numbers less than %d\n", MAXINT);
      exit(2);
   }

   max = num;
   while (num != -1)
   {
      printf("Enter the value: ");
      scanf("%d", &nextnum);

      if (nextnum == -1)
      {
         printf("Maximum of given numbers is %d\n", max);
         exit(0);
      }
      else if (nextnum < 0 && nextnum != -1)
      {
         printf("Enter only positive numbers or numbers less than %d\n", MAXINT);
         exit(2);
      }
      else if (nextnum > max)
      {
         max = nextnum;
      }
   }

   printf("Maximum of given numbers is %d\n", max);
   exit(0);
}
