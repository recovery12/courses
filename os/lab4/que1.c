#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX       2
#define BUFFSIZE  1024

int main(int argc, char **argv)
{
   int      p[MAX];
   pid_t    pid;
   FILE     *fp = NULL;

   if (argc != 2)
   {
      fprintf(stderr, "Syntax: %s <filename>.\n", argv[0]);
      exit(1);
   }

   fp = fopen(argv[1], "r");
   pipe(p);

   if ((pid = fork()) == 0)
   {
      char buff[BUFFSIZE];

      dup2(p[0], 0);
      close(p[1]);
      while (read(p[0], buff, BUFFSIZE-1) > 0)
      {
         printf("%s\n", buff);
      }
      // execlp("more", "more", NULL);
   }
   else
   {
      dup2(p[1], 1);
      close(p[0]);

      char buff[BUFFSIZE];

      while (fread(buff, 1, BUFFSIZE, fp))
      {
         //write(1, "Hello", 64);
         write(p[1], buff, BUFFSIZE);
      }
      wait();
      exit(0);
   }

   exit(0);
}
