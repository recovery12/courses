#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX       20

void handler(int signo)
{
   printf("You can't kill me signal no %d\n", signo);
   return ;
}

int main(int argc, char **argv)
{
   int i = 0;

   /*signal(8, handler);
   i = 3/0;*/

   /*printf("My pid: %d\n", getpid());
   signal(1, handler);*/

   /*printf("My pid: %d\n", getpid());
   signal(9, handler);*/

   /*printf("My pid: %d\n", getpid());
   signal(15, handler);*/

   /*printf("My pid: %d\n", getpid());
   signal(3, handler);*/

   /*printf("My pid: %d\n", getpid());
   signal(11, handler);*/

   printf("My pid: %d\n", getpid());
   signal(2, handler);

   while (i < MAX)
   {
   }

   exit(0);
}
