#include <stdio.h>

void swap(int ar[], int x, int y)
{
  int temp = ar[x];
  ar[x] = ar[y];
  ar[y] = temp;
}

void bub_sort(int ar[], int len)
{
  for(int i=0; i<len-1; i++)
    for(int j=0; j<len-i-1; j++)
      if(ar[j+1]< ar[j])
      swap(ar,j,j+1);
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
  bub_sort(ar,n);
  printf("\nThe Sorted array is: ");
  for(int i=0; i<n; i++)
    printf("%d ",ar[i]);
  printf("\n\n");
  return 0;
}
