#include <stdio.h>
#include <stdlib.h>

/*** FUNCTION PROTOTYPES ***/
void printd(int n);

/******** MAIN PROGRAM STARTS HERE *******/
int main(void)
{
  int       N;

  printf("Enter a number : ");
  scanf("%d", &N);

  printd(N);
  printf("\n");

  exit(0);
}

void printd(int n)
{
  if (n < 0) {
    putchar('-');
    n = -n;
  }

  if (n / 10) {
    printf("Calling printd recursively with %d\n", n/10);
    printd(n / 10);
  }

  putchar(n % 10 + '0');

  return;
}
