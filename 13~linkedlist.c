#include <stdio.h>
#include <stdlib.h>

struct Node                               // Create a structure for node
{
  int data;
  struct Node *next;
};

void insert_beg(struct Node** head, int new_data)       // insert at the beginning of list
{

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head);
    (*head)    = new_node;
    printf("\n%d inserted at the begining of the linked list\n",new_data);
}

void insert_end(struct Node** head, int new_data)     // insert at the end of list
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head == NULL)                          // check list is empty
    {
       *head = new_node;
       return;
    }
    while (last->next != NULL)                 // traverse to last node
        last = last->next;

    last->next = new_node;
    printf("\n%d appended at the end of the linked list\n",new_data);
    return;
}

void insert_mid(struct Node** head, int new_data, int key)      // insert after a given key if exixts
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head;

	while (last->next != NULL)                 // traverse to node with given key
	{
		if(last->data == key)
		{
			new_node->data = new_data;
			new_node->next = last->next;
			last->next = new_node;
			printf("\n%d inserted after %d in the linked list\n",new_data,key);
			return;
		}
        last = last->next;
  }
  if(last->data == key)             // check if the last node is the key
	{
			printf("\n%d inserted after %d in the linked list\n",new_data,key);
    		new_node->data  = new_data;
    		new_node->next = NULL;
    		last->next = new_node;
    		return;
	}
	else
    	printf("\nKey Not Found\n");
  return;
}

void printList(struct Node *node)           // function to print the linkedlist
{
  if(node == NULL)          // check list is empty
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

void delete_beg(struct Node** head)     // delete node from beginning
{
	if((*head) == NULL )                         // check list is empty
	{
		printf("\nNo Element to be deleted\n");
		return;
	}
	struct Node *next_node = (*head);
	printf("\n%d deleted from linked list\n",next_node->data);
	(*head) = next_node->next;
	return;
}

void delete_end(struct Node** head)     // delete node from the end of list
{
	if((*head) == NULL )                       // check list is empty
	{
		printf("\nNo Element to be deleted\n");
		return;
	}
  struct Node *next_node = (*head);
  if(next_node->next == NULL)             // check if the fist node is the last node (only 1 node in list)
  {
    printf("\n%d deleted from linked list\n",next_node->data);
    *head = NULL;
    return;
  }
	struct Node *prev_node = (*head);
	next_node = next_node->next;
	while (next_node->next != NULL)      // traverse to the last
	{
        next_node = next_node->next;      // last node
        prev_node = prev_node->next;      // second last node
    }
    printf("\n%d deleted from linked list\n",next_node->data);
    prev_node->next = NULL;              // link part of decond last node set to NULL
    return;
}

void delete_mid(struct Node** head, int key)      // delete node with given key
{
	if((*head) == NULL )                       // check list is empty
	{
		printf("\nNo Element to be deleted\n");
		return;
	}
	struct Node *next_node = (*head);      // node with given key
	struct Node *prev_node = (*head);      // node previous to given key
	if(next_node->data == key)             // check if first node is the key
		{
			printf("\n%d deleted from linked list\n",next_node->data);
    		(*head)    = next_node->next;
    		return;
		}
	next_node = next_node->next;
	while (next_node->next != NULL)        // traverse to key
	{
		if(next_node->data == key)
		{
			printf("\n%d deleted from linked list\n",next_node->data);
    		prev_node->next = next_node->next;
    		return;
		}
		next_node = next_node->next;
        prev_node = prev_node->next;
	}
	if(next_node->data == key)             // check if the last node is the key
		{
			printf("\n%d deleted from linked list\n",next_node->data);
    		prev_node->next = NULL;
    		return;
		}
	else
		printf("\nKey Not Found\n");
	return;
}

int main()                            // main function
{
	struct Node* head = NULL;           // set head = NULL to initialise the list
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

			case 6:
					printf("\nEnter the Key element to be deleted: ");
					scanf("%d",&key);
					delete_mid(&head, key);
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
