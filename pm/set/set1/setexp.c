#include <stdio.h>
#include <stdlib.h>

#define   MAX        20
void do_union(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1);
void read_file(char filename1, FILE *fp1, int NA, int set_A[]);
int read_data(FILE *fp1, int set_A[]);
int print_data(int set_A[], int NA);
void uni(int set_A[], int NA, int set_B[], int NB, int set_C[]);

int main(void)
{
   int        set_A[MAX], NA = 0, set_B[MAX], NB = 0, set_C[MAX], option;
   FILE       *fp1 = NULL, *fp2 = NULL;
   char       filename1[MAX+1], filename2[MAX+1];

   printf("Select a set operation:-\n");
   printf("   1) Union of Sets\n");
   printf("   2) Intersection of Sets\n");
   printf("   3) Membership of Sets\n");
   printf("   4) Subset of Sets\n");
   printf("   5) Difference of Sets\n");

   printf("Your option please: ");
   scanf("%d", &option);

   if (option < 1 || option > 5)
   {
      printf("Select the options which are given above\n");
      exit(1);
   }

   switch (option)
   {
      case 1:
             do_union(set_A, NA, set_B, NB, set_C, fp1, filename1, fp2, filename2);
             break;
      case 2:
               printf("test");
               break;
   }

   exit(0);
}

void read_file(char filename1, FILE *fp1, int NA, int set_A[])
{
   printf("Enter the filename which contains set:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in file opening %s", filename1);
      exit(1);
   }

   NA = read_data(fp1, set_A);
   printf("SetA = %d", NA);
   fclose(fp1);
   return ;
}

int read_data(FILE *fp1, int set_A[])
{
   int        i = 0;

   while (fscanf(fp1, "%d", &set_A[i]) != EOF)
   {
      i = i + 1;
      if (i == MAX)
      {
         printf("!!! Maximum limit of the set has reached !!!\n");
         printf("Enter values such that total number is <= %d\n", MAX);
         exit(2);
      }
   }
   return i;
}

int print_data(int set_A[], int NA)
{
   int        i;

   printf("Set you have entered { ");
   for (i = 0; i < NA; i++)
   {
      printf("%d ", set_A[i]);
   }
   printf("}");
   printf("\n");
   return 0;
}

void do_union(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1)
{
             read_file(fp1, set_A, NA, filename1);
             print_data(NA, set_A);

             read_file(fp2, set_B, NB, filename2);
             print_data(NB, set_B);
             uni(set_A, NA, set_B, NB, set_C);
   return;
}

void uni(int set_A[], int NA, int set_B[], int NB, int set_C[])
{
   int        i, j, l, NC = 0, match;

   printf("SetC is { ");
   for (l = 0; l < NA; l++)
   {
      set_C[NC] = set_A[l];
      printf("%d ", set_C[NC]);
      NC = NC + 1;
   }

   match = 0;

   for (i = 0; i < NB; i++)
   {
      for (j = 0; j < NA; j++)
      {
         if (set_A[j] == set_B[i])
         {
            match = 1;
            break;
         }
      }
      if (match == 0)
      {
         NC = NC + 1;
         set_C[NC] = set_B[i];
         printf("%d ", set_C[NC]);
      }
      match = 0;
   }
   printf("}");
   printf("\n");
   printf("The cardinality of SetC is %d\n", NC);
   return ;
}
