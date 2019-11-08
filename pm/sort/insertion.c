#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int read_data(FILE *ifp, char infile[], int Table[]);
int print_data(int nitems, int Table[]);
void insertion_sort(int Table1[], int nitems, int Table2[]);
void insert_ele(int j, int Table2[], int added, int Table1[]);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        nitems, Table1[MAX], Table2[MAX];
   char       *infile;
   FILE       *ifp = NULL;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
      exit(0);
   }

   infile = argv[1];

   nitems = read_data(ifp, infile, Table1);
   print_data(nitems, Table1);

   insertion_sort(Table1, nitems, Table2);
   print_data(nitems, Table2);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int read_data(FILE *ifp, char infile[], int Table[])
{
   int        i = 0;
   char       eof;

   if ((ifp = fopen(infile, "r")) == NULL)
   {
      printf("Error in opening file %s\n", infile);
      exit(1);
   }

   if ((eof = fgetc(ifp)) == EOF)
   {
      fprintf(stderr, "Enter some elements to perform sorting operation.\n");
      exit(2);
   }

   rewind(ifp);
   while (fscanf(ifp, "%d", &Table[i]) != EOF)
   {
      i = i + 1;
      if (i == MAX)
      {
         printf("!!! MAXIMUM LIMIT OF THE TABLE REACHED !!!\n You can't values more than this");
         exit(1);
      }
   }
   fclose(ifp);
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

void insertion_sort(int Table1[], int nitems, int Table2[])
{
   int        i, j, added, watch = 0;

   Table2[0] = Table1[0];
   added = 1;

   for (i = 1; i < nitems; i++)
   {
      watch = 0;
      for (j = 0; j < added; j++)
      {
         if (Table1[i] < Table2[j+1])
         {
            insert_ele(j+1, Table2, added, Table1);
            added = added + 1;
            watch = 1;
            break;
         }
      }

      if (watch == 0)
      {
         Table2[added] = Table1[i];
         added = added + 1;
      }
      printf("%d\n", Table2[j]);
   }

   return ;
}

void insert_ele(int j, int Table2[], int added, int Table1[])
{
   int        i = 0;

   for (i = added; i >= j; i--)
   {
      Table2[i+1] = Table2[i];
   }

   Table1[j] = Table2[i];

   return ;
}
