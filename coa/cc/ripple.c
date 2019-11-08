#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define MAX        32

/********* FUNCTION DECLARARTION *********/
int ripple(char *bi1, char *bi2, int result[]);
int fulladd(int x, int y, int z, int result[], int ind);
void reverse(char *str);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int          i, len, result[MAX];
   char         *bi1, *bi2;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <first value> <second value>.\n", argv[0]);
      exit(1);
   }

   bi1 = argv[1];
   bi2 = argv[2];

   if (strlen(bi1) > 32 || strlen(bi2) > 32)
   {
      fprintf(stderr, "Enter only a 32-bit number.\n");
      exit(2);
   }
   else if (strlen(bi1) != strlen(bi2))
   {
      fprintf(stderr, "Both the values should contain equal no. of digits.\n");
      exit(3);
   }

   len = ripple(bi1, bi2, result);

   for (i = len; i >= 0; i--)
   {
      printf("%d", result[i]);
   }
   printf(" is the resultant value.\n");

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int ripple(char *bi1, char *bi2, int result[])
{
   int        i = 0, x1, x2, carry = 0;

   reverse(bi1);
   reverse(bi2);

   while (*bi1 != '\0' && *bi2 != '\0')
   {
      x1 = (int)(*bi1 - '0');
      x2 = (int)(*bi2 - '0');

      carry = fulladd(x1, x2, carry, result, i);
      i++;
      bi1++;
      bi2++;
   }

   if (carry == 1)
   {
      result[i] = carry;
   }
   else
   {
      i = i - 1;
   }

   return i;
}

int fulladd(int x, int y, int z, int result[], int ind)
{
   int        sum, carry;

   sum = (x ^ y ^ z);
   carry = ((x & y) | (y & z) | (x & z));

   result[ind] = sum;
   return carry;
}

void reverse(char *str)
{
   int       c, i, j;

   for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
   {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
   }
   return ;
}

