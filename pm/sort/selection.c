#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int read_data(FILE *ifp, char infile[], int Table[]);
int print_data(int nitems, int Table[]);
void selection_sort(int Table[], int nitems);
int mini(int nitems, int Table[], int ind);
void swap(int *a, int *b);
int printin_file(FILE *ofp, char *outfile, int Table[], int nitems);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        nitems, Table[MAX];
   char       *infile, *outfile;
   FILE       *ifp = NULL, *ofp = NULL;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <in-filename> <out-filename>\n", argv[0]);
      exit(0);
   }

   infile = argv[1];
   outfile = argv[2];

   nitems = read_data(ifp, infile, Table);
   print_data(nitems, Table);

   selection_sort(Table, nitems);
   printin_file(ofp, outfile, Table, nitems);

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
   int        i = 0;

   for (i = 0; i < nitems; i++)
   {
      printf("%d ", Table[i]);
   }
   printf("\n");
   printf("The number of elements in the Table is %d\n", nitems);
   return 0;
}

void selection_sort(int Table[], int nitems)
{
   int        i, pos = 0;

   for (i = 0; i < nitems; i++)
   {
      pos = mini(nitems, Table, i);

      if (Table[i] > Table[pos] && i != pos)
      {
         swap(&Table[i], &Table[pos]);
      }

   }

   return ;
}

int mini(int nitems, int Table[], int ind)
{
   int        i, nxt_num, min, pos = ind;

   min = Table[ind];

   for (i = ind; i < (nitems-1); i++)
   {
      nxt_num = Table[i+1];

      if(nxt_num <= min)
      {
         min = nxt_num;
         pos = i + 1;
      }
   }

   return pos;
}

void swap(int *a, int *b)
{
   int        temp;

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}

int printin_file(FILE *ofp, char *outfile, int Table[], int nitems)
{
   int        i, eof;

   ofp = fopen(outfile, "w");
   if (ofp == NULL)
   {
      fprintf(stderr, "Error in opening file %s\n", outfile);
      exit(2);
   }

   /*if ((eof = fgetc(ofp)) != EOF)
   {
      fprintf(stderr, "over-writing in an existing file.\n");
   }
   else
   {
      fprintf(stderr, "writing in a new file.\n");
   }*/

   for (i = 0; i < nitems; i++)
   {
      fprintf(ofp, "%d ", Table[i]);
   }
   fprintf(ofp, "%c", '\n');

   fclose(ofp);
   return 0;
}
