#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX    50

int main(void)
{
  char        s1[MAX], s2[MAX];
  char       *p;

  printf("Enter string 1 : ");
  scanf("%s", s1);

  printf("Enter string 2 : ");
  scanf("%s", s2);

  p = s1 + strlen(s1);
  while (*s2 != '\0') {
    *p++ = *s2++;
  }

  printf("concatenated string = [%s]\n", s1);
  exit(0);
}
