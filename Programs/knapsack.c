#include<stdio.h>
int max(int a,int b)
{
	if(a>=b)
	 return a;
	else 
	  return b;
}
int main()
{
	int p[10],wt[10],m,n,w,i,j;
	printf("enter total number of objects:");
	scanf("%d",&n);
    printf("enter capacity of the bag:");
	scanf("%d",&m);
	printf("enter the profit of each object:");
	for(i=1;i<n+1;i++)
	{
		p[0]=0;
		scanf("%d",&p[i]);
	}
    printf("enter the weight of each object:");
	for(i=1;i<n+1;i++)
	{
		wt[0]=0;
		scanf("%d",&wt[i]);
	}
	int k[n+1][m+1];
	for(i=0;i<=n;i++)
	{
	  for(w=0;w<=m;w++)
	  {
	    if(i==0||w==0)
	    {
	  	  k[i][w]=0;
	    }
		else if(wt[i]<=w)
		{
		   k[i][w]=max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);
    	}
	    else
	    {
		 k[i][w]=k[i-1][w];
    	}
	  }
	}
	printf("total profit of the bag is ---> %d",k[n][m]);
	i=n;j=m;
	printf("\nthe objects in bag are:\n");
	while(i>0&&j>0)
	{
		if(k[i][j]==k[i-1][j])
		{
			printf("%d=0\n",i);i--;
		}
		else
		{
			printf("%d=1\n",i);
			j=j-wt[i];
			i--;		
	    }
	}
	printf("\nhere not mentioned object and assigned with zero object be the not included in the bag ");
}
