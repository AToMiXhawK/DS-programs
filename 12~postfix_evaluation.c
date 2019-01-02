// when compiling this program in gcc there will be an error
// to solve it do:
// gcc *program_name* -lm
// i.e. add -lm to the end of gcc command
// e.g. gcc 12~postfix_evaluation.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stack[20];
int top = -1;

void push(int x)
{  stack[++top] = x;  }

int pop()
{  return stack[top--];   }

int main()
{
  char exp[20], *e;
  int num, n1, n2;
  printf("Enter the postfix expression: ");
  scanf("%s",exp);
  e = exp;
  while(*e != '\0')
  {
    if(isalpha(*e))         //check if isOperand
    {
      printf("Enter the value of %c: ",*e);
      scanf("%d",&num);
      push(num);
    }

    else                    //if operator
    {
      n1=pop();
      n2=pop();
      switch(*e)
      {
        case '+':
                  num = n2 + n1;
                  break;
        case '-':
                  num = n2 - n1;
                  break;
        case '*':
                  num = n2 * n1;
                  break;
        case '/':
                  num = n2/n1;
                  break;
        case '^':
                  num = pow(n2,n1);
                  break;
      }
      push(num);
    }

    e++;
  }

  printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
        return 0;
}
