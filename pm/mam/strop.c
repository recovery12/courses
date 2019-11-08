/*14MCME12*/
#include<stdio.h>
#define MAXLEN 50

/*the following function returns string length*/

int slen(char s1[MAXLEN]) {
  int slen=0;
  int i=0;
  
  while (s1[i] != 0) {
    slen++;
    i++;
  }
  return slen;
}

/*the following function copies string s2 to s1*/

void scpy(char s2[MAXLEN], char s1[MAXLEN]) {
  int i;
  int a = slen(s2);

   for (i = 0; i < a; i++) {
     s1[i] = s2[i];
   }
   s1[i]='\0';
 
}

/*the following function concatenates two strings s1 and s2*/
void scat(char s1[MAXLEN], char s2[MAXLEN]) {
  int i=0;
  int c1=slen(s1);
  int c2=slen(s2);
  
  for (i = c1; i < (c1+c2); i++) {
    s1[i] = s2[(i-c1)];
  }
  s1[i]='\0';
}


int main(void) {
  int c;
  printf("enter the choice number: " ); 
  scanf("%d",&c);

  if (c < 1 || c> 3) {
    printf("invalid choice:choice should be either 1 or 2 or 3\n");
    return 0;
  }

  char s1[MAXLEN];
  char s2[MAXLEN];

  switch(c) {
  
  case 1:

    printf("enter the string: "); 
    scanf("%s", s1);
    printf("The length of the string %s is %d\n", s1, slen(s1));
  
    break;
  
  case 2:
   
     printf("enter the string: ");
     scanf("%s", s2);
     scpy(s2,s1);
     printf("the string is copied...s1 now is %s\n", s1); 
    
     break;    
  
  case 3:

    printf("enter a string: ");
    scanf("%s",s1);
    printf("enter another string: "); 
    scanf("%s",s2);
    scat(s1,s2);
    printf("the concatenated string is %s\n", s1);
    
    break;
  
  }
  return 0;
}

 