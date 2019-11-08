#include <stdio.h>
#include <stdlib.h>

int cmp(int i, int j)
{
  printf("i = %d, j = %d\n", i,  j);
  return (i == j) ? 0 : 1;
}

int compare(void *a, void *b, int (*f1)(int, int))
{
  int     *x, *y;

  x = (int *) a;
  y = (int *) b;

  return f1(*x, *y);
}

int main(int argc, char **argv)
{
  int       m, n;

  if (argc != 3) {
    fprintf(stderr, "Usage: fnptr <num1> <num2>\n");
    exit(1);
  }

  m = atoi(argv[1]);
  n = atoi(argv[2]);

  printf("The numbers %d and %d are %s\n", m, n,
          compare(&m, &n, cmp) ? "not equal" : "equal");

  exit(0);
}
