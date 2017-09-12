#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}*top;
int main()
{
    int choice, item;
	top =NULL;
    printf("\n1. Push Element into the Stack\n");
    printf("2. Pop Element from the Stack\n");
    printf("3. Traverse the Stack\n");
    printf("4. Quit\n");
    while (1)
    {
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter value to be pushed into the stack: ");
            scanf("%d",&item);
            top = push(top, item);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            traverse(top);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong Choice...");
        }
    }
 getch();
}
void push(struct node *top, int item)
{
    struct node *tmp;
    tmp = (struct node*) malloc(sizeof(struct node));
    tmp->info = item;
    tmp->link = top;
    top = tmp;
    return top;
}
void pop(struct node *top)
{
    struct node *tmp;
    if (top == NULL)
        printf("Stack is empty.");
    else
    {
        tmp = top;
        printf("Element Popped: %d",tmp->info);
        top = top->link;
        free(tmp);
    }
    return top;
}
void traverse(struct node *top)
{
    struct node *ptr;
    ptr = top;
    if (top == NULL)
    	printf("Stack is empty.");
    else
    {
        printf("Stack elements : ");
        while (ptr != NULL)
        {
            printf("%d ",ptr->info);
            ptr = ptr->link;
        }
    }
    printf("\n");
}
