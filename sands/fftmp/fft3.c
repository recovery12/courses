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
void divarr(Complex ori[], Complex dup[], int s, int e);
void printarr(Complex arr[], int n);
void concat_arr(Complex tmp[], Complex arr[], int n);;
void final_oper(Complex sol[], Complex tpe[], Complex tpo[], Complex w[][MAX], int n);
/********* MIAN STARTS HERE *********/
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
void fft(Complex arr[], int n)
{
   int        i, j;
   Complex    even[MAX], odd[MAX], tpe[MAX], tpo[MAX], w[MAX][MAX], sol[MAX];

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         w[i][j].real = cos(2*PI*i*j/n);
         w[i][j].imag = sin(2*PI*i*j/n); 
         printf("(%f)+i(%f)\n", w[i][j].real, w[i][j].imag);
      }
   }

   divarr(arr, even, 0, n);
   divarr(arr, odd, 1, n);
   //printarr(even, n/2);
   concat_arr(tpe, even, (int)n/2);
   concat_arr(tpo, odd, (int)n/2);
   
   final_oper(sol, tpe, tpo, w, n);
   printarr(sol, n);
   return ;
}

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

void divarr(Complex ori[], Complex dup[], int s, int e)
{
   int          i, k = 0;

   for (i = s; i < e; i += 2, k++)
   {
      dup[k] = ori[i];
   }

   return ;
}

void printarr(Complex arr[], int n)
{
   int         i;

   for (i = 0; i < n; i++)
   {
      printf("(%f)+i(%f)\n", arr[i].real, arr[i].imag);
   }

   return ;
}

void concat_arr(Complex tmp[], Complex arr[], int n)
{
   int        i;

   for (i = 0; i < n; i++)
   {
      tmp[i] = arr[i];
      tmp[i+n] = arr[i];
   }

   return ;
}

void final_oper(Complex sol[], Complex tpe[], Complex tpo[], Complex w[][MAX], int n)
{
   int        i, j, k;
   Complex    tmp;

   for (i = 0; i < n; i++)
   {
      sol[i].real = 0;
      sol[i].imag = 0;
   }
 
   for (i = 0; i < n; i++)
   {
      for (k = 0; k < n; k++)
      {
         tmp = comp_mul(tpo[k], w[i][k]);
         sol[k] = comp_add(sol[k], comp_add(sol[k], tmp));
      }
   }

   return ;
}
