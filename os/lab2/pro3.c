#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
   int        p;
   pid_t      pid_p = 0, pid_c = 0;
   clock_t    start, end;

   if (argc != 3)
   {
      fprintf(stderr, "Syntax is: %s <command> <argument>.\n", argv[0]);
      exit(1);
   }

   start = clock();
   p = fork();
   end = clock();
   printf("Time taken to create child process is %lf\n", end-start);

   if (p != 0)
   {
      pid_p = getpid();
      waitpid(p);
      printf("I am parent and my id is %d\n", pid_p);
   }
   else
   {
      pid_c = getpid();
      printf("I am copy and my id is %d\n", pid_c);
      execlp(argv[1], argv[1], argv[2], NULL);
      printf("Job Done\n");
   }

   printf("I am useless. %d\n", pid_c);
   exit(0);
}
