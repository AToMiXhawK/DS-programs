#include <stdio.h>

void merge(int ar[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m -l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for(i=0; i<n1; i++)
    L[i]=ar[l + i];
  for(j=0; j<n2; j++)
    R[j]=ar[m + 1 + j];

  i=0;
  j=0;
  k=l;

  while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
      ar[k] = L[i];
      i++;
      k++;
    }

    while (j < n2)
    {
      ar[k] = R[j];
      j++;
      k++;
    }
}

void merge_sort(int ar[], int l, int r)
{
  if(l<r)
  {
    int m=(l+r)/2;
    merge_sort(ar,l,m);
    merge_sort(ar,m+1,r);
    merge(ar,l,m,r);
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
  merge_sort(ar,0,n-1);
  printf("\nThe Sorted array is: ");
  print_array(ar,n);
  printf("\n");
  return 0;
}
