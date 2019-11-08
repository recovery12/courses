#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DEFINITION *********/
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
:x
:x
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
   printf("The cardinality of SetC is %d\n", NC);
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
