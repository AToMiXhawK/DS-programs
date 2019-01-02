#include <stdlib.h>
#include <stdio.h>

// A linked list (LL) node to store a queue entry
struct QNode
{
	int key;
	struct QNode *next;
};

// The queue, front stores the front node of LL and rear stores ths
// last node of LL
struct Queue
{
	struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
struct Queue *createQueue()
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

// The function to add a key k to q
void enQueue(struct Queue *q, int k)
{
	// Create a new LL node
	struct QNode *temp = newNode(k);

	// If queue is empty, then new node is front and rear both
	if (q->rear == NULL)
	{
	q->front = q->rear = temp;
	return;
	}

	// Add the new node at the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp;
}

// Function to remove a key from given queue q
struct QNode *deQueue(struct Queue *q)
{
	// If queue is empty, return NULL.
	if (q->front == NULL)
	return NULL;

	// Store previous front and move front one node ahead
	struct QNode *temp = q->front;
	q->front = q->front->next;

	// If front becomes NULL, then change rear also as NULL
	if (q->front == NULL)
	q->rear = NULL;
	return temp;
}

void printQueue(struct Queue *q)
{
	if (q->front == NULL)
	{
		printf("Queue is Empty!!\n");
		return;
	}
	printf("Now the Queue is: ");
	struct Queue *tempq = q;
	struct QNode *tempn = tempq->front;
	int f=0;
	while(f==0)
	{
		printf(" %d ",tempn->key);
		if(tempn->next == 0)
			break;
		tempn=tempn->next;
	}
	printf("\n");
	return;
}

// Driver Program to test above functions
int main()
{
	int opt, key, f=0;
	struct Queue *q = createQueue();
	struct QNode *n;
	while(f==0)
	{
		printf("\nEnter the desired option:\n\t\t\t1. Enqueue\n\t\t\t2. Dequeue\n\t\t\t3. Exit\n: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&key);
				enQueue(q, key);
				printQueue(q);
				break;

			case 2:
				n = deQueue(q);
				if (n != NULL)
				{
					printf("\nDequeued item is %d\n", n->key);
					printQueue(q);
				}
				else
					printf("\nQueue is Empty!!\n");
				break;

			case 3:
				printf("\nThankyou for using the program!!\n\n");
				f=1;
				break;
			default:
				printf("\nInvalid Input!!\n");

		}
	}
	return 0;
}
