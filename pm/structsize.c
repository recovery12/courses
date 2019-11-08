#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int main(void)
{

enum boolean {FALSE, TRUE};

struct std_s 
{
   char  a, b;
   int   i, j;
   char c[32];
   float num, num1;
   long double num3;
   char cd;
   enum boolean option;
   short num2;
} __attribute__((__packed__));

   char  a;
   int   i;
   float num;
   short num2;
   enum boolean opt;

   printf("The size of char is %lu\n", sizeof(char));
   printf("The size of int is %lu\n", sizeof(int));
   printf("The size of float is %lu\n", sizeof(float));
   printf("The size of short is %lu\n", sizeof(short));
   printf("The size of enum is %lu\n", sizeof(opt));
   printf("The size of stucture is %lu\n", sizeof(struct std_s ));
   exit(0);
}
