#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int read_data(FILE *ifp, char infile[], int Table[]);
int print_data(int nitems, int Table[]);
void quick_sort(int Table[], int nitems);
void swap(int *a, int *b);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        nitems, Table[MAX];
   char       *infile;
   FILE       *ifp = NULL;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
      exit(0);
   }

   infile = argv[1];

   nitems = read_data(ifp, infile, Table);
   print_data(nitems, Table);

   quick_sort(Table, nitems);
   print_data(nitems, Table);

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

void quick_sort(int Table[], int nitems)
{
   int        i, j, count = 0;

   for (i = (nitems-1); i > 0; i--)
   {
      for (j = 0; j < nitems; j++)
      {
         if (Table[i] < Table[j] && count ==0 && (j-i) == 1)
         {
            swap(&Table[i], &Table[i-1]);
            swap(&Table[i], &Table[j]);
         }
         else
         {
            swap(&Table[i], &Table[j]);
            count = 1;
         }
      }
   }

   return ;
}

void swap(int *a, int *b)
{
   int        temp;

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}

