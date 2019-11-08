#include <stdio.h>
#include <stdlib.h>

/********* ADDITIONAL DATATYPES *********/
typedef char StackEntry

/********* DATA STRUCTURE DEFINITION *********/
typedef struct node
{
   StackEntry   data;
   struct node  *addr;
} Node;


