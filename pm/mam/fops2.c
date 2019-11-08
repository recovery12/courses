#include <stdio.h>
#include <stdlib.h>

#define MAXLEN      256
#define NAMELEN     32

int main(void)
{
  FILE        *ifp = NULL, *ofp = NULL;
  char         infile[NAMELEN], outfile[NAMELEN];
  int          val;
  
  printf("Enter the name of the input file: ");
  scanf("%s", infile);

  printf("Enter the name of the output file: ");
  scanf("%s", outfile);

  ifp = fopen(infile, "r");
  if (ifp == NULL) {
    printf("Error opening file %s\n", infile);
    exit(1);
  }

  ofp = fopen(outfile, "wb");
  if (ofp == NULL) {
    printf("Error opening file %s\n", outfile);
    exit(2);
  }

  printf("Integers read from the file : \n");
  while (fscanf(ifp, "%d", &val) != EOF) {
//    printf("%d ", val);
    fwrite(&val, sizeof(int), 1, ofp);
  }

//  printf("\n");

  fclose(ifp);
  fclose(ofp);

  ifp = fopen(outfile, "rb");
  if (ifp == NULL) {
    printf("Error opening file %s\n", outfile);
    exit(3);
  }
  
  while (fread(&val, sizeof(int), 1, ifp) != 0)
    printf("%d ", val);
  printf("\n");

  exit(0);
}
