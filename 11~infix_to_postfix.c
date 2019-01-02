#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
  int top;
  unsigned capacity;
  int *array;
};

struct Stack* createStack(unsigned capacity)
{
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int*)malloc((stack->capacity)*sizeof(int));
  return stack;
}

int isEmpty(struct Stack* stack)
{ return stack->top == -1;  }

void push(struct Stack* stack, char op)
{ stack->array[++stack->top] = op;  }

char pop(struct Stack* stack)
{ return stack->array[stack->top--];  }

char peek(struct Stack* stack)
{ return stack->array[stack->top];  }

int isOperand(char ch)
{ return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch >= 'Z'); }

int prec(char ch)
{
  switch (ch)
  {
    case '+':
    case '-':
              return 1;
    case '*':
    case '/':
              return 2;
    case '^':
              return 3;
  }
  return -1;
}

void infix_to_postfix(char* exp)
{
  struct Stack* stack = createStack(strlen(exp));
  int i, k;
  for(i=0, k=-1; exp[i]; ++i)
  {
    if(isOperand(exp[i]))
      exp[++k]=exp[i];

    else if(exp[i]=='(')
      push(stack, exp[i]);

    else if(exp[i]==')')
    {
      while(!isEmpty(stack) && peek(stack) != '(')
        exp[++k]=pop(stack);
      pop(stack);
    }

    else                    //an operator is encountered
    {
      while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
        exp[++k]=pop(stack);
      push(stack,exp[i]);
    }
  }

  while(!isEmpty(stack))        //pop all remaining operator in stack
    exp[++k]=pop(stack);

  exp[++k]='\0';
  printf("%s\n",exp);
}

int main()
{
	char exp[20];
	printf("Enter the Infix expression: ");
	fgets(exp,20,stdin);
  printf("The Postfix expresion is: ");
  infix_to_postfix(exp);
  return 0;
}
