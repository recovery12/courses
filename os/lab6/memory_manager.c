#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        1024
#define   PAGESIZE   4096

/********* GLOBAL VARIABLES *********/
int frametable[MAX], ind = 0;

/********* FUNCTION DECLARATION *********/
void mem_manager(int f, FILE *ifp, FILE *ofp);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        i = 0, f;
   char       check, *fin = NULL, *fout = NULL;
   FILE       *ifp = NULL, *ofp = NULL;

   if (argc != 4)
   {
      fprintf(stderr, "%s <addr-file> F <outfile>\n", argv[0]);
      exit(1);
   }

   fin = argv[1];
   f = atoi(argv[2]);
   fout = argv[3];

   ifp = fopen(fin, "r");
   ofp = fopen(fout, "w");

   if (ifp == NULL)
   {
      fprintf(stderr, "Sorry the requested file(%s) doesn't exist, or", fin);
      fprintf(stderr, "it doesn't have a read permission.\n");
      exit(2);
   }

   check = fgetc(ifp);
   if (check == EOF)
   {
      fprintf(stderr, "%s is an empty file.\n", fin);
      exit(3);
   }
   rewind(ifp);

   if (ofp == NULL)
   {
      fprintf(stderr, "Sorry the requested file(%s) doesn't exist, or", fout);
      fprintf(stderr, "it doesn't have a read permission.\n");
      exit(4);
   }

   for (i = 0; i < MAX; i++)
   {
      frametable[i] = -1;
   }

   mem_manager(f, ifp, ofp);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void mem_manager(int f, FILE *ifp, FILE *ofp)
{
   int    i, pgnum, offset, addr;
   char   buff[MAX];
   bool   check;

   while (fscanf(ifp, "%s", buff) != EOF)
   {
      check = true;
      addr = atoi(buff);
      pgnum = (int) addr/PAGESIZE;
      offset = addr%PAGESIZE;

      if (ind == f)
      {
         fprintf(stderr, "Memory Full\n");
         fclose(ifp);
         fclose(ofp);
         exit(0);
      }
      else
      {
         for (i = 0; i < ind; i++)
         {
            if (frametable[i] == pgnum)
            {
               fprintf(ofp, "%d,%d,0\n", addr, i*PAGESIZE+offset);
               check = false;
               break;
            }
         }
         if (check)
         {
            fprintf(ofp, "%d,%d,1\n", addr, ind*PAGESIZE+offset);
            frametable[ind] = pgnum;
            ind = ind + 1;
         }
      }
   }

   fclose(ifp);
   fclose(ofp);

   return ;
}