#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insert_beg(struct Node** head, int new_data)
{

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head);
    (*head)    = new_node;
}

void insert_end(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head == NULL)
    {
       *head = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}


void printList(struct Node *node)
{
  if(node == NULL)
  	printf("\nNo Elements in Queue!!\n\n");
  else
  {
  	printf("\nQueue is: ");
  	while (node != NULL)
  	{
     	printf(" %d ", node->data);
     	node = node->next;
  	}
  	printf("\n");
  }
}

void delete_beg(struct Node** head)
{
	if((*head) == NULL )
	{
		printf("\nNo Element to be deleted\n");
		return;
	}
	struct Node *next_node = (*head);
	printf("\nDequeued item is %d\n",next_node->data);
	(*head)    = next_node->next;
	return;
}

void delete_end(struct Node** head)
{
	if((*head) == NULL )
	{
		printf("\nNo Element to be deleted\n");
		return;
	}
	struct Node *next_node = (*head);
	if(next_node->next == NULL)
	{
		printf("\nDequeued item is %d\n",next_node->data);
		*head = NULL;
		return;

	}
	struct Node *prev_node = (*head);
	next_node = next_node->next;
	while (next_node->next != NULL)
	{
        	next_node = next_node->next;
       		prev_node = prev_node->next;
    	}
   	printf("\nDequeued item is %d\n",next_node->data);
    	prev_node->next = NULL;
    return;
}

int main()
{
	struct Node* head = NULL;
	int o, elt, key, f = 0;
  	while(f==0)
	{
  		printf("\nEnter the Desired option: \n");
  		printf("\t\t1. Insert at the front\n");
  		printf("\t\t2. Insert at the rear\n");
  		printf("\t\t3. Delete from the front\n");
  		printf("\t\t4. Delete from the rear\n");
  		printf("\t\t5. Exit\n");
  		printf(": ");
  		scanf("%d",&o);
		switch(o)
		{
			case 1:
					printf("\nEnter the element to be inserted at front: ");
					scanf("%d",&elt);
					insert_beg(&head, elt);
					printList(head);
					break;

			case 2:
					printf("\nEnter the element to be inserted at rear: ");
					scanf("%d",&elt);
					insert_end(&head, elt);
					printList(head);
					break;

			case 3:
					delete_beg(&head);
					printList(head);
					break;

			case 4:
					delete_end(&head);
					printList(head);
					break;

			case 5:
					f = 1;
					printf("\nThankYou for using the program!!\n\n");
					break;

			default:
					printf("Invalid Input!!!!\n\n");
					//f = 1;
					break;
  		}
  	}
  	return 0;
}
