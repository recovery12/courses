#include <stdio.h>
#include <stdlib.h>

#define   N    5

int main(void)
{
  int      i, n = 5;
  int      table[N] = {1, 2, 3, 4, 5};

  printf("n = %d\n", n);

  for (i = 0; i < n; i++)
    printf("%d ", table[i]);

  printf("\n");

  exit(0);
}
