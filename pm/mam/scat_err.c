#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX    50

char * scat(char *s1, char *s2);

int main(void)
{
  char        s1[MAX], s2[MAX];
  char       *p = NULL;

  printf("Enter string 1 : ");
  scanf("%s", s1);

  printf("Enter string 2 : ");
  scanf("%s", s2);

  printf("Calling function scat...\n");
  p = scat(s1, s2);
  printf("The concatenated string = [%s]:[%s]\n", p, s1);

  exit(0);
}

char *scat(char *a1, char *a2)
{
  char   *p = a1;

  a1 = a1 + strlen(a1);
  while (*a2 != '\0') {
    *a1++ = *a2++;
  }
  *a1 = '\0';

  return p;
}
