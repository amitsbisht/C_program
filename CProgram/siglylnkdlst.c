#include <stdio.h>
#include <stdlib.h>
struct NODE {
	int number;
	struct NODE *next;
};
int search_value(struct NODE *llist, int num);
void append_node(struct NODE *llist, int num);
void display_list(struct NODE *llist);
void delete_node(struct NODE *llist);
int main(void) 
{
	int num = 0;
	int input = 1;
	int retval = 0;
	struct NODE *llist;
	llist = (struct NODE *) malloc(sizeof(struct NODE));
	llist->number = 0;
	llist->next = NULL;
	while (input != 0) {
		printf("\n0) Exit\n");
		printf("1) Insert\n");
		printf("2) Delete\n");
		printf("3) Display\n");
		printf("Enter your choice : ");
		scanf("%d", &input);
		switch (input) {
		case 0:
		default:
			break;
		case 1:
			printf("Enter the value which should be inserted: ");
			scanf("%d", &num);
			append_node(llist, num);
			break;
		case 2:
			delete_node(llist);
			break;
		case 3:
			display_list(llist);
			break;
		} 
	} 
	free(llist);
	getch();
}
void display_list(struct NODE *llist) {
	printf("\nList contains : ");
	while(llist->next != NULL) {
		printf("%d ", llist->number);
		llist = llist->next;
	}
	printf("%d\n", llist->number);
}
void append_node(struct NODE *llist, int num) {
	while (llist->next != NULL)
		llist = llist->next;
	llist->next = (struct NODE *) malloc(sizeof(struct NODE));
	llist->next->number = num;
	llist->next->next = NULL;
}
void delete_node(struct NODE *llist) {
	struct NODE *ptr,*cptr;
	int n;
	if(llist==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	if(llist->next==NULL)
	{
		ptr = llist;
		n = llist->number;
		llist = NULL;
	}
	else
	{
		cptr= llist;
		ptr= llist->next;
		while(ptr->next!=NULL)
		{
			cptr = ptr;
			ptr = ptr->next;
		}
		cptr->next = NULL;
		n = ptr->number;
	}
	free(ptr);
	printf("\n%d deleted from the list.\n",n);
}
