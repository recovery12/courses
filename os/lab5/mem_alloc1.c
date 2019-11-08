#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

/********* DEFINED CONSTANTS *********/
#define MAX        10
#define MAXMEM     32
#define BLOCKSIZE  128

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

/********* FUNCTION DECLARATION *********/
int arr_len(int proc_com[], int size);
void initialize(int array[], int size);
int put_proc_inwait(int q[], int ind);
void alloc_mem(int q[], int qi, int pm[]);
int dealloc_mem(int pm[], int proc_com[], int ind);
void ext_frag(int pm[]);
void print_status(int pm[], int proc_com[], int q[]);
void print_array(int arr[], int size);  // For tracing or debugging

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i, qi = 0, pci = 0;
   int        q[MAX], pm[MAXMEM], proc_com[MAX];
   char       line[3*MAX];
   FILE       *fp = NULL;
   pid_t      cpid;

   fp = fopen("table.txt", "r");

   for (i = 0; i < MAX; i++)
   {
      fgets(line, 3*MAX, fp);
      sscanf(line, "%d %d %d %d", &mem[i].pid, &mem[i].arrival, &mem[i].mem, &mem[i].time);
   }
   fclose(fp);

   initialize(pm, MAXMEM);
   initialize(proc_com, MAX);

   cpid = fork();
   while (arr_len(proc_com, MAX) != MAX)
   {
      if (cpid == 0)
      {
         pci = dealloc_mem(pm, proc_com, pci);
         qi = put_proc_inwait(q, qi);
         printf("child is: %d\n", getpid());
         print_array(q, qi);
      }
      else if (cpid > 0)
      {
         alloc_mem(q, qi, pm);
         print_array(q, qi);
         printf("parent is: %d\n", getpid());
         //print_status(pm, proc_com, q);
      }
      cur_time = cur_time + 1;
      sleep(1);
   }
   printf("The order in which processes are executed are: \n");
   print_array(proc_com, pci);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void initialize(int array[], int size)
{
   int        i;

   for (i = 0; i < size; i++)
   {
      array[i] = 0;
   }

   return ;
}

void print_status(int pm[], int proc_com[], int q[])
{
   int        i = 0, k, pid, len, p = 0, start_t, end_t, wait = 0;
   int        mem_alloc = 0, mem_used = 0, mem_free = MAXMEM;
   bool       cond, flag = false;

   len = arr_len(proc_com, MAX);

   printf("Current time: %d\n", cur_time);
   printf("\e[35;107mPID\tBASE ADDRESS\tMEMORY\t\t%%MEM\t\tSTART\tEND\e[0m\n");
   while (i < MAXMEM)
   {
      cond = (pm[i] >= 643 && pm[i] <= 652);
      mem_alloc = 0;
      if (cond)
      {
         pid = pm[i];
         while (cond && pm[i] == pid)
         {
            mem_alloc = mem_alloc + 1;
            i = i + 1;
            flag = true;
         }
         for (k = 0; k < MAX; k++)
         {
            if (pid == mem[k].pid)
            {
               break;
            }
         }
         start_t = mem[k].start_t;
         end_t = mem[k].end_t;
      }

      if (flag)
      {
         printf("%d\t%d\t\t%d(%d MB)\t%f\t%d\t%d\n", pid, i - mem_alloc, mem_alloc, mem_alloc*BLOCKSIZE, (double)mem_alloc/MAXMEM, start_t, end_t);
         mem_used = mem_used + mem_alloc;
         flag = false;
         p = p + 1;
      }
      else
      {
         i = i + 1;
      }
   }

   for (k = 0; k < MAX; k++)
   {
      if (q[k] > 642 && q[k] < 653)
      {
         wait = wait + 1;
      }
   }

   mem_free = MAXMEM - mem_used;
   printf("Processes: Completed %d, Running %d, Under wait %d\n", len, p, wait);
   printf("Memory: Total %d MB, Used %d(%d MB), Free %d(%d MB)\n", MAXMEM*BLOCKSIZE, mem_used, mem_used*BLOCKSIZE, mem_free, mem_free*BLOCKSIZE);
   printf("External Fragmentation:\n");
   ext_frag(pm);
   printf("\n\n");

   return ;
}

int arr_len(int proc_com[], int size)
{
   int        i, len = 0;

   for (i = 0; i < size; i++)
   {
      if (proc_com[i] != 0)
      {
         len = len + 1;
      }
   }

   return len;
}

void alloc_mem(int q[], int qi, int pm[])
{
   int        i = 0, j, k, l, ava_mem, flag = 0, mem_req, pid;

   while (i < MAXMEM)
   {
      if (pm[i] != 0)
      {
         i = i + 1;
      }
      else
      {
         j = i;
         ava_mem = 0;
         while (pm[j] == 0)
         {
            ava_mem = ava_mem + 1;
            j = j + 1;
            if (j == MAXMEM)
            {
               break;
            }
         }
         for (k = 0; k < qi; k++)
         {
            for (l = 0; l < MAX; l++)
            {
               if (q[k] == mem[l].pid && ava_mem >= mem[l].mem)
               {
                  pid = mem[l].pid;
                  mem_req = mem[l].mem;
                  flag = 1;
                  q[k] = 0;
                  mem[l].start_t = cur_time;
                  mem[l].end_t = cur_time + mem[l].time;
                  break;
               }
               else if (q[k] == mem[l].pid)
               {
                  break;
               }
            }
            if (flag)
            {
               break;
            }
         }
         for (k = i; k < i+mem_req; k++)
         {
            pm[k] = pid;
         }
      }
      if (pid != 0 && flag)
      {
         i = i + mem_req;
      }
      else
      {
         i = i + 1;
      }
      pid = 0, mem_req = 0, flag = 0; // Resetting the values
   }

   return ;
}

int put_proc_inwait(int q[], int ind)
{
   int        i;

   for (i = 0; i < MAX; i++)
   {
      if (cur_time == mem[i].arrival)
      {
         q[ind] = mem[i].pid;
         ind = ind + 1;
      }
   }

   return ind;
}

int dealloc_mem(int pm[], int proc_com[], int ind)
{
   int        i, j, k, pid;

   for (i = 0; i < MAXMEM; i++)
   {
      if (pm[i] != 0)
      {
         for (j = 0; j < MAX; j++)
         {
            if (pm[i] == mem[j].pid && mem[j].end_t == cur_time)
            {
               pid = pm[i];
               for (k = i; k < i+mem[j].mem; k++)
               {
                  pm[k] = 0;
               }

               i = mem[j].mem;
               proc_com[ind] = pid;
               ind = ind + 1;
               break;
            }
         }
      }
   }

   return ind;
}

void ext_frag(int pm[])
{
   int        i = 0, k = 1;
   bool       flag = false, cond;

   while (i < MAXMEM)
   {
      flag = false;
      cond = (pm[i] >= 643 && pm[i] <= 652);
      if (cond != true)
      {
         printf("Fragment no. %d from %d to ", k, i);
         while (cond != true && i < MAXMEM)
         {
            i = i + 1;
            flag = true;
            if (pm[i] >= 643 && pm[i] <= 652)
            {
               break;
            }
         }
         printf("%d\n", i);
         k = k + 1;
      }

      if (flag == false)
      {
         i = i + 1;
      }
   }

   return ;
}

void print_array(int arr[], int size) // For tracing or debugging
{
   int        i;

   for (i = 0; i < size; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return ;
}
