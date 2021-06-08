//A program to delete a node from the beginning, middle and end of a linked list....

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void traverse(struct Node *ptr)
{
	while(ptr!=NULL)
	{
		printf("Element = %d\n",ptr->data);
		ptr = ptr->next;
	}
}

struct Node * deleteFromBeginning(struct Node *head)
{
	printf("\nDeleting a node from the beginning of the linked list :\n");
	
	struct Node *ptr = head;
	
	if(ptr == NULL)
	{
		return NULL;
	}
	head = head->next;
	free(ptr);
	
	return head;
}

struct Node * deleteFromMiddle(struct Node *head, int loc)
{
	printf("\nDeleting element from the middle of the linked list :\n");
	
	struct Node *ptr1, *ptr2;
	int i=1;
	
	ptr1 = head;
	ptr2 = head->next;
	
	if(ptr1 == NULL)
	{
		return NULL;
	}
	else if(loc == 1)
	{
		head = ptr1->next;
		free(ptr1);
		return head;
	}
	while(i!=loc-1)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		i++;
	}
	ptr1->next = ptr2->next;
	free(ptr2);
		
	return head;	
}

struct Node * deleteFromEnd (struct Node *head)
{
	printf("eleting element from the end of the linked list :\n");
	struct Node *ptr1 = head;
	struct Node *ptr2 = head->next;
	while(ptr2->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	ptr1->next = NULL;
	free(ptr2);
	
	return head;
}

void main()
{
	int index;
	struct Node *head, *second, *third, *fourth, *fifth;
	
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));
	fifth = (struct Node *)malloc(sizeof(struct Node));
	
	head->data = 10;
	head->next = second;
	
	second->data = 20;
	second->next = third;
	
	third->data = 30;
	third->next = fourth;
	
	fourth->data = 40;
	fourth->next = fifth;
	
	fifth->data = 50;
	fifth->next = NULL;
	
	printf("Currently, The linked list is : \n");
	traverse(head);
	head = deleteFromBeginning(head); 
	if(head == NULL)
	{
		printf("Underflow !!! \n");
	}
	else
	{
		traverse(head);
	}
	
	printf("\nAt what position, you want to delete a node ? ");
	scanf("%d",&index);
	printf("\n");
	head = deleteFromMiddle(head,index);
	if(head == NULL)
	{
		printf("Underflow !!! \n");
	}
	else
	{
		traverse(head);
	}
	
	printf("\n");
	head = deleteFromEnd(head);
	if(head == NULL)
	{
		printf("Underflow !!! \n");
	}
	else
	{
		traverse(head);
	}
}
