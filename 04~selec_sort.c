#include <stdio.h>

void swap(int ar[], int x, int y)
{
  int temp = ar[x];
  ar[x] = ar[y];
  ar[y] = temp;
}

int selec_sort(int ar[], int len)
{
  for(int i=0; i<len-1; i++)
  {
    int pos=i;
    for(int j=i+1; j<len; j++)
      if(ar[j]<ar[i] && ar[j]<ar[pos])
        pos = j;
    if(pos!=i)
      swap(ar,pos,i);
  }
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
  selec_sort(ar,n);
  printf("\nThe Sorted array is: ");
  for(int i=0; i<n; i++)
    printf("%d ",ar[i]);
  printf("\n\n");
  return 0;
}
