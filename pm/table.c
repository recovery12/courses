#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        62

/********* FUNCTION DECLARATION *********/
int read_data(FILE *ifp, char infile[], int Table[]);
int print_data(int nitems, int Table[]);
void rm_ele(int pos, int Table[], int nitems);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        nitems, Table[MAX], pos = 6, tn;
   char       *infile;
   FILE       *ifp = NULL;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <in-filename>\n", argv[0]);
      exit(1);
   }

   infile = argv[1];


   nitems = read_data(ifp, infile, Table);
   print_data(nitems, Table);

   rm_ele(pos, Table, nitems);
   print_data(nitems-1, Table);

   tn = rm_dup(Table, nitems);
   print_data(nitems-tn, Table);
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
         printf("!!! MAXIMUM LIMIT OF THE TABLE REACHED !!!\n You can't values more than this\n");
         exit(1);
      }
   }
   fclose(ifp);
   return i;
}

int print_data(int nitems, int Table[])
{
   int        i = 0;

   for (i = 0; i < nitems; i++)
   {
      printf("%d ", Table[i]);
   }
   printf("\n");
   printf("The number of elements in the Table is %d\n", nitems);
   return 0;
}

void rm_ele(int pos, int Table[], int nitems)
{
   int        i;

   for (i = pos-1; i < nitems; i++)
   {
      Table[i] = Table[i+1];
   }
   return ;
}

int rm_dup(int Table[], int nitems)
{
   int        i, j, n = 0;

   for (i = 0; i < (nitems-n); i++)
   {
      for (j = i+1; j < (nitems-n); j++)
      {
         if (Table[j] == Table[i])
         {
            n = n + 1;
            rm_ele(j-1, Table, (nitems-n));
         }
      }
   }

   return n;
}
