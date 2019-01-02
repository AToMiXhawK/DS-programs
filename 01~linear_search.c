#include <stdio.h>

int linear_search(int* ar, int len, int key)
{
  for(int i=0; i<len; i++)
  {
    if(*ar == key)
      return i;
    ar++;
  }
  return -1;
}

int main()
{
  int n, key, f;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int ar[n];
  printf("\nEnter the elemnts: \n");
  for(int i=0; i<n; i++)
    scanf("%d",&ar[i]);
  printf("\nEnter the key: ");
  scanf("%d",&key);
  f = linear_search(ar,n,key);
  if(f==-1)
    printf("\nKey Not Found\n");
  else
    printf("\nKey found at %d\n",f);
  return 0;
}
