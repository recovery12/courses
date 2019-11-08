#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        30

/********* FUNCTIONS *********/
int read_data(FILE *fp, int Table[MAX])
{
   int        nitems = 0;

   while (fscanf(fp, "%d", &Table[nitems]) != EOF)
   {
      nitems = nitems + 1;
   }
   return nitems;
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

int search_valuef(int Table[MAX], int nitems, int svalue)
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
   int        Table[MAX];
   int        nitems, svalue;
   FILE       *fp = NULL;
   char       filename[MAX];

   enum boolean {FALSE, TRUE};

   printf("Enter the file name: ");
   scanf("%s", filename);

   fp = fopen(filename, "r");

   if (fp == NULL)
   {
      printf("Error in opening file %s\n", filename);
      exit(0);
   }

   enum boolean found;

   nitems = read_data(fp, Table);
   print_data(Table, nitems);

   printf("Enter the search value: ");
   scanf("%d", &svalue);
   printf("\n");

   found = search_valuef(Table, nitems, svalue);
   fclose(fp);

   printf("status = %s\n", found?"FOUND":"NOT FOUND");
   exit(0);
}
