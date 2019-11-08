#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********* FUNCTION DECLARARTION *********/
void fulladd(int x, int y, int z);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        x, y, z;
   clock_t    start, end;
   double     time_used;

   if (argc != 4)
   {
      fprintf(stderr, "Usage: %s <xi> <yi> <ci>.\n", argv[0]);
      exit(1);
   }

   x = atoi(argv[1]);
   y = atoi(argv[2]);
   z = atoi(argv[3]);

   printf("----------------------\n");
   printf(" x  y  z  sum  carry\n");
   printf("----------------------\n");

   printf(" %d  %d  %d", x, y, z);
   start = clock();
   fulladd(x, y, z);
   end = clock();

   time_used = ((double) end - start);
   printf("Time taken is %lf\n", time_used);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void fulladd(int x, int y, int z)
{
   int        sum, carry;

   sum = ((x ^ y) ^ z);
   carry = ((x & y) | (y & z) | (x & z));

   printf("   %d     %d\n", sum, carry);

   return ;
}
