#include <stdio.h>
#include <stdlib.h>
#include "setop.h"

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        set_A[MAX], NA = 0, set_B[MAX], NB = 0, set_C[MAX], sval, option;
   FILE       *fp1 = NULL, *fp2 = NULL;
   char       filename1[MAX+1], filename2[MAX+1];

   enum boolean status, stat;

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
             NA = read_data(fp1, set_A, filename1);
             print_data(set_A, NA);
             NB = read_data(fp2, set_B, filename2);
             if (NB == 0)
             {
                print_data(set_A, NA);
                exit(1);
             }
             print_data(set_B, NB);

             uni(set_A, NA, set_B, NB, set_C);
             break;
      case 2:
             NA = read_data(fp1, set_A, filename1);
             if (NA == 0)
             {
                printf("SetC is { }\n");
                printf("The cardinality of the set is 0\n");
                exit(1);
             }
             print_data(set_A, NA);
             NB = read_data(fp2, set_B, filename2);
             if (NB == 0)
             {
                printf("SetC is { }\n");
                printf("The cardinality of the set is 0\n");
                exit(1);
             }
             print_data(set_B, NB);

             intersec(set_A, NA, set_B, NB, set_C);
             break;
      case 3:
             NA = read_data(fp1, set_A, filename1);
             if (NA == 0)
             {
                printf("You have entered an empty\n Please enter a non-empty set for the search operation\n");
                exit(2);
             }
             print_data(set_A, NA);
             printf("Enter the value to be searched: ");
             scanf("%d", &sval);

             status = member_ship(set_A, NA, sval);
             printf("%d %s\n", sval, status?"IS A MEMBER OF SET":"IS NOT A MEMBER OF SET");
             break;
      case 4:
             NA = read_data(fp1, set_A, filename1);
             if (NA == 0)
             {
                printf("You have entered an empty\nPlease enter a non-empty set.\n");
                exit(2);
             }
             print_data(set_A, NA);
             NB = read_data(fp2, set_B, filename2);
             if (NB == 0)
             {
                printf("You have entered an empty set\nIt is the subset of every set and given set too\n");
                exit(2);
             }
             print_data(set_B, NB);

             stat = subset(set_A, NA, set_B, NB, set_C);
             printf("%s\n", stat?"SETB IS A SUBSET SETA":"SETB IS NOT A SUBSET SETA");
             break;
      case 5:
             NA = read_data(fp1, set_A, filename1);
             if (NA == 0)
             {
                printf("SetC is { }\n");
                printf("The cardinality of the set is 0\n");
                exit(1);
             }
             print_data(set_A, NA);
             NB = read_data(fp2, set_B, filename2);
             if (NB == 0)
             {
                print_data(set_A, NA);
                exit(1);
             }
             print_data(set_B, NB);

             diff(set_A, NA, set_B, NB, set_C);
             break;
   }
   exit(0);
}

int read_data(FILE *fp1, int set_A[], char filename1[])
{
   int        i = 0;

   printf("Enter the filename which contains set:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in file opening %s\n", filename1);
      exit(1);
   }

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
   fclose(fp1);
   return i;
}

int print_data(int set_A[], int NA)
{
   int        i;

   printf("Set is { ");
   for (i = 0; i < NA; i++)
   {
      printf("%d ", set_A[i]);
   }
   printf("}");
   printf("\n");
   printf("The cardinality of Set is %d\n", NA);
   return 0;
}
