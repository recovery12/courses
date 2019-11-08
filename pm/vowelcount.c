#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        150

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, acount, ecount, icount, ocount, ucount, vowel_count;
   int        Acount, Ecount, Icount, Ocount, Ucount, Vowel_count;
   char       str[MAX];

   acount = 0, Acount = 0;
   ecount = 0, Ecount = 0;
   icount = 0, Icount = 0;
   ocount = 0, Ocount = 0;
   ucount = 0, Ucount = 0;
   vowel_count = 0, Vowel_count = 0;

   printf("Type the string here \n");
   scanf("%s", str);

   while (str[i] != '\0')
   {
      switch (str[i])
      {
         case 'a': 
                  acount = acount + 1;
                  break;
         case 'e':
                  ecount = ecount + 1;
                  break;
         case 'i':
                  icount = icount + 1;
                  break;
         case 'o':
                  ocount = ocount + 1;
                  break;
         case 'u':
                  ucount = ucount + 1;
                  break;
         case 'A':
                  Acount = Acount + 1;
                  break;
         case 'E':
                  Ecount = Ecount + 1;
                  break;
         case 'I':
                  Icount = Icount + 1;
                  break;
         case 'O':
                  Ocount = Ocount + 1;
                  break;
         case 'U':
                  Ucount = Ucount + 1;
                  break;
         default : break;
      }
      i = i + 1;
   }

   vowel_count = acount + ecount + icount + ocount + ucount;
   Vowel_count = Acount + Ecount + Icount + Ocount + Ucount;
   printf("The number of a's is %d\n", acount);
   printf("The number of e's is %d\n", ecount);
   printf("The number of i's is %d\n", icount);
   printf("The number of o's is %d\n", ocount);
   printf("The number of u's is %d\n", ucount);
   printf("\n");
   printf("The number of A's is %d\n", Acount);
   printf("The number of E's is %d\n", Ecount);
   printf("The number of I's is %d\n", Icount);
   printf("The number of O's is %d\n", Ocount);
   printf("The number of U's is %d\n", Ucount);
   printf("\n");
   printf("Total number of lowercase vowels in the given string is %d\n", vowel_count);
   printf("Total number of uppercase vowels in the given string is %d\n", Vowel_count);
   exit(0);
}
