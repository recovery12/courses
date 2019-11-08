#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   NAME_MAX        32
#define   MONTH_MAX       8
#define   MAX             256

/********* STRUCTURE DEFINITION *********/
struct std_r
{
   char        regno[NAME_MAX+1];
   char        name[NAME_MAX+1];
   int         mon_attd[MONTH_MAX];
   int         month[MONTH_MAX];
} attd;

/********* FUNCTION DECLARATION *********/
void add_std(FILE *fp, struct std_r attd, int num_month, int num_std);
void print_attd(struct std_r attd, int num_month, int num_std);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   char        *file, eof;
   FILE        *fp = NULL;
   int         num_month, num_std;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <filename>.\n", argv[0]);
      exit(1);
   }

   file = argv[1];

   if ((fp = fopen(file, "r")) == NULL)
   {
      fprintf(stderr, "Error in opening file %s.\n", file);
      exit(2);
   }

   eof = fgetc(fp);
   rewind(fp);

   add_std(fp, attd, num_month, num_std);
   print_attd(attd, num_month, num_std);

}

void add_std(FILE *fp, struct std_r attd, int num_month, int num_std)
{
   char        line[MAX];
   int         i, j, k = 0;

   num_month = fgetc(fp);

   while (fgets(line, MAX, fp) != '\n')
   {
      attd.month[0] = strtok(line, " ");

      for (i = 1; i < num_month; i++)
      {
         attd.month[i] = strtok(NULL, " ");
      }
   }

   while (fgets(line, MAX, fp) != NULL)
   {
      attd.regno[k] = strtok(line, " ");
      attd.name[k] = strtok(NULL, " ");

      for (j = 0; j < num_month; j++)
      {
         attd.mon_attd[j] = strtok(line, " ");
      }
   }

   num_std = k;
   return ;
}

void print_attd(struct std_r attd, int num_month, int num_std)
{
   int        i;
   int        percent[MAX];

   for (i = 0; i < num_std; i++)
   {
      for (i = 0; i < num_month; i++)
      {
         percent[i] += (attd.month[i] / attd.mon_attd[i]) * 100;
      }

      printf("%s %s %d\n", attd.regno[i], attd.name[i], percent[i]/4);
   }

   return ;
}
