#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/

#define  MAXI        30

/********* MAIN STARTS HERE *********/
int main(void)
{
   char       name[MAXI];
   printf("Enter a name: ");
   scanf("%s", name);
   printf("Hello %s\n", name);
   exit(0);
}
