						\
#include <stdio.h>
int main(void)
{
  int n, i, f0 = 0,f1 = 1, f2;

  printf("enter the number of terms: ");
  scanf("%d", &n);

  while (n < 2) {
    printf("Invalid input: n must be greater than 2 \n");
    printf("enter again: ");
    scanf("%d", &n);
  } 
 
  
  printf("%d %d ", f0, f1);

  for (i=0; i<n-2; i++) {
    f2 = f0 + f1;
    printf("%d ", f2);
    f0 = f1;
    f1 = f2;
  }
  printf("\n");
  return 0;
}
