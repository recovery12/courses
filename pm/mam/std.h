#ifndef __STD_H
#define __STD_H

/**** CONSTANT DECLARATIONS ****/
#define NAMELEN      32

/***** DATA TYPE DEFINITIONS ****/
typedef struct std_s {
  char       regno[NAMELEN];
  char       name[NAMELEN];
  float      cgpa;
} std_t;

/**** FUNCTION PROTOTYPES ****/
int add_student(FILE *fp);
void print_student(int num_std);

#endif /* __STD_H */
