#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAXSTACK        32

/********* ADDITIONAL DATATYPES *********/
typedef char         StackEntry;

/********* DATA STRUCTURE DEFINITION *********/
typedef struct stack
{
   int           top;
   StackEntry    entry[MAXSTACK];
} Stack;

int StackEmpty(Stack *s)
{
   if (s->top <= 0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int StackFull(Stack *s)
{
   if (s->top >= MAXSTACK)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

void push(StackEntry item, Stack *s)
{
   if (StackFull(s))
   {
      printf("The stack is already full can't enter more items.\n");
      return ;
   }
   else
   {
      s->entry[s->top] = item;
      s->top++;
   }

   return ;
}

void pop(StackEntry *item, Stack *s)
{
   if (StackEmpty(s))
   {
      printf("The stack is already empty can't pull any items from it.\n");
      return ;
   }
   else
   {
      *item = s->entry[--s->top];
   }

   return ;
}

void CreateStack(Stack *s)
{
   s->top = 0;
   return ;
}

int StackSize(Stack *s)
{
   return s->top;
}

void StackTop(StackEntry *item, Stack *s)
{
   if (StackEmpty(s))
   {
      printf("The stack is already empty can't pull any items from it.\n");
      return ;
   }
   else
   {
      *item = s->entry[s->top];
   }

   return ;
}

void StackClear(Stack *s)
{
   free(s);
   return ;
}

/********* MAIN STARTS HERE *********/
int main(void)
{
   StackEntry        item;
   Stack             stack;

   CreateStack(&stack);

   while (!StackFull(&stack) && (item = getchar()) != '\n')
   {
      push(item, &stack);
   }

   while (!StackEmpty(&stack))
   {
      pop(&item, &stack);
      printf("%c", item);
   }
   printf("\n");

   exit(0);
}
