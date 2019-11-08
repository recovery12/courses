#include<stdio.h>

int main()
{
   int N;

   printf("enter N \n");
   scanf("%d",&N);

   int A[N+10];


   A[0]  = 10;
   A[19] = 20;

   printf(" A[0] = %d  A[19] = %d \n",A[0],A[19]);

   exit(0);
}
