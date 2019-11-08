#include <stdio.h>
#include <stdlib.h>

int getbits(int x, int p, int n);

int main(void)
{
  int       value, end, numbits, extract;

  printf("Enter an unsigned integer : ");
  scanf("%d", &value);

  printf("Enter the ending bit position : ");
  scanf("%d", &end);

  printf("Enter no. of bits to extract : ");
  scanf("%d", &numbits);

  extract = getbits(value, end, numbits);

  printf("Value extracted = %d\n", extract);

  exit(0);
}

int getbits(int x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}