#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 17MCME07, 17MCME10   Subhash sarangi Mahesh chandra

/********* DEFINED CONSTANTS *********/
#define   MAX       50

/********* FUNCTION DECLARATION *********/
int menu();
void print_set(int set[], int n);
void create_set(int set[], int n);
bool is_member(int set[], int n, int val);
bool subset(int seta[], int setb[], int n1, int n2);
bool superset(int seta[], int setb[], int n1, int n2);
int set_union(int seta[], int setb[], int setc[], int n1, int n2);
int set_intersection(int seta[], int setb[], int setc[], int n1, int n2);
int set_difference(int seta[], int setb[], int setc[], int n1, int n2);
int set_sym_diff(int seta[], int setb[], int setc[], int n1, int n2);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        opt, n1, n2, n3, val;
   int        seta[MAX], setb[MAX], setc[MAX];
   bool       check;

   printf("Enter the number of elements in setA: ");
   scanf("%d", &n1);
   create_set(seta, n1);

   printf("Enter the number of elements in setB: ");
   scanf("%d", &n2);
   create_set(setb, n2);

   opt = menu();
   switch (opt)
   {
      case 1:
            n3 = set_union(seta, setb, setc, n1, n2);
            print_set(setc, n3);
            break;
      case 2:
            n3 = set_intersection(seta, setb, setc, n1, n2);
            print_set(setc, n3);
            break;
      case 3:
            n3 = set_difference(seta, setb, setc, n1, n2);
            print_set(setc, n3);
            break;
      case 4:
            n3 = set_sym_diff(seta, setb, setc, n1, n2);
            print_set(setc, n3);
            break;
      case 5:
            printf("Enter the value: ");
            scanf("%d", &val);
            check = is_member(seta, n1, val);
            if (check)
            {
               printf("Is a member\n");
            }
            else
            {
               printf("Not a member\n");
            }
            break;
      case 6:
            check = subset(seta, setb, n1, n2);
            if (check)
            {
               printf("Is a subset\n");
            }
            else
            {
               printf("Not a subset\n");
            }
            break;
      case 7:
            check = superset(seta, setb, n1, n2);
            if (check)
            {
               printf("Is a superset\n");
            }
            else
            {
               printf("Not a superset\n");
            }
            break;
      case 8:
            exit(0);
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void print_set(int set[], int n)
{
   int        i;

   printf("{");
   for (i = 0; i < n; i++)
   {
      printf("%d, ", set[i]);
   }
   printf("}\n");

   return ;
}

void create_set(int set[], int n)
{
   int        i = 0, val;

   while (i < n)
   {
      scanf("%d", &val);
      if (!is_member(set, n, val))
      {
         set[i] = val;
         i++;
      }
   }

   return ;
}

bool is_member(int set[], int n, int val)
{
   int        i;

   for (i = 0; i < n; i++)
   {
      if (set[i] == val)
      {
         return true;
      }
   }

   return false;
}

int set_union(int seta[], int setb[], int setc[], int n1, int n2)
{
   int        i, k;

   for (i = 0; i < n1; i++)
   {
      setc[i] = seta[i];
   }

   k = i;
   for (i = 0; i < n2; i++)
   {
      if (!is_member(setc, k, setb[i]))
      {
         setc[k] = setb[i];
         k++;
      }
   }

   return k;
}

int set_intersection(int seta[], int setb[], int setc[], int n1, int n2)
{
   int        i, k = 0;

   for (i = 0; i < n1; i++)
   {
      if (is_member(setb, n2, seta[i]))
      {
         setc[k] = seta[i];
         k++;
      }
   }

   return k;
}

int set_difference(int seta[], int setb[], int setc[], int n1, int n2)
{
   int        i, k = 0;

   for (i = 0; i < n1; i++)
   {
      if (!is_member(setb, n2, seta[i]))
      {
         setc[k] = seta[i];
         k++;
      }
   }

   return k;
}

int set_sym_diff(int seta[], int setb[], int setc[], int n1, int n2)
{
   int        n3, tn1, tn2, ts1[MAX], ts2[MAX];

   tn1 = set_difference(seta, setb, ts1, n1, n2);
   tn2 = set_difference(setb, seta, ts2, n2, n1);
   n3 = set_union(ts1, ts2, setc, tn1, tn2);

   return n3;
}

bool subset(int seta[], int setb[], int n1, int n2)
{
   int        i, j, count = 0;

   for (i = 0; i < n1; i++)
   {
      for (j = 0; j < n2; j++)
      {
         if (seta[i] == setb[j])
         {
            count = count + 1;
         }
      }
   }

   if (count == n1)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool superset(int seta[], int setb[], int n1, int n2)
{
   int        i, j, count = 0;

   for (i = 0; i < n2; i++)
   {
      for (j = 0; j < n1; j++)
      {
         if (seta[i] == setb[j])
         {
            count = count + 1;
         }
      }
   }

   if (count == n2)
   {
      return true;
   }
   else
   {
      return false;
   }
}

int menu()
{
   int       option;

   printf("\n----------------------------\n");
   printf("        Set operations        \n");
   printf("----------------------------  \n");
   printf("1) Union\n");
   printf("2) Intersection\n");
   printf("3) Difference\n");
   printf("4) Symmteric Difference\n");
   printf("5) Is member\n");
   printf("6) Is subset\n");
   printf("7) Is superset\n");
   printf("8) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}
