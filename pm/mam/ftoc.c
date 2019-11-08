#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int      f, c, c1, c2, c3;

  printf("Enter deg. fahrenheit : ");
  scanf("%d", &f);

  c = f - 32 * 5 / 9;
  c1 = (f - 32 * 5) / 9;
  c2 = (f - 32) * 5 / 9;
  c3 = 5 / 9 * (f - 32) ;
  printf("deg. centigrade c = %d, c1 = %d, c2 = %d, c3 = %d\n", 
          c, c1, c2, c3);

  exit(0);
}
