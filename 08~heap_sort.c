#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(int ar[], int n, int i)
{
  int largest = i;    //initialise largest as root
  int lc = 2*i+1;     //left child
  int rc = 2*i+2;     //rigt child

  if (lc < n && ar[lc] > ar[largest])
    largest = lc;

  if (rc < n && ar[rc] > ar[largest])
    largest = rc;

  if (largest != i)
  {
    swap(&ar[i], &ar[largest]);
    heapify(ar, n, largest);     // Recursively heapify the affected sub-tree
  }
}

void heap_sort(int ar[], int n)
{
    for(int i = (n/2)-1; i>=0; i--)
      heapify(ar,n,i);               // Build heap (rearrange array)

    for(int i = n-1; i>=0; i--)     // One by one extract an element from heap
    {
      swap(&ar[0],&ar[i]);          // Move current root to end
      heapify(ar,i,0);             // call max heapify on the reduced heap
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
  heap_sort(ar,n);
  printf("\nThe Sorted array is: ");
  print_array(ar,n);
  printf("\n");
  return 0;
}
