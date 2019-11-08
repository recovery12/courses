#include <stdio.h>
#include <stdlib.h>

#define NAMELEN      32
#define MAXLEN       256

typedef struct std_s {
  char       regno[NAMELEN];
  char       name[NAMELEN];
  float      cgpa;
} std_t;

int main(void)
{
  char       filename[NAMELEN], line[MAXLEN];
  std_t      std_rec;
  FILE      *fp = NULL;

  printf("Enter the input file name: ");
  scanf("%s", filename);

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  while (fgets(line, MAXLEN, fp) != NULL) {
    sscanf(line, "%s %s %f", std_rec.regno, std_rec.name, &std_rec.cgpa);
    printf("Reg. No. = %s, Name = %s, CGPA = %f\n", 
            std_rec.regno, std_rec.name, std_rec.cgpa);
  }

  exit(0);
}