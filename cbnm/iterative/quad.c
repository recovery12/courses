/***************** Usage: For finding the real of the ******************************************** quadratic equation ax^2 + bx^1 + c *************************
****************** taking the values of the coeffients ************************/

/************** Explanation: The program takes guess value, coeffients of the equation as the input and computes the root for the given equation using iterative method **************/

/*************** Given Equation: a*x^2 + b*x^1 + c **************/

/*************** The roots are same irrespective of the guess value but the no. of iterations change, it depends on the guess value ***************/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
float root1(float x0, float a, float b, float c);
float root2(float x0, float a, float b, float c);

/******** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float        guess, roots1, roots2, val;  //Declaration of variables
   float        a, b, c;  //Declaration of variables

   if (argc != 5)   // Verification of arguments
   {
      fprintf(stderr, "Usage: %s <x^2 coeff> <x^1 coeff> <x^0 coeff> <guess-value>\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]);        // Taking a, b, c as inputs from the user.
   b = atof(argv[2]);
   c = atof(argv[3]);

   val = ((b * b) - (4 * a * c));    // Value under the square root

   if (val < 0)          // Checking whether discriminant < zero
   {
      fprintf(stderr, "The given Equation has no real roots.\n");
      exit(2);
   }
   guess = atof(argv[4]);         // Conversion of argument

   roots1 = root1(guess, a, b, c);        // Calling the first root
   roots2 = root2(guess, a, b, c);        //Calling the second root

   printf("The roots are: %f & %f\n", roots1, roots2); //Printing of roots
   exit(0);
}

/********* FUNCTION DEFINITION *********/
/***** ROOT1 *****/
float root1(float x0, float a, float b, float c)
{
   int        i = 0;  //Declaration of variables in int
   float      x1;     //Declaration of variables in float

   while (1)           // Check condition
   {
      x1 = (-c / ((a * x0) + b));      // Equation for first root
      i = i + 1;                      // Incrementing i

      if (floorf(x0*10000) == floorf(x1*10000))  //Check for the approx. value
      {
         break;                //Getting out of the loop
      }

      x0 = x1;                 //Changing the value of x0
   }

   printf("The No. of iterations for first root is: %d\n", i);
   return x1;                  //Returning x1
}

/***** ROOT2 *****/
float root2(float x0, float a, float b, float c)
{
   int        i = 0;               //Declaration of variables in int
   float      x1;                           //Declaration of variables in float

   while (1)           // Check condition
   {
      x1 = ((-c / (a * x0)) - (b / a));    // Equation for second root
      i = i + 1;                      //Incrementing i

      if (floorf(x0*1000000) == floorf(x1*1000000))  //Check for the approx. value
      {
         break;                //Getting out of the loop
      }

      x0 = x1;                // Changing value of x0
   }

   printf("The No. of iterations for second root is: %d\n", i);
   return x1;                //Returning x1
}
