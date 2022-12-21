#include<stdio.h>  
int temp;  
  
void heapify(int arr[], int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != i)  
{  
temp = arr[i];  
    arr[i]= arr[largest];   
    arr[largest] = temp;  
heapify(arr, size, largest);  
}  
}  
  
void heapSort(int arr[], int size)  
{  
int i;  
for (i=size/2-1;i>=0;i--)  
heapify(arr,size,i);  
for (i=size-1;i>=0;i--)  
{  
temp=arr[0];  
    arr[0]=arr[i];   
    arr[i]=temp;  
heapify(arr,i,0);  
}  
}  
  
void main()  
{  
/*int arr[] = {1,45,12,56,10,2,0};  
int i;  
int size = sizeof(arr)/sizeof(arr[0]);*/
int arr[10],n,i;
printf("enter number of elements:");
scanf("%d",&n);
for(i=1;i<n;i++)
{
	scanf("%d ",&arr[i]);
}/*
printf("you are given elements are:");   
for (i=0; i<size; ++i)  
printf("%d  ",arr[i]);  */ 
int size=n;
heapSort(arr, size);   
printf("\nprinting sorted elements\n");  
for (i=0; i<size; ++i)  
printf("%d  ",arr[i]);  
}  
