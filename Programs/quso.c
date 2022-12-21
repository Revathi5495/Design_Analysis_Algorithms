#include<stdio.h>
void quicksort(int a[],int,int);
int main()
{
	int a[20],i,n;
	printf("enter the size of the array:");
	scanf("%d",&n);
	printf("enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("\n applying the quick sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
void quicksort(int a[],int low,int high)
{
	int pivot,i,j,temp;
	if(low<high)
	{
		pivot=low;
		i=low;
		j=high;
	while(i<j)
	{
		while(a[i]<=a[pivot] && i<=high)
		{
			i++;
		}
		while(a[j]>a[pivot] && j>=low)
		{
			j--;
		}
		if(i<j)
		{

		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	}
	temp=a[j];
	a[j]=a[pivot];
	a[pivot]=temp;
	quicksort(a,low,j-1);
	quicksort(a,j+1,high);
}
}
