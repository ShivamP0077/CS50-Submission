#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
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
  }
  else
  {
      node* new = (node*)malloc(sizeof(node));
      new->number = n;
      new->next = list;
      list = new;
  }
}

// insert last

void insertLast(int n)
{
    node *ptr = list;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    node* new = (node*)malloc(sizeof(node));
      new->number = n;
      new->next = NULL;
      ptr->next = new;
      last = new;
}

// index

int index(int n)
{
   node *a = list;
   if (a == NULL)
   {
    return 0;
   }


    int t = 0;
    while (a != NULL)
    {
        if (a->number <= n)
        {
            t++;
        }

        a = a->next;
    }
    return t;
}

// insert

void insert(int n)
{

   int where = index(n);
    if (where == 0)
    {
        insertFront(n);
    }
    else
    {
        node *temp = list;
        int count = 0;
        while (count < where -1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            insertLast(n);
        }
        else
        {
            node *a = (node *)malloc(sizeof(node));
            a->number = n;
            a->next = temp->next;
            temp->next = a;
        }
    }
}

// delete node form front

void deleteFront()
{
  list = list->next;
}

// delete node from last

void deleteLast()
{
   node *ptr = list;
   node *t = NULL;
    while (ptr->next != NULL)
    {
      t = ptr;
      ptr = ptr->next;
    }
    t->next = NULL;
    last = t;
}

//copy list

void copy()
{
  node *ptr = list;
  while (ptr != NULL)
  {
    node *a = (node*)malloc(sizeof(node));
    a->number = ptr->number;
    if (list1 == NULL)
    {
      list1 = a;
      a->next = NULL;
    }
    else
    {
      a->next = a;
    }
    ptr = ptr->next;
  }

}

// search element

void search(int n)
{
   node *ptr = list;
   int count = 0;
 while (ptr != NULL)
 {
   if (ptr->number == n)
   {
    count++;
   }
   ptr = ptr->next;
 }
 if (count)
   {
    printf("element is present in a list!\n");

   }
   else
   {
     printf("element is abasent in a list!\n");

   }
}




// ptint list

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


 int choise = 0;

 while (choise != -1)
 {
    printf("1] create linklist and insert 1st element \n 2] insert element asending order \n 3] element delete form front \n 4] element delete from last \n 5] travers the list \n 6] search element in list \n 7] exit\n");
    printf("Enter your choise : ");
    scanf("%d",&choise);

    switch (choise)
    {
      case 1:
      {
          int n;
          printf("Enter number: ");
          scanf("%d",&n);
          insert(n);
      }
      break;
      case 2:
      {
          int n;
          printf("Enter number: ");
          scanf("%d",&n);
          insert(n);
      }
      break;

      case 3:
      {

          deleteFront();
      }
      break;
      case 4:
      {

          deleteLast();
      }
      break;
      case 5:
      {

          printlist();
      }
      break;
      case 6:
      {
          int n;
          printf("Enter number which you search: ");
          scanf("%d",&n);
          search(n);
      }
      break;
      case 7:
      {
          choise = -1;
      }
      break;
      default :
        printf("enter a right choise!");
    }
 }


}