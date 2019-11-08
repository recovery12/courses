#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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

   while (i < MAX);
   exit(0);
}
