#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        100

/********* FUNCTION DECLARATION *********/
void linear(float sumx, float sumy, float sumxy, float sumx2, int nitems);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int          nitems, i;
   float        x[MAX], y[MAX], x2[MAX], xy[MAX];
   float        sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;

   printf("Enter the Number of items:- ");
   scanf("%d", &nitems);

   printf("Enter the values of xi and yi, i = 1,2,3.....%d\n", nitems);
   printf("xi  yi\n");
   for (i = 0; i < nitems; i++)
   {
      scanf("%f %f", &x[i], &y[i]);
      xy[i] = x[i] * y[i];
      x2[i] = x[i] * x[i];
      sumx = sumx + x[i];
      sumy = sumy + y[i];
      sumxy = sumxy + xy[i];
      sumx2 = sumx2 + x2[i];
   }

   linear(sumx, sumy, sumxy, sumx2, nitems);
   exit(0);
}

void linear(float sumx, float sumy, float sumxy, float sumx2, int nitems)
{
   float        a, b;

   a = ((sumx*sumxy)-(sumx2*sumy))/((sumx*sumx)-(nitems*sumx2));
   b = ((sumx*sumy)-(nitems*sumxy))/((sumx*sumx)-(nitems*sumx2));

   printf("The Linear Equation is: y = (%.4f) + (%.4f)x\n", a, b);

   return ;
}
