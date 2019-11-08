#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 50

/*the following function returns string length*/

int slen(char *s1, int *t) 
{
  int slen=0;
  
/*
  while (*s1++ != 0) {
    slen++;
  }
*/
  for (; *s1++ != 0; slen++, t++) {
    printf("s1 = %x, t = %x\n", s1, t);
    printf("*s1 = %c, *t = %d\n", *s1, *t);
  }
  return slen;
}

int main(void)
{
  char       s[MAXLEN];
  int        len = 0, table[MAXLEN] = {10, 20, 30, 40, 50};

  printf("Enter a string : ");
  scanf("%s", s);

  len = slen(s, table);
  printf("Length of string [%s] = %d\n", s, len);

  exit(0);
}
