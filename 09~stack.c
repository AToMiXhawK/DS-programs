#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int top;
  unsigned capacity;
  int *array;
};

struct Stack* createStack(unsigned capacity)
{
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int *)malloc(stack->capacity*sizeof(int));
  return stack;
}

int isFull(struct Stack* stack)
{ return stack->top == stack->capacity - 1; }

int isEmpty(struct Stack* stack)
{ return stack->top == -1; }

void print_stack(struct Stack* stack)
{
  if(stack->top == -1)
    printf("Empty!!");
  else
    for(int i=0; i<=(stack->top); i++)
      printf("%d ",stack->array[i]);
}

void push(struct Stack* stack, int item)
{
  if(isFull(stack))
  {
    printf("\n\nStack Overflow!!\n\n");
    return;
  }
  stack->array[++stack->top] = item;
  printf("\nThe Stack is ");
  print_stack(stack);
  return;
}

void pop(struct Stack* stack)
{
  if(isEmpty(stack))
  {
    printf("\n\nStack Underflow!!\n\n");
    return;
  }
  printf("\n%d poped from stack\n",stack->array[stack->top--]);
  printf("\nThe Stack is ");
  print_stack(stack);
  return;
}

int main()
{
	int n, o, elt;
	printf("Enter the size of the Stack: ");
	scanf("%d",&n);
    struct Stack* stack = createStack(n);

	while(1)
	{
  	printf("\n\nEnter the required option:\n\t\t1.Push\n\t\t2.pop\n\t\t3.Exit\noption: ");
  	scanf("%d",&o);
  	switch(o)
  	{
  		case 1:
  				printf("\nEnter the element to be pushed: ");
  				scanf("%d",&elt);
  				push(stack, elt);
  				break;
  		case 2:
  				pop(stack);
  				break;
  		case 3:
  				printf("\nThankYou for using the program\n\n");
  				return 0;
  				break;
  		default:
  				printf("Invalid Input!!\n");
  	}
	}
}
