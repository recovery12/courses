#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX       20

void handler(int signo)
{
   printf("You can't kill me with signal %d\n", signo);
   printf("But you can always try with some other signals.");
   return ;
}

int main(int argc, char **argv)
{
   int      i = 0;

   signal(2, handler);
   signal(3, handler);
   signal(1, handler);
   signal(9, handler);
   signal(11, handler);
   signal(17, handler);
   signal(15, handler);
   signal(8, handler);

   printf("My pid is %d\n", getpid());
   sleep(40);

   exit(0);
}
