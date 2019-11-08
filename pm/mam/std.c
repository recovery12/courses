#include <stdio.h>
#include "std.h"

#define MAXLEN       256
#define MAX_STD      10

static std_t      std_table[MAX_STD];

int add_student(FILE *fp)
{
  int      num_std = 0;
  char     line[MAXLEN];
  std_t   *std_rec = std_table;

  while (fgets(line, MAXLEN, fp) != NULL) {
    sscanf(line, "%s %s %f", std_rec->regno, std_rec->name, 
           &std_rec->cgpa);
    num_std++;
    std_rec++;
  }

  return num_std;
}

void print_student(int num_std)
{
  std_t   *rec = std_table;
  int      i;

  for (i = 0; i < num_std; i++) {
    printf("Reg. No. = %s, Name = %s, CGPA = %f\n", 
            rec->regno, rec->name, rec->cgpa);
    rec++;
  }

  return;
}
