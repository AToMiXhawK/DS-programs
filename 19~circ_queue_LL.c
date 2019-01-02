#include <stdlib.h>
#include <stdio.h>

struct QNode
{
	int key;
	struct QNode *next;
};


struct Queue
{
	struct QNode *front, *rear;
	int size, elts;
};


struct QNode* newNode(int k)
{
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}


struct Queue *createQueue(int s)
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	q->size = s;
	q->elts = 0;
	return q;
}


void enQueue(struct Queue *q, int k)
{
	if((q->elts) == (q->size))
	{
		printf("\nQueue is Full!!\n");
		return;
	}

	struct QNode *temp = newNode(k);
	q->elts++;

	if (q->rear == NULL)
	{
	q->front = q->rear = temp;
	return;
	}


	q->rear->next = temp;
	q->rear = temp;
}


struct QNode *deQueue(struct Queue *q)
{

	if (q->front == NULL)
		return NULL;


	struct QNode *temp = q->front;
	q->front = q->front->next;


	if (q->front == NULL)
	q->rear = NULL;
	q->elts--;
	return temp;
}

void printQueue(struct Queue *q)
{
	printf("\nSize: %d\nElements: %d\n",q->size,q->elts);
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


int main()
{
	int opt, key, size, f=0;
	printf("\nEnter the size of Circular Queue: ");
	scanf("%d",&size);
	struct Queue *q = createQueue(size);
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
