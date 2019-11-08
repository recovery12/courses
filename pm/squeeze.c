#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int read_data(FILE *fp, char *filename, int Table[]);
int print_data(int Table[], int nitems);
int rm_element(int K, int Table[], int nitems);
void squeeze(int Table[], int num, int l, int nitems);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        K, nitems, totn;
   int        Table[MAX];
   FILE       *fp = NULL;
   char       *filename;

   if (argc != 3)
   {
     fprintf(stderr, "Usage: %s <filename> <frequency>\n", argv[0]);
     exit(1);
   }

   filename = argv[1];

   nitems = read_data(fp, filename, Table);
   printf("The table you have entered is: \n");
   print_data(Table, nitems);

   K = atoi(argv[2]);

   if (K < 0)
   {
      printf("Enter a +ve number for the frequency.\n");
      exit(2);
   }
   else if (K == 0)
   {
      printf("All the values in the table are removed.\n");
      printf("\n");
      exit(0);
   }

   totn = rm_element(K, Table, nitems);
   printf("The Squeezed table: \n");
   print_data(Table, totn);
}

/********* FUNCTION DEFINITION *********/
int read_data(FILE *fp, char *filename, int Table[])
{
   int        i = 0;

   fp = fopen(filename, "r");

   if (fp == NULL)
   {
      printf("Error in opening file %s\nOnce check the filename or it's permissions.", filename);
      exit(0);
   }

   while (fscanf(fp, "%d", &Table[i]) != EOF)
   {
      i = i + 1;

      if (i == MAX)
      {
         printf("!!! MAXIMUM LIMIT OF THE TABLE REACHED !!!\n");
         exit(0);
      }
   }

   fclose(fp);
   return i;
}

int print_data(int Table[], int nitems)
{
   int        i;

   for (i = 0; i < nitems; i++)
   {
      printf("%d ", Table[i]);
   }

   printf("\n");
   return 0;
}

int rm_element(int K, int Table[], int nitems)
{
   int        i = 0, j, l = 0, n = 0, num, count = 0;
   int        freq[MAX];

   while (i < nitems)
   {
      if (count == 0)
      {
      num = Table[l];
      freq[num] = 1;
      count = 1, j = l;
      }

      if (Table[j+1] == num)
      {
         freq[num] = freq[num] + 1;
      }
      else
      {
         l = j + 1;
         if (freq[num] > K)
         {
            l = l - freq[num];
            squeeze(Table, num, l, nitems);
            n = n + freq[num];
         }
         count = 0;
      }
      i = i + 1, j = j + 1;
   }

   if ((freq[num]-1) > K)
   {
      squeeze(Table, num, l, nitems);
      n = n + (freq[num] - 1);
   }

   n = nitems - n;
   return n;
}

void squeeze(int Table[], int num, int l, int nitems)
{
   int        i, j;

   for (i = l, j = l; i < nitems; i++)
   {
      if (Table[i] != num)
      {
         Table[j++] = Table[i];
      }
   }
   return ;
}
