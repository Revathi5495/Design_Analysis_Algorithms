#include<stdio.h>
void merge(int *a,int low,int high,int mid)
{
	int i=low;
	int j=mid+1;
	int k=low;
	int b[100];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
   {

		b[k]=a[i];
		i++;
		k++;
	}
	else
	{
		b[k]=a[j];
		j++;
		k++;
	}
}
	while(i<=mid)
	{
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		k++;
		j++;
	}

	for(i=low;i<k;i++)

		a[i]=b[i];
}
void merge_sort(int *a,int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high,mid);
	}
}
int main()
{
	int n,i,a[100];
	printf("enter the size of the array:");
	scanf("%d",&n);
	printf("enter the elements:");
	for(i=0;i<n;i++)
	{
    scanf("%d",&a[i]);
	}
	merge_sort(a,0,n-1);
	printf("after appling merge sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
