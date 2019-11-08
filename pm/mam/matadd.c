#include <stdio.h>
#include <stdlib.h>

#define   M       10

void printMatrix(int (*mat)[M], int rows, int cols)
{
  int      i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }

  return;
}

int main(void)
{
  int       i, j;
  int       rows = 2, cols = 4;
  int       matrix1[M][M] = {
                                {10, 5, 2, 1},
                                {3, 12, 46, 23}
                            };
  int       matrix2[M][M] = {
                            {1, 8, 4, 19},
                            {53, 22, 16, 83}
                          };

  printf("Matrix 1 = \n");
  printMatrix(matrix1, rows, cols);
  printf("\n");

  printf("Matrix 2 = \n");
  printMatrix(matrix2, rows, cols);
  printf("\n");

  for (i = 0; i < M; i++)
    for (j = 0; j < M; j++)
      matrix1[i][j] += matrix2[i][j];

  printf("Added Matrix = \n");
  printMatrix(matrix1, rows, cols);
  printf("\n");

  exit(0);
}
