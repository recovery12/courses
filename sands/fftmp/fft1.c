#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

/********* DEFINED CONSTANTS ********/
#define MAX        100
#define PI         acos(-1.0)

/********* FUNCTION DECLARATION *********/
float complex w(int k, int i, int n);
void fft(int n, float complex que[]);
void cparr(float complex oarr[], float complex darr[], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int              i, n;
   float            tmp;
   float complex    array[MAX];

   printf("Enter the value of: ");
   scanf("%d", &n);

   for (i = 0; i < n; i++)
   {
      tmp = sin(2*PI*0.2*i);
      array[i] = tmp*(1+0*I);
   }
   fft(n, array);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
float complex w(int k, int i, int n)
{
   return cos(2*PI*pow(2,i)*k/n)+I*sin(2*PI*pow(2,i)*k/n);
}

void fft(int n, float complex que[])
{
   int              i, j, k;
   float complex    darr[MAX], tmp[MAX];

   for (i = 0; i < n/2; i++)
   {
      cparr(que, darr, n);
      for (j = 0; j < (int) log2(n); j++)
      {
         for (k = 0; k < (int) (n/(pow(2,i))); k += 2)
         {
            tmp[k] = darr[k]+w(i, j, n)*darr[k+1];
         }
      }
      cparr(tmp, darr, (int)(n/(pow(2,i))));
      printf("(%f+i.%f)\n", creal(darr[0]), cimag(darr[1]));
   }

   return ;
}

void cparr(float complex oarr[], float complex darr[], int n)
{
   int        i;

   for (i = 0; i < n; i++)
   {
      darr[i] = oarr[i];
   }

   return ;
}
