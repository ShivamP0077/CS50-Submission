#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
    struct node *pre;
}
node;
node *list = NULL;
node *last = NULL;
node *list1 = NULL;


// insert front

void insertFront(int n)
{
  if (list == NULL)
  {
      node* new = (node*)malloc(sizeof(node));
      new->number = n;
      new->next = NULL;
      list = new;
      last = new;
       new->pre = NULL;

  }
  else
  {
      node* new = (node*)malloc(sizeof(node));
      new->number = n;
      new->next = list;
      new->pre = NULL;
      list = new;

  }
}





void printlist(void)
{
   node *ptr = list;
 while (ptr != NULL)
 {
   printf("%i\n",ptr->number);
   ptr = ptr->next;
 }
}



int main(void)
{

    insertFront(3);
    insertFront(5);
    insertFront(6);
   printlist();
}