#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********* FUNCTION DECLARARTION *********/
void bcell(int x, int y, int c);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        x, y, c;
   clock_t    start, end;
   double     time_used;

   x = atoi(argv[1]);
   y = atoi(argv[2]);
   c = atoi(argv[3]);

   printf("----------------------\n");
   printf(" x  y  c  sum  carry\n");
   printf("----------------------\n");

   printf(" %d  %d  %d", x, y, c);
   start = clock();
   bcell(x, y, c);
   end = clock();

   time_used = ((double) end - start);
   printf("Time taken is %lf\n", time_used);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void bcell(int x, int y, int c)
{
   int        s, g, p, C;

   g = (x & y);
   p = (x ^ y);
   s = (p ^ c);
   C = (g | (p & c));

   printf("   %d     %d\n", s, C);

   return ;
}
