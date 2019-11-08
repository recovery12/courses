/***************** Usage: For finding the real of the ******************************************** quadratic equation xlog(x) - 1.2 ************************/

/************** Explanation: The program takes guess value as the input and computes the root for the given equation using iterative method **************/

/*************** Given Equation: xlog(x) - 1.2 **************/
/*************** Guess Value: 2.5 **************/
/*************** Roots are: 2.740659 **************/

/*************** The roots are same irrespective of the guess value but the no. of iterations change, it depends on the guess value ***************/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
float root1(float x0);
float function(float x);

/******** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float        guess, roots;  //Declaration of variables in float

   if (argc != 2)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <guess-value>\n", argv[0]);
      exit(1);
   }

   guess = atof(argv[1]);  //Conversion of arguments

   roots = root1(guess);  // Calling root

   printf("The root is around %f\n", roots); //Printing root
   exit(0);
}

/********* FUNCTION DEFINITION *********/
float root1(float x0)
{
   int        i = 0; //Declaration of variables in int
   float      x1;    //Declaration of variables in float

   while (1)  // Check condition
   {
      x1 = function(x0);  // Equation

      if (floor(x0*10000000) == floor(x1*10000000))
      {
         break;
      }
      i++;                     // Incrementing i
      x0 = x1;                //Changing value of x0
   }

   return x1;                  //Returning the value of x1
}

float function(float x)
{
   float        fx; //Declaration of variables in float

   fx = 1.2/log10f(x);
   return fx;
}
