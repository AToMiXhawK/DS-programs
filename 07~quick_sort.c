#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int ar[], int l, int h)
{
  int pivot = ar[h];
  int i = l-1;  //index of lowest elemnt

  for(int j = l; j<h; j++)
  {
    if(ar[j]<=pivot)
    {
      i++;
      swap(&ar[i],&ar[j]);
    }
  }
  swap(&ar[i+1],&ar[h]);
  return i+1;
}

void quick_sort(int ar[], int l, int h)
{
  if(l<h)
  {
    int pi = partition(ar,l,h);

    quick_sort(ar,l,pi-1);
    quick_sort(ar,pi+1,h);
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
  quick_sort(ar,0,n-1);
  printf("\nThe Sorted array is: ");
  print_array(ar,n);
  printf("\n");
  return 0;
}
