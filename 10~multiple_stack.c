#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top1, top2;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top1 = -1;
    stack->top2 = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{   return stack->top1 == stack->top2 - 1; }

int isEmpty_s1(struct Stack* stack)
{   return stack->top1 == -1;  }

int isEmpty_s2(struct Stack* stack)
{   return stack->top2 == stack->capacity;  }

void print_s1(struct Stack* stack)
{
  if(stack->top1 == -1)
    printf("Empty!!");
  else
    for(int i=0; i<=(stack->top1); i++)
      printf("%d ",stack->array[i]);
}

void print_s2(struct Stack* stack)
{
  if(stack->top2 == stack->capacity)
    printf("Empty!!");
  else
    for(int i=(stack->capacity)-1; i>=(stack->top2); i--)
      printf("%d ",stack->array[i]);
  printf("\n");
}

void push_s1(struct Stack* stack, int item)
{
    if (isFull(stack))
        printf("\n\nStack Overflow!!\n\n");
    else
      stack->array[++stack->top1] = item;
    printf("\nThe Stack 1 is ");
    print_s1(stack);
    printf("\nThe Stack 2 is ");
    print_s2(stack);
}

void push_s2(struct Stack* stack, int item)
{
    if (isFull(stack))
        printf("\n\nStack Overflow!!\n\n");
    else
      stack->array[--stack->top2] = item;
    printf("\nThe Stack 1 is ");
    print_s1(stack);
    printf("\nThe Stack 2 is ");
    print_s2(stack);
}

void pop_s1(struct Stack* stack)
{
    if (isEmpty_s1(stack))
    {
      printf("\n\nStack 1 Underflow!!\n\n");
    }
    else
      printf("\n%d poped from stack 1\n",stack->array[stack->top1--]);
    printf("\nThe Stack 1 is ");
    print_s1(stack);
    printf("\nThe Stack 2 is ");
    print_s2(stack);
}

void pop_s2(struct Stack* stack)
{
    if (isEmpty_s2(stack))
    {
      printf("\n\nStack 2 Underflow!!\n\n");
    }
    else
      printf("\n%d poped from stack 2\n",stack->array[stack->top2++]);
    printf("\nThe Stack 1 is ");
    print_s1(stack);
    printf("\nThe Stack 2 is ");
    print_s2(stack);
}

int main()
{
	int n, opt, num, p, s, f=0,t=1;
	printf("Enter the combined size of Stack 1 and Stack 2: ");
	scanf("%d",&n);
    struct Stack* stack = createStack(n);
	while(f==0)
	{
		printf("\n(%d) Enter the desired operation: \n\t\t1. PUSH\n\t\t2. POP\n\t\t3. QUIT\n>> ",t);
		scanf("%d",&opt);
		t++;
		switch(opt)
		{
			case 1:
					printf("\nSelect the Stack to perform the operation:\n\t\t1. Stack 1\n\t\t2. Stack 2\n>> ");
					scanf("%d",&s);
					if(s==1)
					{
						printf("\nEnter the element to be Pushed to Top of Stack 1: ");
						scanf("%d",&num);
						push_s1(stack, num);
					}
					else if(s==2)
					{
						printf("\nEnter the element to be Pushed to Top of Stack 2: ");
						scanf("%d",&num);
						push_s2(stack, num);
					}
					else
						printf("\nInvalid Input!!!\n");
					break;

			case 2:
					printf("\nSelect the Stack to perform the operation:\n\t\t1. Stack 1\n\t\t2. Stack 2\n>> ");
					scanf("%d",&s);
					if(s==1)
						pop_s1(stack);
					else if(s==2)
					  pop_s2(stack);
					else
						printf("\nInvalid Input!!!\n");
					break;

			case 3 :
					f = 1;
					printf("\n\t\t\tThankYou for using the program!!\n\n\t\t\t\t\t(%d)\n\n",--t);
					break;

			default:
					printf("Invalid Input!!!!\n\n");
					f = 1;
					break;
		}
	}


    return 0;
}
