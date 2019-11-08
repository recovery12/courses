#include <stdio.h>
#include <stdlib.h>

int scomp(char *s1, char *s2)
{
  while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0')) {
    s1++;
    s2++;
  }

  if (*s1 == *s2)
    return 0;
  else
    return 1;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: scomp <string1> <string2>\n");
    exit(1);
  }

  printf("argv[0] = %s, argv[1] = %s, argv[2] = %s\n", 
          argv[0], argv[1], argv[2]);

  if (scomp(argv[1], argv[2]) == 0)
    printf("The two strings are equal\n");
  else
    printf("The two strings are not equal\n");

  exit(0);
}
