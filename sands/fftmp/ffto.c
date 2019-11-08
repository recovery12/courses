#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX       1024
#define PI        acos(-1)

/********* STRUCTURE DEFINITION *********/
typedef struct comp
{
   float      real;
   float      imag;
} Complex;

/********* FUNCTION DECLARATION *********/
Complex comp_mul(Complex a, Complex b);
Complex comp_add(Complex a, Complex b);
void fft(Complex arr[], int n);
void cparr(Complex ori[], Complex dup[], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i, n;
   float      f = 0.2;
   Complex    arr[MAX];

   printf("Enter the value of n: ");
   scanf("%d", &n);

   for (i = 0; i < n; i++)
   {
      arr[i].real = sin(2*PI*f*i);
      arr[i].imag = 0;
   }

   fft(arr, n);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
Complex comp_mul(Complex a, Complex b)
{
   Complex        c;

   c.real = a.real*b.real - a.imag*b.imag;
   c.imag = a.real*b.imag + a.imag*b.real;

   return c;
}

Complex comp_add(Complex a, Complex b)
{
   Complex        c;

   c.real = a.real + b.real;
   c.imag = a.imag + b.imag;

   return c;
}

void fft(Complex arr[], int n)
{
   int        i, j, k;
   Complex    tp, arr1[MAX], sol[MAX], fsol[MAX];

   for (k = 0; k < n; k++)
   {
      printf("(%f+i.%f)\n", arr[k].real, arr[k].imag); 
      cparr(arr, arr1, n);
      for (i = 0; i < log2(n); i++)
      {
         for (j = 0; j < n/(pow(2,i)); i += 2)
         {
            tp.real = cos(2*PI*k*pow(2,i)/n);
            tp.imag = sin(2*PI*k*pow(2,i)/n);
            sol[j] = comp_add(arr1[j], comp_mul(tp, arr[j+1]));
         }
         cparr(sol, arr, n/(pow(2,i)));
      }
      fsol[k] = arr1[0];
   }

   for (i = 0; i < n; i++)
   {
      printf("(%f+i.%f)\n", fsol[i].real, fsol[i].imag);
   }
   return ;
}

void cparr(Complex ori[], Complex dup[], int n)
{
   int        i;

   for (i = 0; i < n; i++)
   {
      dup[i] = ori[i];
   }

   return ;
}
