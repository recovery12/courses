#include <stdio.h>
#include <stdlib.h>

#define NAMELEN      32
#define MAXLEN       256

int main(void)
{
  char       filename[NAMELEN], line[MAXLEN];
  char       regno[NAMELEN], name[NAMELEN];
  float      cgpa;
  FILE      *fp = NULL;

  printf("Enter the input file name: ");
  scanf("%s", filename);

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  while (fgets(line, MAXLEN, fp) != NULL) {
    sscanf(line, "%s %s %f", regno, name, &cgpa);
    printf("Reg. No. = %s, Name = %s, CGPA = %f\n", regno, name, cgpa);
  }

  exit(0);
}
