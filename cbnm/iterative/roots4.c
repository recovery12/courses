/***************** Usage: For finding the real of the ******************************************** quadratic equation 3x - cos(x) - 1 ************************/

/************** Explanation: The program takes guess value as the input and computes the root for the given equation using iterative method **************/

/*************** Given Equation: 3x - cos(x) - 1 **************/
/*************** Guess Value: 0.6 **************/
/*************** Roots are: 0.607102 **************/

/*************** The roots are same irrespective of the guess value but the no. of iterations change, it depends on the guess value ***************/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
float root1(float x0);

/******** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float        guess, roots1;             //Declaration of variables in float

   if (argc != 2)                         // Verification of argumrnts
   {
      fprintf(stderr, "Usage: %s <guess-value>\n", argv[0]);
      exit(1);
   }

   guess = atof(argv[1]);           //Conversion of arguments

   roots1 = root1(guess);           // Calling the root

   printf("The root is around %f\n", roots1); //Printing roots
   exit(0);
}

/********* FUNCTION DEFINITION *********/
float root1(float x0)
{
   int        check = 0, i = 0;         //Declaration of variables in int
   float      x1, cosine;               //Declaration of variables in float

   while (check == 0)         // Check condition
   {
      cosine = cosf(x0);       // Value of cosine at x0

      x1 = ((cosine + 1) / 3);       // Equation for first root

      if (floor(x0*10000000)/10000000 == floor(x1*10000000)/10000000)          
      {
         check = 1;
         break;                   //Getting out of the loop
      }
      i++;                        //Incrementing i
      x0 = x1;                    //Changing the value of x0

      if (i > 1000000)            //Checking the value of i
      {
         return x1;
      }
   }

   return x1;                     // Returning the root
}
