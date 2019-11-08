#include <stdio.h>
#include <stdlib.h>
#include "setop.h"

/********* FUNCTION DEFINITION *********/
/****** DO_UNION ******/
void do_union(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[])
{
   printf("Enter the filename which contains SetA:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in opening file %s\n", filename1);
      exit(1);
   }

   NA = read_data(fp1, set_A);
   print_data(set_A, NA);
   printf("The cardinality of the SetA is %d\n", NA);
   fclose(fp1);

   printf("Enter the filename which contains SetB:\n");
   scanf("%s", filename2);

   fp2 = fopen(filename2, "r");

   if (fp2 == NULL)
   {
      printf("Error in opening file %s\n", filename2);
      exit(1);
   }

   NB = read_data(fp2, set_B);
   if (NB == 0)
   {
      print_data(set_A, NA);
      exit(1);
   }
   print_data(set_B, NB);
   printf("The cardinality of the SetB is %d\n", NB);
   fclose(fp2);

   uni(set_A, NA, set_B, NB, set_C);
   return ;
}

/****** DO_INTERSECTION ******/
void do_intersec(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[])
{
   printf("Enter the filename which contains SetA:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in opening file %s\n", filename1);
      exit(1);
   }

   NA = read_data(fp1, set_A);
   if (NA == 0)
   {
      printf("SetC is { }\n");
      exit(1);
   }
   print_data(set_A, NA);
   printf("The cardinality of the SetA is %d\n", NA);
   fclose(fp1);

   printf("Enter the filename which contains SetB:\n");
   scanf("%s", filename2);

   fp2 = fopen(filename2, "r");

   if (fp2 == NULL)
   {
      printf("Error in opening file %s\n", filename2);
      exit(1);
   }

   NB = read_data(fp2, set_B);
   if (NB == 0)
   {
      printf("SetC is { }\n");
      exit(1);
   }
   print_data(set_B, NB);
   printf("The cardinality of the SetB is %d\n", NB);
   fclose(fp2);

   intersec(set_A, NA, set_B, NB, set_C);
   return ;
}

/****** DO_MEMBERSHIP ******/
void do_membership(int set_A[], int NA, int sval, FILE *fp1, char filename1[])
{
   enum boolean status;

   printf("Enter the filename which contains SetA:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in opening file %s\n", filename1);
      exit(1);
   }

   NA = read_data(fp1, set_A);
   if (NA == 0)
   {
      printf("You have entered an empty\n Please enter a non-empty set for the search operation\n");
      exit(2);
   }

   print_data(set_A, NA);
   printf("The cardinality of the SetA is %d\n", NA);
   fclose(fp1);

   printf("Enter the value to be searched: ");
   scanf("%d", &sval);

   status = member_ship(set_A, NA, sval);
   printf("Status = %s\n", status?"FOUND":"NOT FOUND");
   return ;
}

/****** DO_SUBSET ******/
void do_subset(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[])
{
   enum boolean stat;

   printf("Enter the filename which contains SetA:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in opening file %s\n", filename1);
      exit(1);
   }

   NA = read_data(fp1, set_A);
   if (NA == 0)
   {
      printf("You have entered an empty\nPlease enter a non-empty set.\n");
      exit(2);
   }
   print_data(set_A, NA);
   printf("The cardinality of the SetA is %d\n", NA);
   fclose(fp1);

   printf("Enter the filename which contains SetB:\n");
   scanf("%s", filename2);

   fp2 = fopen(filename2, "r");

   if (fp2 == NULL)
   {
      printf("Error in opening file %s\n", filename2);
      exit(1);
   }

   NB = read_data(fp2, set_B);
   if (NB == 0)
   {
      printf("You have entered an empty set\nIt is the subset of every set\n");
      exit(2);
   }
   print_data(set_B, NB);
   printf("The cardinality of the SetB is %d\n", NB);
   fclose(fp2);

   stat = subset(set_A, NA, set_B, NB, set_C);
   printf("stat = %s\n", stat?"SUBSET":"NO SUBSET");
   return ;
}

/****** DO_DIFFERENCE ******/
void do_diff(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[])
{
   printf("Enter the filename which contains SetA:\n");
   scanf("%s", filename1);

   fp1 = fopen(filename1, "r");

   if (fp1 == NULL)
   {
      printf("Error in opening file %s\n", filename1);
      exit(1);
   }

   NA = read_data(fp1, set_A);
   if (NA == 0)
   {
      printf("SetC is { }\n");
      exit(1);
   }
   print_data(set_A, NA);
   printf("The cardinality of the SetA is %d\n", NA);
   fclose(fp1);

   printf("Enter the filename which contains SetB:\n");
   scanf("%s", filename2);

   fp2 = fopen(filename2, "r");

   if (fp2 == NULL)
   {
      printf("Error in opening file %s\n", filename2);
      exit(1);
   }

   NB = read_data(fp2, set_B);
   if (NB == 0)
   {
      print_data(set_A, NA);
      exit(1);
   }
   print_data(set_B, NB);
   printf("The cardinality of the SetB is %d\n", NB);
   fclose(fp2);

   diff(set_A, NA, set_B, NB, set_C);
   return ;
}

/***** UNION *****/
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

/***** INTERSECTION *****/
void intersec(int set_A[], int NA, int set_B[], int NB, int set_C[])
{
   int        i, j, NC = 0;

   printf("SetC is { ");
   for (i = 0; i < NA; i++)
   {
      for (j = 0; j < NB; j++)
      {
         if (set_A[i] == set_B[j])
         {
            set_C[NC] = set_A[i];
            printf("%d ", set_C[NC]);
            NC = NC + 1;
            break;
         }
      }
   }
   printf("}");
   printf("\n");
   printf("The cardinality of SetC is %d", NC);
   return ;
}

/***** MEMBERSHIP *****/
int member_ship(int set_A[], int NA, int sval)
{
   int        i;

   for (i = 0; i < NA; i++)
   {
      if (set_A[i] == sval)
      {
         return 1;
      }
   }
   return 0;
}

/***** SUBSET *****/
int subset(int set_A[], int NA, int set_B[], int NB, int set_C[])
{
   int        i, j, count_B;

   count_B = 0;

   for (i = 0; i < NB; i++)
   {
      for (j = 0; j < NA; j++)
      {
         if (set_A[j] == set_B[i])
         {
            count_B = count_B + 1;
            break;
         }
      }
      if (count_B == NB)
      {
         return 1;
      }
   }
   return 0;
}

/***** DIFFERENCE *****/
void diff(int set_A[], int NA, int set_B[], int NB, int set_C[])
{
   int        i, j, NC = 0, found;

   printf("SetC is { ");
   found = 0;
   for (i = 0; i < NA; i++)
   {
      for (j = 0; j < NB; j++)
      {
         if (set_A[i] == set_B[j])
         {
            found = 1;
            break;
         }
      }

      if (found == 0)
      {
         set_C[NC] = set_A[i];
         printf("%d ", set_C[NC]);
         NC = NC + 1;
      }
      found = 0;
   }
   printf("}");
   printf("\n");
   printf("The cardinality of SetC is %d\n", NC);
   return ;
}
