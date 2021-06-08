// A program to insert new node at the beginning, middle and end of the linked list....

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void traversal (struct Node *ptr)
{
	while(ptr!=NULL)
	{
		printf("Element = %d\n",ptr->data);
		ptr = ptr->next;
	}	
}

struct Node * insertAtBeginning (struct Node *head, int data)
{
	printf("Insertion at the beginning of the linked list : \n");
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->next = head;
	return ptr;
}

struct Node * insertAtMiddle (struct Node *head, int LOC, int data)
{
	printf("Insertion at the middle of the list : \n");
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	struct Node *ptr1, *ptr2;
	int i=1;
	
	ptr1 = head;
	ptr2 = head->next;
	
	while(i!=LOC-1)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
		i++;
	}
	
	new->data = data;
	new->next = ptr2;
	ptr1->next = new;
	return head;
}

struct Node * insertAtEnd (struct Node *head, int data)
{
	printf("Insertion at the end of the linked list : \n");
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	
	struct Node *ptr = head;
	
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	
	ptr->next = new;
	new->next = NULL;
	return head;
}

void main()
{
	int index,element;
	struct Node *head, *second, *third, *fourth, *fifth, *sixth;
	
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));
	fifth = (struct Node *)malloc(sizeof(struct Node));
	sixth = (struct Node *)malloc(sizeof(struct Node));
	
	head->data = 10;
	head->next = second;
	
	second->data = 20;
	second->next = third;
	
	third->data = 30;
	third->next = fourth;
	
	fourth->data = 40;
	fourth->next = fifth;
	
	fifth->data = 50;
	fifth->next = sixth;
	
	sixth->data = 60;
	sixth->next = NULL;
	
	printf("Currently the linked list is : \n");
	
	traversal(head);
	printf("\n");
	printf("\nWhich element you want to enter in the node ? ");
	scanf("%d",&element);
	printf("\n");
	head = insertAtBeginning(head,element);
	traversal(head);
	printf("\n");
	
	printf("At which position you want to insert another node ? ");
	scanf("%d",&index);
	printf("\nWhich element you want to enter in the node ? ");
	scanf("%d",&element);
	printf("\n");
	head = insertAtMiddle(head,index,element);
	traversal(head);
	printf("\n");
	
	printf("\nWhich element you want to enter in the node ? ");
	scanf("%d",&element);
	printf("\n");
	head = insertAtEnd(head,element);
	traversal(head);
	printf("\n");
}
