#include<stdio.h>
int main()
{
	int n=5;
	int m[5][5]={0};
	int s[5][5]={0};
	int p[5];
	int min,q,i,j,k,d;
	printf("enter the order of the 4 matrices:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(d=1;d<n-1;d++)
    {
    	for(i=1;i<n-d;i++)
    	{
    		j=i+d;
    		min=32767;
    		for(k=i;k<=j-1;k++)
    		{
    			q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
    			if(q<min)
    			{
    				min=q;
    				s[i][j]=k;
				}
			}
			m[i][j]=min;
		}
	}
	printf("%d",m[1][n-1]);
}
