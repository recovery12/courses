#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
double root1(double x0);

/******** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   double        guess, roots1;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <guess-value>\n", argv[0]);
      exit(1);
   }

   guess = atof(argv[1]);

   roots1 = root1(guess);

   printf("The root is: %lf\n", roots1);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
double root1(double x0)
{
   int        check = 0;
   double      x1, cosine;

   while (check == 0)
   {
      cosine = cos(x0);

      x1 = ((cosine + 1) / 3);
      printf("Root is %lf\n", x1);

      if (x0 == x1)
      {
         check = 1;
         break;
      }
      x0 = x1;
   }

   return x1;
}
