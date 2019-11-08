#include <stdio.h>
#include <stdlib.h>
#include "std.h"

/******** MAIN PROGRAM STARTS HERE ********/
int main(void)
{
  char       filename[NAMELEN];
  FILE      *fp = NULL;
  int        total_std;

  printf("Enter the input file name: ");
  scanf("%s", filename);

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  total_std = add_student(fp);
  print_student(total_std);

  exit(0);
}
