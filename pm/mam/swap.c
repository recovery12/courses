#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j);

int main(void)
{
  int      m, n;

  printf("Enter m: ");
  scanf("%d", &m);

  printf("Enter n: ");
  scanf("%d", &n);

  swap(&m, &n);

  printf("m = %d, n = %d\n", m, n);

  exit(0);
}

void swap(int *i, int *j)
{
  int      k;

  k = *i;
  *i = *j;
  *j = k;

  printf("i = %d, j = %d, k = %d\n", *i, *j, k);
  return;
}

