#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>

#define PI 3.1415

int main()
{
  int i, j, k, N = 16, l;
  double complex arr[N], arr1[N];
  double complex sol[N];

  for(k = 0; k < N; k++)
  {
      arr[k] = sin(2*PI*0.2*k);
      arr1[k] = arr[k];
  }

  for(k = 0; k < N/2; k++)
  {
      for(i = 0; i < log2f(N); i++)
      {
          for(j = 0; j < N/pow(2, i); i += 2)
	  {
	     sol[j] = arr[j] + cexp(CMPLX(0, 1)*2*PI*pow(2, i)*k/N)*arr[j+1];
	  }
	  for(l = 0; l < N; l++)
	  {
	      arr[l] = sol[l];
	  }
	  for(l = 0; l < N; l++)
	  {
	      printf("Arr: %f + %fi\n", creal(arr[l]), cimag(arr[l]));
	      printf("Arr1: %f + %fi\n", creal(arr1[l]), cimag(arr1[l]));
	      printf("Sol: %f + %fi\n", creal(sol[l]), cimag(sol[l]));
	  }
      }
      for(l = 0; l < N; l++)
      {
          arr[l] = arr1[l];
      }
  }

  for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
  {
      printf("%f + %fi\n", creal(arr[i]), cimag(arr[i]));
  }
  printf("\n");

  exit (0);
}
