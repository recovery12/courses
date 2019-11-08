#include <stdio.h>
#include <stdlib.h>

#define MAXLEN      256
#define NAMELEN     32

int main(void)
{
  FILE        *ifp = NULL;
  char         infile[NAMELEN];
  int          val, i = 0;
  
  printf("Enter the name of the input file: ");
  scanf("%s", infile);

  ifp = fopen(infile, "rb");
  if (ifp == NULL) {
    printf("Error opening file %s\n", infile);
    exit(3);
  }
  
  do {
    while (fread(&val, sizeof(int), 1, ifp) != 0)
      printf("%d ", val);
    printf("\n");
    i++;
    rewind(ifp);
  } while (i < 2);

  rewind(ifp);
  fseek(ifp, 2 * sizeof(int), SEEK_SET);
  fread(&val, sizeof(int), 1, ifp);
  printf("3rd value in file = %d\n", val);

  fseek(ifp, 0, SEEK_END);
  fseek(ifp, -sizeof(int), SEEK_END);
  fread(&val, sizeof(int), 1, ifp);
  printf("Last value in file = %d\n", val);

  fseek(ifp, -2 * sizeof(int), SEEK_CUR);
  fread(&val, sizeof(int), 1, ifp);
  printf("Last but one value in file = %d\n", val);

  fclose(ifp);

  exit(0);
}
