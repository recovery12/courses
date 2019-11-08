#include <stdio.h>
#include <stdlib.h>

/**** CONSTANT DECLARATIONS ***/
#define   MAX     100

/*** EXTERNAL VARIABLE DECLARATIONS ***/
int        FS[MAX];

/*** FUNCTION PROTOTYPYES ***/
int fib_recur(int n);

/****** MAIN STARTS HERE ******/
int main(void)
{
  int        N, i;

  printf("Enter N : ");
  scanf("%d", &N);

  if (N < 1 || N > MAX) {
    printf("N must be >= 1 and <= %d\n", MAX);
    exit(1);
  }

  printf("Fibonacci Series up to %d is as follows\n", N);

  fib_recur(N);

  for (i = 0; i < N; i++) 
    printf("%d ", FS[i]);
  printf("\n");

  exit(0);
}

int fib_recur(int n)
{
  int     nterm;

  if (n == 0) {
    FS[n] = 0;
    return 0;
  } else if (n == 1) {
    FS[n] = 1;
    return 1;
  } else {
    nterm = fib_recur(n - 2) + fib_recur(n - 1);
    FS[n] = nterm;
  }

  return nterm;
}