#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *next;
};
void insert_at_end(struct node *start)
{
	struct node *q,*temp;
	q =(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the value : ");
	scanf("%d",&q->num);
	q->next =NULL;
	if(start==NULL)
	{
		start = q;
	} else {
		temp = start;
		while(temp->next!=NULL)
		 	temp=temp->next;
		temp->next= q;
	}
}
void insert_at_beg(struct node *start)
{
	struct node *q;
	q= (struct node*) malloc(sizeof(struct node));
	printf("\nEnter the value : ");
	scanf("%d",&q->num);
	q->next = start->next;
	start->next = q;
}
void display_list(struct node *start) {
	while (start->next != NULL) {
		printf("%d ", start->num);
		start = start->next;
	}
	printf("%d", start->num);
}
void delete_node(struct node *start) {
	struct node *temp=start;
	struct node *t;
	while(temp->next!=NULL)
	{
	 t = temp;
	 temp= temp->next;
	}
	free(t->next);
	t->next = NULL;
}
void main()
{
	int num,input;
	struct node *start;
	start= (struct node*) malloc(sizeof(struct node));
	start->num =0;
	start->next =NULL;
	while (input!= 0) {
		printf("\n0) Quit");
		printf("\n1) Insert at begining.");
		printf("\n2) Insert at end.");
		printf("\n3) Delete");
		printf("\n4) Display");
		printf("\nEnter your choice : ");
		scanf("%d", &input);
		switch (input) {
		case 0:
		default:
			printf("Goodbye ...\n");
			input = 0;
			break;
		case 1:
			insert_at_beg(start);
			break;
		case 2:
			insert_at_end(start);
			break;
		case 3:
			delete_node(start);
			break;
		case 4:
			display_list(start);
			break;
		} /* switch */
	} /* while */
	free(start);
	getch();
}
