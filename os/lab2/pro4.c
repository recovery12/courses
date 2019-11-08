#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   pid_t        pid_p, pid_me;

   fork();
   fork();
   fork();

   pid_me = getpid();
   pid_p = getppid();
   printf("My parent id %d and my id %d\n", pid_p, pid_me);

   exit(0);
}
