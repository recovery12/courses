#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX       2
#define BUFFSIZE  1024

void upper_string(char s[]);

int main(int argc, char **argv)
{
   int      p[MAX];
   pid_t    pid;
   char buff[BUFFSIZE];

   pipe(p);

   if ((pid = fork()) == 0)
   {
      int        i = 0;

      dup2(p[0], 0);
      close(p[1]);

      while (read(p[0], buff, BUFFSIZE) > 0)
      {
         i = i + 1;
         printf("%d->\t%s\n", i, buff);
      }
   }
   else
   {
      dup2(p[1], 1);
      close(p[0]);

      while (1)
      {
         fgets(buff, BUFFSIZE, stdin);
         upper_string(buff);
         write(p[1], buff, BUFFSIZE);
      }
      exit(0);
   }

   exit(0);
}

void upper_string(char s[]) 
{
   int i = 0;
   
   while (s[i] != '\0')
   {
      if (s[i] >= 'a' && s[i] <= 'z')
      {
         s[i] = s[i] - 32;
      }
      i++;
   }
}
