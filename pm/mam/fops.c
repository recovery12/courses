#include <stdio.h>
#include <stdlib.h>

#define MAXLEN      256
#define NAMELEN     32

int main(void)
{
  FILE        *fp = NULL,*fout = NULL;
  char         filename[NAMELEN];
  char         ID[MAXLEN],Name[MAXLEN];
  float        Cgpa;
  
  printf("Enter the name of the file: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }


  fout = fopen("outFile.txt","w");
  if ( fout == NULL) {
     printf("ERROR : opening file %s\n","outFile");

  }
  printf("Integers read from the file : \n");
  while (fscanf(fp, "%s%s%f", ID, Name, &Cgpa) != EOF) {
    fprintf(fout,"%s %s %f \n", ID, Name, Cgpa);
  }

  printf("\n");
  exit(0);
}
