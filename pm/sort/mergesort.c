#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
int read_data(FILE *fp1, char filename1[], int Table1[]);
int print_data(int N1, int Table1[]);
int merge_sort(int Table1[], int N1, int Table2[], int N2, int Table3[]);

/********* DEFINED CONSTANTS *********/
#define   MAX1       32
#define   MAX2       64

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        Table1[MAX1], Table2[MAX1], Table3[MAX2], N1 = 0, N2 = 0, N3 = 0;
   FILE       *fp1 = NULL, *fp2 = NULL;
   char       filename1[MAX1+1], filename2[MAX1+1]; 

   N1 = read_data(fp1, filename1, Table1);

   if (N1 == 0)
   {
      printf("You have entered a empty table.\n");
      printf("Enter a non-empty table to continue merge-sorting operation.\n");
      exit(1);
   }
   print_data(N1, Table1);
   N2 = read_data(fp2, filename2, Table2);

   if (N2 == 0)
   {
      printf("You have entered a empty table.\n");
      printf("Enter a non-empty table to continue merge-sorting operation.\n");
      exit(1);
   }
   print_data(N2, Table2);

   N3 = merge_sort(Table1, N1, Table2, N2, Table3);
   print_data(N3, Table3);
   exit(0);
}

int read_data(FILE *fp1, char filename1[], int Table1[])
{
   int        i = 0;

   printf("Enter the file name which contains the table:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in opening file %s\n", filename1);
      exit(1);
   }

   while (fscanf(fp1, "%d", &Table1[i]) != EOF)
   {
      i = i + 1;
      if (i == MAX1)
      {
         printf("!!! MAXIMUM LIMIT OF THE TABLE REACHED !!!\n You can't values more than this");
         exit(1);
      }
   }
   fclose(fp1);
   return i;
}

int print_data(int N1, int Table1[])
{
   int        i;

   for (i = 0; i < N1; i++)
   {
      printf("%d ", Table1[i]);
   }
   printf("\n");
   printf("The number of elements in the Table is %d\n", N1);
   return 0;
}

int merge_sort(int Table1[], int N1, int Table2[], int N2, int Table3[])
{
   int        i = 0, j = 0, k = 0, m = 0, n = 0;

   while (i + j <= N1 + N2 && i < N1 && j < N2)
   {
      if (Table1[i] < Table2[j])
      {
         Table3[k] = Table1[i];
         i = i + 1;
      }
      else if (Table1[i] > Table2[j])
      {
         Table3[k] = Table2[j];
         j = j + 1;
      }
      k = k + 1;
   }

   if (i == N1)
   {
      for (m = j; m <= N2; m++)
      {
         Table3[k] = Table2[m];
         k = k + 1;
      }
   }
   else
   {
      if (j == N2)
      {
         for (n = i; n <= N1; n++)
         {
            Table3[k] = Table1[n];
            k = k + 1;
         }
      }
   }
   return k-1;
}
