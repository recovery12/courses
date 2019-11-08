#include <stdio.h>
#include <stdlib.h>

/**** CONSTANT DECLARATIONS ****/
#define NAMELEN      32
#define MAXLEN       256
#define MAX_STD      10

/***** DATA TYPE DEFINITIONS ****/
typedef struct std_s {
  char       regno[NAMELEN];
  char       name[NAMELEN];
  float      cgpa;
} std_t;

/**** FUNCTION PROTOTYPES ****/
int add_student(FILE *fp, std_t *std_rec);
void print_student(int num_std, std_t *rec);

/******** MAIN PROGRAM STARTS HERE ********/
int main(void)
{
  char       filename[NAMELEN];
  FILE      *fp = NULL;
  std_t      std_table[MAX_STD];
  int        total_std;

  printf("Enter the input file name: ");
  scanf("%s", filename);

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  total_std = add_student(fp, std_table);
  print_student(total_std, std_table);

  exit(0);
}

int add_student(FILE *fp, std_t *std_rec)
{
  int      num_std = 0;
  char     line[MAXLEN];

  while (fgets(line, MAXLEN, fp) != NULL) {
    sscanf(line, "%s %s %f", std_rec->regno, std_rec->name, &std_rec->cgpa);
    num_std++;
    std_rec++;
  }

  return num_std;
}

void print_student(int num_std, std_t *rec)
{
  int       i;

  for (i = 0; i < num_std; i++) {
    printf("Reg. No. = %s, Name = %s, CGPA = %f\n", 
            rec->regno, rec->name, rec->cgpa);
    rec++;
  }

  return;
}
