#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
   int        i;
   pid_t      pid_p = 0, pid_c = 0;

   if (argc != 3)
   {
      fprintf(stderr, "Syntax is: %s <command> <argument>.\n", argv[0]);
      exit(1);
   }

   if ((i=fork()) != 0)
   {
      pid_p = getpid();
      waitpid(i);
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
