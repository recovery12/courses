#include <stdio.h>
int main(void)
{
  float a, r, a2;
  int n, i;
  
  printf("enter the number of terms: ");
  scanf("%d", &n);
  printf("enter the first term: ");
  scanf("%f", &a);
  printf("enter the common ratio: ");
  scanf("%f", &r);
  if (n <= 0) {
    printf("invalid input:n must be a positive integer\n");
   }
  else {
  
    printf("%f ", a);
    for (i = 0; i < n-1; i++) {
      a2 = a*r;
      printf("%f ", a2);
      a = a2;
   }  
    printf("\n");
   
  }
  return 0;
}
