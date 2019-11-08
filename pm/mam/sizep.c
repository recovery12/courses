#include <stdio.h>
#include <stdlib.h>

int main(void)
{
      char    *cp;
      int     *ip;
      int     *iap[10];
      float    f;
      
      f = sizeof(cp);
      printf("f = %f\n", f);
      printf("%lu %lu %lu\n", sizeof(cp), sizeof(ip), sizeof(iap));

      exit(0);
}
