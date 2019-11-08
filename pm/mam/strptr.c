#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX      2
#define MAXLEN   32

int main(void)
{
  char       *str = "hello world", string[MAXLEN] = "hello world"; 
  char       *ptr = NULL;
  char       *a[MAX] = {"hello", "world"};
  int         i = 0;

  strcpy(str, "kernighan");
  printf("str = %s\n", str);
/*
  ptr = string;
  printf("first char = ");
  putchar(*ptr);
  printf("\n");
  string++;
  printf("second char = ");
  putchar(*str);
  printf("\n");
*/

/*
  printf("str = %x, string = %s\n", str, str);
  printf("Addr a[0] = %x, a[1] = %x\n", a[0], a[1]);
*/
  while (i < MAX) {
/*
    printf("%x %x\n", a[i], *(a + i));
*/
    printf("%s ", a[i]);
    printf("%s\n", *(a + i));
    i++;
  }

  exit(0);
}
