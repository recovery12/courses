#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 5

int main(void)
{
  char       str[MAXLEN] = "thisisthelongeststring.";

//  strcpy(str, "supercalifragilisticexpialidocius");
  printf("Str = %s\n", str);

  exit(0);
}
