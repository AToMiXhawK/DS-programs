#include <stdio.h>

int bin_search(int ar[], int len, int key)
{
  int mid, first = 0, last = len-1;
  while(first<=last)
  {
    mid=(first+last)/2;
    if(ar[mid]==key)
      return mid;
    else if(key<ar[mid])
      last=mid-1;
    else
      first=mid+1;
  }
  return -1;
}

int main()
{
  int n, key, f;
  printf("\nEnter the size of the array: ");
  scanf("%d",&n);
  int ar[n];
  printf("\nEnter the elemnts: \n");
  for(int i=0; i<n; i++)
    scanf("%d",&ar[i]);
  printf("\nEnter the key: ");
  scanf("%d",&key);
  f = bin_search(ar,n,key);
  if(f==-1)
    printf("\nKey Not Found\n\n");
  else
    printf("\nKey found at %d\n\n",f);
  return 0;
}
