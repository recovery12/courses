#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN      32
#define MAXLEN       256

int main(void)
{
  char       filename[NAMELEN], line[MAXLEN];
  char       regno[NAMELEN], name[NAMELEN];
  char      *ptr = NULL;
  float      cgpa;
  FILE      *fp = NULL;

  printf("Enter the input file name: ");
  scanf("%s", filename);

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  while (fgets(line, MAXLEN, fp) != NULL) {
    ptr = strtok(line, ",");
    strcpy(regno, ptr);
    ptr = strtok(NULL, ",");
    strcpy(name, ptr);
    ptr = strtok(NULL, ",");
    cgpa = atof(ptr);
    printf("Reg. No. = %s, Name = %s, CGPA = %f\n", regno, name, cgpa);
  }

  exit(0);
}
