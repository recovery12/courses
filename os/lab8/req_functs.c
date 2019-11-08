#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "queue.h"
#include "memory_management.h"

/********* REFERENCEING GLOBAL VARIABLES *********/
extern int           ff_global, ind, np, pg_replace;
extern firstframe    ff_local[MAXFRAMES];

/********* FUNCTION DEFINITION *********/
void initialize_ready_q(int np)
{
   int        i, tmp_arr[MAXFRAMES];

   initialize(&proc_queue);
   for (i = 0; i < np; i++)
   {
      tmp_arr[i] = i+1;
   }

   shuffle_q(tmp_arr, np);

   for (i = 0; i < np; i++)
   {
      insert(&proc_queue, tmp_arr[i]);
   }

   return ;
}

void shuffle_q(int arr[], int size)
{
   int        i, j;
   time_t     t;

   srand((unsigned) t);

   for (i = size-1; i > 0; i--)
   {
      j = rand() % i;
      swap(&arr[i], &arr[j]);
   }

   return ;
}

void swap(int *a, int *b)
{
   int        tmp;

   tmp = *b;
   *b = *a;
   *a = tmp;

   return ;
}

int no_of_digits(int num)
{
   int      count = 0;

   while (num != 0)
   {
      count = count + 1;
      num = (int) num / 10;
   }

   return count;
}

int rand_range(int lower, int upper)
{
   int        num;

   num = (int) (rand() % (upper - lower + 1)) + lower;
   return num;
}

int sim_process(int m, int s, FILE *fp)
{
   int        i, j, c, l, d, size1, size2, val, tot_ref = 0;
   int        normal[ULIMIT], uniform[ULIMIT];
   time_t     t;

   for (i = 0; i < m; i++)
   {
      c = (int) (m * drand48());
      l = rand_range(LLIMIT, ULIMIT);
   
      d = c * 4096 + 2048;
      size1 = (int) floorf(0.9*l);
   
      srand((unsigned) time(&t));

      j = 0;
      while (j < size1)
      {
         val = (int) (drand48() * (512 * (s+1)) + d);
         normal[j] = val;
         fprintf(fp, "%d ", normal[j]);
         j = j + 1;
      }
      fprintf(fp, "\n");

      c = ((int) (m * drand48())) + 1;
      size2 = (int) floorf(0.1*l);

      for (j = 0; j < size2; j++)
      {
         uniform[j] = (int) (drand48() * c);
         fprintf(fp, "%d ", uniform[j]);
      }
      fprintf(fp, "\n\n");
      tot_ref = tot_ref + size1 + size2;
   }

   return tot_ref;
}

void make_process(int pid, int m, int s)
{
   char       fname[FNAME] = "AR_\0";
   FILE       *fp = NULL;

   filename(fname, pid, INFILE);
   fp = fopen(fname, "w");
   sim_process(m, s, fp);
   fclose(fp);

   return ;
}

int mem_mapper(FILE *ifp, FILE *ofp, int pid)
{
   int    i = 0, j, a, pgnum, offset, addr, f_stat, rep_pg;
   char   buff[MAXCHAR];
   bool   check;

   a = rand_range(LLIMIT, ULIMIT);
   while (i < a)
   {
      f_stat = fscanf(ifp, "%s", buff);
      if (f_stat == EOF)
      {
         return 0;
      }

      check = true;
      addr = atoi(buff);
      pgnum = (int) addr/PAGESIZE;
      offset = addr%PAGESIZE;

      if (ind == MAXFRAMES)
      {
         check = in_memory(pid, ind, addr, ofp);
         if (check)
         {
            if (pg_replace == GLOBAL)
            {
               rep_pg = page_fifo_global();
               phy_mem[rep_pg].pid = pid;
               phy_mem[rep_pg].pgnum = pgnum;
            }
            else if (pg_replace == LOCAL)
            {
               rep_pg = page_fifo_local(pid);
               phy_mem[rep_pg].pgnum = pgnum;
            }
            fprintf(ofp, "%d,%d,1\n", addr, rep_pg * PAGESIZE + offset);
         }
      }
      else
      {
         check = in_memory(pid, ind, addr, ofp);
         if (check)
         {
            if (ff_local[pid-1].firstframe == -1)
            {
               ff_local[pid-1].firstframe = ind;
               ff_local[pid-1].first = true;
            }
            fprintf(ofp, "%d,%d,1\n", addr, ind * PAGESIZE + offset);
            phy_mem[ind].pgnum = pgnum;
            phy_mem[ind].pid = pid;
            ind = ind + 1;
         }
      }
      i = i + 1;
   }

   return 1;
}

bool in_memory(int pid, int index, int addr, FILE *ofp)
{
   int        i, pgnum, offset;

   pgnum = (int) addr/PAGESIZE;
   offset = addr%PAGESIZE;

   for (i = 0; i < ind; i++)
   {
      if (phy_mem[i].pgnum == pgnum && phy_mem[i].pid == pid)
      {
         fprintf(ofp, "%d,%d,0 %d\n", addr, i * PAGESIZE + offset, pgnum);
         return false;
      }
   }

   return true;
}

int page_fifo_global()
{
   ff_global = (ff_global + 1) % MAXFRAMES;

   return ff_global;
}

int page_fifo_local(int pid)
{
   int        i, frame_no = -1;

   if (ff_local[pid-1].first)
   {
      frame_no = ff_local[pid-1].firstframe;
      ff_local[pid-1].first = false;
   }

   if (ff_local[pid-1].first == false && frame_no == -1)
   {
      for (i = 0; i < np; i++)
      {
         if (pid-1 == i)
         {
            frame_no = ff_local[i].cur_frame;
         }
      }
   }

   for (i = frame_no+1; i < MAXFRAMES; i++)
   {
      if (phy_mem[i].pid == pid)
      {
         ff_local[pid-1].cur_frame = i;
         break;
      }
   }
   if (i == MAXFRAMES)
   {
      ff_local[pid-1].cur_frame = ff_local[pid-1].firstframe;
      ff_local[pid-1].first = true;
   }

   return frame_no;
}

void display_frametable()
{
   int        i = 0;

   printf("+-----------------------+\n");
   printf("|Pid\t|Page no.\t|\n");
   printf("+-----------------------+\n");
   while (i < ind)
   {
      printf("|%d\t|%d\t\t|\n", phy_mem[i].pid, phy_mem[i].pgnum);
      i = i + 1;
   }
   printf("+-----------------------+\n");

   return ;
}

void filename(char *fname, int pid, int param)
{
   int        dig;

   dig = no_of_digits(pid);

   if (param == INFILE)
   {
      if (dig == 1)
      {
         snprintf(fname, FNAME, "AR_000%d.dat", pid);
      }
      else if (dig == 2)
      {
         snprintf(fname, FNAME, "AR_00%d.dat", pid);
      }
      else if (dig == 3)
      {
         snprintf(fname, FNAME, "AR_0%d.dat", pid);
      }
      else
      {
         snprintf(fname, FNAME, "AR_%d.dat", pid);
      }
   }
   else if (param == OUTFILE)
   {
      if (dig == 1)
      {
         snprintf(fname, FNAME, "AR_000%d_out.dat", pid);
      }
      else if (dig == 2)
      {
         snprintf(fname, FNAME, "AR_00%d_out.dat", pid);
      }
      else if (dig == 3)
      {
         snprintf(fname, FNAME, "AR_0%d_out.dat", pid);
      }
      else
      {
         snprintf(fname, FNAME, "AR_%d_out.dat", pid);
      }  
   }

   return ;
}
