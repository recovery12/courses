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
   pid_t    pid;

   if ((pid = fork()) == 0)
   {
      kill(17, getppid());
      printf("My pid: %d and parent id is %d\n", getpid(), getppid());
      while (1)
      //while (getpid() == getppid()+1 || getpid() == getppid()-1)
      {
         //printf("My pid: %d and parent id is %d\n", getpid(), getppid());
      }
      //printf("My pid: %d and now my parent is %d(upstart)\n", getpid(), getppid());
   }
   else
   {
      signal(17, handler);
      waitpid(pid);
      printf("abc\n");
   }
   exit(0);
}
