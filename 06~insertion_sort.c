#include <stdio.h>

void ins_sort(int ar[], int len)
{
  for(int i=1; i<len; i++)
  {
    int key = ar[i];
    int j = i-1;

    while(j>=0 && ar[j]>key)
    {
      ar[j+1] = ar[j];
      j--;
    }
    ar[j+1] = key;
  }
}

void print_array(int ar[], int len)
{
  for(int i=0; i<len; i++)
    printf("%d ",ar[i]);
  printf("\n");
}

int main()
{
  int n;
  printf("\nEnter the size of the array: ");
  scanf("%d",&n);
  int ar[n];
  printf("\nEnter the elemnts: \n");
  for(int i=0; i<n; i++)
    scanf("%d",&ar[i]);
  printf("The array given is: ");
  print_array(ar,n);
  ins_sort(ar,n);
  printf("\nThe Sorted array is: ");
  print_array(ar,n);
  printf("\n");
  return 0;
}
