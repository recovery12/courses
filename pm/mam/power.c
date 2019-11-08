#include <stdio.h>
#include <stdlib.h>

int power(int b, int e);

int main(void)
{
  int      base, exp, val;

  printf("Enter base: ");
  scanf("%d", &base);

  printf("Enter exp: ");
  scanf("%d", &exp);

  val = power(base, exp);
  printf("%d raised to power %d = %d\n", base, exp, val);

  exit(0);
}

int power(int b, int e)
{
  int      pval;

  printf("In function %s:(b=%d, e=%d)\n", __FUNCTION__, b, e);
  if (e == 0)
    return(1);
  else {
    pval = b * power(b, e-1);
    printf("pval = %d\n", pval);
    return pval;
  }
}
