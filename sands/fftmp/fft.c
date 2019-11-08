#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

/********* DEFINED CONSTANTS ********/
#define MAX        100
#define J          sqrt(-1)
#define PI         acos(-1.0)

/********* FUNCTION DECLARATION *********/
void even_terms(float array[], float earr[], int s, int e);
void odd_terms(float array[], float oarr[], int s, int e);
void fft(float array[], int s, int e);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i, len = 0;
   float       array[MAX], sarr[MAX];

   for (i = 0; i < 32; i++)
   {
      array[i] = sin(2*PI*0.2*i);
   }
   fft(array, 0, 32);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
float complex w()
{
   return cexp(0);
}

void even_terms(float array[], float earr[], int s, int e)
{
   int        i, k = 0;

   for (i = 0; i < e-s; i = i + 2)
   {
      earr[k] = array[i];
      k++;
   }

   return ;
}

void odd_terms(float array[], float oarr[], int s, int e)
{
   int        i, k = 0;

   for (i = 1; i < e-s; i = i + 2)
   {
      oarr[k] = array[i];
      k++;
   }

   return ;
}

void fft(float array[], int s, int e)
{
   int        mid;
   float      earr[MAX/2], oarr[MAX/2];

   if (e - s == 1)
   {
      printf("( %f + i %f )\n", creal(array[0]*w()), cimag(array[0]*w()));
   }
   else
   {
      mid = (s+e)/2;
      even_terms(array, earr, s, e);
      odd_terms(array, oarr, s, e);
      fft(earr, s, mid);
      fft(oarr, mid, e);
   }

   return ;
}
