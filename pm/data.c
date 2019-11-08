#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int read_data(FILE *fp, char filename[], int Table[]);
int print_data(int nitems, int Table[]);

/********* FUNCTION DEFINITION *********/
int read_data(FILE *fp, char filename[], int Table[])
{
   int        i = 0;

   printf("Enter the file name which contains the table:\n");
   scanf("%s", filename);

   fp = fopen(filename, "r");

   if (fp == NULL)
   {
      printf("Error in opening file %s\n", filename);
      exit(1);
   }

   while (fscanf(fp, "%d", &Table[i]) != EOF)
   {
      i = i + 1;
      if (i == MAX)
      {
         printf("!!! MAXIMUM LIMIT OF THE TABLE REACHED !!!\n You can't values more than this");
         exit(1);
      }
   }
   fclose(fp);
   return i;
}

int print_data(int nitems, int Table[])
{
   int        i;

   for (i = 0; i < nitems; i++)
   {
      printf("%d ", Table[i]);
   }
   printf("\n");
   printf("The number of elements in the Table is %d\n", nitems);
   return 0;
}
