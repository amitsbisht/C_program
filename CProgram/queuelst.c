#define true 1
#define false 0
#include<stdio.h>
#include<conio.h>
#include<process.h>
struct queue_point
{
  int element;
  struct queue_point* n;
};
struct queue_point *f_ptr = NULL;
int is_que(void);
void add_ele(int);
int remove_ele(void);
void show_ele();
void main()
{
  int ele,choice,j;
  printf("\n1 To insert an element");
  printf("\n2 To remove an element");
  printf("\n3 To display all the elements");
  printf("\n4 Exit\n");
  while(1)
    {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
    {
      printf("\nElement to be inserted: ");
      scanf("%d",&ele);
      add_ele(ele);
      break;
    }
    case 2:
    {
      if(!is_que())
       {
        j=remove_ele();
        printf("\n%d is removed from the queue",j);
        printf("\n");
       }
       else
       {
         printf("\nQueue is Empty.\n");
       }
     break;
   }
    case 3:
     show_ele();
     break;
	case 4:
     exit(1);
     break;
    default:
     printf("\nInvalid choice.\n");
     break;
    }
  }
}
int is_que(void)
{
  if(f_ptr==NULL)
  return true;
  return false;
}
void add_ele(int element)
{
  struct queue_point *queue = (struct queue_point*)malloc(sizeof(struct queue_point));
  queue->element = element;
  queue->n = NULL;
  if(f_ptr==NULL)
  {
    f_ptr = queue;
  }
  else
  {
      struct queue_point* ptr;
      ptr = f_ptr;
      for(ptr=f_ptr ;ptr->n!=NULL; ptr=ptr->n);
      ptr->n = queue;
  }
}
int remove_ele()
{
  struct queue_point* queue=NULL;
  if(is_que()==false)
  {
    int j = f_ptr->element;
    queue=f_ptr;
    f_ptr = f_ptr->n;
    free (queue);
    return j;
  }
  else
  {
    printf("\nQueue is empty.\n");
    return -9999;
  }
}
void show_ele()
{
  struct queue_point *ptr=NULL;
  ptr=f_ptr;
  if(is_que())
  {
    printf("\nQUEUE is Empty.\n");
    return;
  }
  else
  {
    printf("\nElements present in Queue are: ");
    while(ptr!=NULL)
    {
     printf("%d\t",ptr->element);
     ptr=ptr->n;
    }
    printf("\n");
  }
}
