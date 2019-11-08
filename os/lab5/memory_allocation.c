#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "memory_allocation.h"

/********* STRUCTURE DEFINITION *********/
typedef struct PCB
{
   int       pid;
   int       arrival;
   int       mem;
   int       time;
   int       start_t;
   int       end_t;
} pcb;

/********* GLOBALS VARIABLES *********/
int        cur_time = 0;
pcb        mem[MAX];

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        i, qi = 0, pci = 0;
   int        q[MAX], pm[MAXMEM], proc_com[MAX];
   char       check, line[3*MAX], *fname = NULL;
   FILE       *fp = NULL;

   if (argc != 2)
   {
      fprintf(stderr, "Syntax: %s <filename>\n", argv[0]);
      exit(1);
   }

   fname = argv[1];
   fp = fopen(fname, "r");

   if (fp == NULL)
   {
      fprintf(stderr, "Sorry the requested file doesn't exist, or");
      fprintf(stderr, "it doesn't have a read permission.\n");
      exit(2);
   }
   
   check = fgetc(fp);
   if (check == EOF)
   {
      fprintf(stderr, "%s is an empty file.\n", fname);
      exit(3);
   }
   rewind(fp);

   for (i = 0; i < MAX; i++)
   {
      fgets(line, 3*MAX, fp);  // Extracting details from file
      sscanf(line, "%d %d %d %d", &mem[i].pid, &mem[i].arrival, &mem[i].mem, &mem[i].time);
   }
   fclose(fp);

   initialize(pm, MAXMEM);
   initialize(proc_com, MAX);

   while (arr_len(proc_com, MAX) != MAX)
   {
      // print_array(proc_com, pci);
      pci = dealloc_mem(pm, proc_com, pci);
      qi = put_proc_inwait(q, qi);
      alloc_mem(q, qi, pm);
      // print_array(pm, MAXMEM);
      print_status(pm, proc_com, q);
      cur_time = cur_time + 1;
      sleep(1);
   }
   printf("The order in which processes are executed are: \n");
   print_array(proc_com, pci);

   exit(0);
}