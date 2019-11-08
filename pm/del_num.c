#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int del_num(int nitemsi, int Tablei[], int K, int Tableo[]);
int read_data(FILE *fp, char *filename, int Table[]);
int print_data(int Table[], int nitems);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        K, nitemsi, nitemso;
   int        Tablei[MAX], Tableo[MAX];
   FILE       *fp = NULL;
   char       *filename;

   if (argc != 3)
   {
     fprintf(stderr, "Usage: %s <filename> <frequency>\n", argv[0]);
     exit(1);
   }

   filename = argv[1];

   nitemsi = read_data(fp, filename, Tablei);
   printf("The table you have entered is: \n");
   print_data(Tablei, nitemsi);

   K = atoi(argv[2]);

   if (K < 0)
   {
      printf("Enter a +ve number for the frequency.\n");
      exit(2);
   }
   else if (K == 0 && K == 1)
   {
      printf("None of the values in the Table are removed.\n"); 
      nitemso = del_num(nitemsi, Tablei, 1, Tableo);
      print_data(Tableo, nitemso);
      exit(0);
   }

   nitemso = del_num(nitemsi, Tablei, K, Tableo);
   print_data(Tableo, nitemso);
   exit(0);
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

int del_num(int nitemsi, int Tablei[], int K, int Tableo[])
{
   int        i, freq = 1, check = 0, n = 0;

   for (i = 0; i < nitemsi; i++)
   {
      if (Tablei[i+1] == Tablei[i])
      {
         freq = freq + 1;
      }
      else
      {
         if (freq >= K)
         {
            Tableo[n] = Tablei[i];
            check = 1;
            n = n + 1;
         }
         freq = 1;
      }
   }

   if (check == 0)
   {
      printf("The frequency of every number is less than %d\n", K);
   }

   return n;
}
