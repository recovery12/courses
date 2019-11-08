#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define MAX 100
#define PI 3.1415

// Function prototypes
void printMatrix(float matrix[MAX][MAX], int rows, int cols);
void printArray(float matrix[MAX], int rows);

int main()
{
  int N, i, j, num;
  float val;
  printf("Enter N: ");
  scanf("%d", &N);
  float dftMatrix[N][N], output[N], input[N];

  double w = cexp(-2*PI*I/N);
  printf("Omega w: %e\n", w);

  printf("Enter input: \n");
  for(i = 0; i < N; i++)
  {
      printf(">> ");
      scanf("%d", &num);
      input[i] = num;
  }
  printf("Input Matrix:\n");
  printArray(input, N);

  for(i = 0; i < N; i++)
  {
      for(j = 0; j < N; j++)
      {
	  val = cpow(w, i*j);
	  //printf("val: %f\n", val);
	  dftMatrix[i][j] = val;
      }
      //printf("\n");
  }

  //printMatrix(dftMatrix, N, N);

  printf("\nDFT Matrix:\n");
  for(i = 0; i < N; i++)
  {
      for(j = 0; j < N; j++)
      {
          printf("%e, ", dftMatrix[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  
  for(i = 0; i < N; i++)
  {
      val = 0;
      for(j = 0; j < N; j++)
      {
          val += dftMatrix[i][j] * input[j];
      }
      output[i] = val;
  }

  printf("\nOutput Matrix:\n");
  printArray(output, N);

  exit (0);
}

void printMatrix(float matrix[][MAX], int rows, int cols)
{
  int i, j;

  for(i = 0; i < rows; i++)
  {
      for(j = 0; j < cols; j++)
      {
          printf("%e, ", matrix[i][j]);
      }
      printf("\n");
  }
  printf("\n");

  return;
}

void printArray(float matrix[MAX], int rows)
{
  int i;

  for(i = 0; i < rows; i++)
  {
      printf("%e ", matrix[i]);
  }
  printf("\n");
  
  return;
}
