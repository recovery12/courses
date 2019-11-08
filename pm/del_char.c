#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* FUNCTION DECLARATION *********/
void del_char(char *str1, char *str2);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   char        *str1, *str2;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
      exit(1);
   }

   str1 = argv[1];
   str2 = argv[2];

   del_char(str1, str2);
   printf("The string after deleting the characters is %s\n", str1);

   exit(0);
}

void del_char(char *str1, char *str2)
{
   int        i, j, k = 0, len1, len2, count = 0;

   len1 = strlen(str1);
   len2 = strlen(str2);

   for (i = 0; i < len1; i++)
   {
      count = 0;
      for (j = 0; j < len2; j++)
      {
         if (str1[i] == str2[j])
         {
            count = 1;
            break;
         }
      }

      if (count == 0)
      {
         str1[k] = str1[i];
         k = k + 1;
      }
   }

   str1[k] = '\0';
   return ;
}
