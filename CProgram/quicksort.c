#include<stdio.h>
void quicksort( int a[], int low, int high )
{
 int pivot;
 if ( high > low )
 {
  pivot = partition( a, low, high );
  quicksort( a, low, pivot-1 );
  quicksort( a, pivot+1, high );
 }
} 
int partition( int a[], int low, int high)
{
int p=low,pivot=a[low],loc;
for(loc=low+1;loc<=high;loc++)
{
if(pivot > a[loc])
{
a[p] = a[loc];
a[loc] = a[p+1];
a[p+1] = pivot;
p=p+1;	
}	
}	
return p;
}
void main()
{
 int a[50], i, n;
 printf("Enter no. of elements: ");
 scanf("%d", &n);
 printf("Enter the elements : ");
 for (i=0; i<n; i++)
  scanf ("%d",&a[i]);
 quicksort(a,0,n-1);
 printf("Sorted elements : ");
 for(i=0;i<n;i++)
 printf("%d ",a[i]);
 getch();
}

