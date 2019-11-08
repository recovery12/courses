#include <stdio.h>
#include <stdlib.h>

//void progression(int pro, int n, float a, float dr);

void progression(int pro, int n, float a, float dr)
{
  int         i;
  float       a1;

  printf("%s Progression for the first %d terms is as follows:\n",
          pro == 1 ? "Arithmetic" : "Geometric", n);
  printf("%f ", a);

  for (i = 1; i <= n-1; i++) {
    switch(pro) {
      case 1:
        a1 = a + dr;
        break;
      case 2:
        a1 = a * dr;
        break;
      default:
        printf("Wrong progression\n");
        return;
    }

    printf("%f ", a1);
    a = a1;
  }

  printf("\n");
  return;
}
int main(void)
{
  float    a, d;
  int      n, pro;
 
  printf("Enter 1 for AP and 2 for GP : ");
  scanf("%d", &pro);
  printf("enter the number of terms: ");
  scanf("%d", &n);
  printf("enter the first term: ");
  scanf("%f", &a);
  printf("enter the common difference/ratio: ");
  scanf("%f", &d);

  if (n <= 0) {
    printf("invalid input: n must be a positive integer\n");
    exit(1);
  }

  progression(pro, n, a, d);

  exit(0);
}


