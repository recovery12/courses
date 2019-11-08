#include <stdio.h>
#include <stdlib.h>
#include "setop.h"

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        set_A[MAX], NA = 0, set_B[MAX], NB = 0, set_C[MAX], sval = 0, option;
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
             do_intersec(set_A, NA, set_B, NB, set_C, fp1, filename1, fp2, filename2); 
             break;
      case 3:
             do_membership(set_A, NA, sval, fp1, filename1);
             break;
      case 4:
             do_subset(set_A, NA, set_B, NB, set_C, fp1, filename1, fp2, filename2);
             break;
      case 5:
             do_diff(set_A, NA, set_B, NB, set_C, fp1, filename1, fp2, filename2);
             break;
   }

   exit(0);
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
