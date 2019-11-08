#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   MAX1        32
#define   MAX2        256

/********* FUNCTION DECLARATION *********/
void long_word(char line[], char mw[], char word[]);
int word_count(char line[]);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int         char_num = 0, word_num = 0, cn = 0, wn = 0;
   FILE        *fp = NULL;
   char        *filename, line[MAX2], max_word[MAX1], word[MAX1], mw[MAX1], eof;

   filename = argv[1];
   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
      exit(0);
   }

   if ((fp = fopen(filename, "r")) == NULL)
   {
      fprintf(stderr, "Error opening file %s\n", filename);
      exit(1);
   }

   eof = fgetc(fp);

   if (eof == EOF)
   {
      printf("The given file is empty.\nGive a non-empty file as input.\n");
      exit(2);
   }
   rewind(fp);

   while (fgets(line, MAX2, fp) != NULL)
   {
      cn = strlen(line);
      char_num = char_num + cn;
      long_word(line, mw, word);

      if (strlen(mw) > strlen(max_word))
      {
         strcpy(max_word, mw);
      }
      wn = word_count(line);
      word_num = word_num + wn;
   }
   printf("Number of characters are %d\nNumber of words are %d\n", char_num, word_num);
   printf("%s\n", max_word);
   fclose(fp);
   exit(0);
}

void long_word(char line[], char mw[], char word[])
{
   int        i = 0, j = 0, max_len = 0, lenc = 0;
 
   while (line[i] != '\n' || i < MAX2)
   {
      if (line[i] == ' ')
      {
         if (lenc > max_len)
         {
            word[j] = '\0';
            max_len = lenc;
            strcpy(mw, word);
         }
         j = 0, lenc = 0;
      }
      else if (line[i] >= 'a' || line[i] <= 'z')
      {
         word[j] = line[i];
         lenc = lenc + 1;
         j = j + 1;
      }
      i = i + 1;
   }

   if (lenc > max_len)
   {
      word[j] = '\0';
      max_len = lenc;
      strcpy(mw, word);
   }
 
   return ; 
}

int word_count(char line[])
{
   int       i = 0, l = 0;

   while (line[i] != '\n')
   {
      if (line[i] == ' ')
      {
         l = l + 1;
      }
      i = i + 1;
   }

   return l+1;
}
