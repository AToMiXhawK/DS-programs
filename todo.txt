!!14~Doubly linkedlist
!!15~circular linkedlist
16~polynomial addn, multiplication
!!21~binary search tree

*/ Doubly linked list testing

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insert_beg(struct Node** head, int new_data)
{

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head);
    new_node->prev = head;
    (*head)    = new_node;
    printf("\n%d inserted at the begining of the linked list\n",new_data);
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
       new_node->prev = head;
       return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
    printf("\n%d appended at the end of the linked list\n",new_data);
    return;
}

void insert_mid(struct Node** head, int new_data, int key)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head;

	while (last->next != NULL)
	{
		if(last->data == key)
		{
			new_node->data = new_data;
			new_node->next = last->next;
      new_node->prev = last;
      new_node->next->prev = new_node;
			last->next = new_node;
			printf("\n%d inserted after %d in the linked list\n",new_data,key);
			return;
		}
        last = last->next;
    }
    if(last->data == key)
		{
			printf("\n%d inserted after %d in the linked list\n",new_data,key);
    		new_node->data  = new_data;
    		new_node->next = NULL;
        new_node->prev = last;
    		last->next = new_node;
    		return;
		}
	else
    	printf("\nKey Not Found\n");
    return;
}

void printList(struct Node *node)
{
  if(node == NULL)
  	printf("\nNo Elements in Linked List!!\n\n");
  else
  {
  	printf("\nLinked list is: ");
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
  if(next_node->next == NULL)
  {
    printf("\n%d deleted from linked list\n",next_node->data);
    *head = NULL;
    return;
  }
	printf("\n%d deleted from linked list\n",next_node->data);
	(*head) = next_node->next;
  next_node->next->prev = head;
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
    printf("\n%d deleted from linked list\n",next_node->data);
    *head = NULL;
    return;
  }
	while (next_node->next != NULL)
        next_node = next_node->next;
  printf("\n%d deleted from linked list\n",next_node->data);
  next_node->prev->next= NULL;
  return;
}

int main()
{
	struct Node* head = NULL;
	int o, elt, key, f = 0;
  	while(f==0)
	{
  		printf("\nEnter the Desired option: \n");
  		printf("\t\t1. Insert at the begining\n");
  		printf("\t\t2. Insert at the end\n");
  		printf("\t\t3. Insert after a particular node (In Between)\n");
  		printf("\t\t4. Delete from the begining\n");
  		printf("\t\t5. Delete from the end\n");
  		printf("\t\t6. Delete a particular node\n");
  		printf("\t\t7. Exit\n");
  		printf(": ");
  		scanf("%d",&o);
		switch(o)
		{
			case 1:
					printf("\nEnter the data to be inserted at the begining: ");
					scanf("%d",&elt);
					insert_beg(&head, elt);
          printList(head);
					break;

			case 2:
					printf("\nEnter the data to be inserted at the end: ");
					scanf("%d",&elt);
					insert_end(&head, elt);
          printList(head);
					break;

			case 3:
					printf("\nEnter the key element after to which the data is to be inserted: ");
					scanf("%d",&key);
					printf("\nEnter the data to be inserted at the begining: ");
					scanf("%d",&elt);
					insert_mid(&head, elt, key);
          printList(head);
					break;

      case 4:
    			delete_beg(&head);
          printList(head);
					break;

    	case 5:
  				delete_end(&head);
          printList(head);
    			break;

			case 7:
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

/*
