#include <stdio.h>
#include <stdlib.h>

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        dig;

   printf("Enter a character: ");
   scanf("%d", &dig);

   if (dig >= '0' || dig <= '9')
   {
      printf("Entered character is a digit.");
      return 0;
   }
   else
   {
      printf("Entered character is not a digit.");
      return 1;
   }

   exit(0);
}
