#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTIONS *********/
int read_data(int Table[MAX])
{
   int        i;

   for (i = 0; i < MAX; i++)
   {
      printf("Enter the value in table: ");
      scanf("%d", &Table[i]);

      if (Table[i] == -1)
      {
         return i;
      }
   }
   printf("Cannot enter more than %d items\n", MAX);
   return i;
}

int print_data(int Table[MAX], int nitems)
{
   int        i;

   if (nitems ==  0)
   {
      printf("No values are entered to be displayed\n");
      exit(1);
   }

   printf("\n");
   printf("The Table you have entered is: \n");
   for (i = 0; i < nitems; i++)
   {
      printf("%d ", Table[i]);
   }
   printf("\n");
   return 0;
}

int search_value(int Table[MAX], int nitems, int svalue)
{
   int        i;

   for (i = 0; i < nitems; i++)
   {
      if (Table[i] == svalue)
      {
         printf("The location of the element is %d\n", i+1);
         return 1;
      }
   }
   return 0;
}

/********* MAIN STARTS HERE *********/
int main(void)
{
   enum boolean {FALSE, TRUE};

   int        nitems, svalue;
   int        Table[MAX];

   enum boolean found;

   nitems = read_data(Table);

   printf("Total number of values entered are %d\n", nitems);
   print_data(Table, nitems);

   printf("\n");

   printf("Enter the search value: ");
   scanf("%d", &svalue);

   found = search_value(Table, nitems, svalue);
   printf("Value = %s\n", found?"found":"not found");

   exit(0);
}
