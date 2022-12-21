#include<stdio.h>
int min(int a,int b)
{
	if(a<=b)
		return a;
	else
	    return b;
}
int all_pair(int d,int v)
{
	int i,j,k,n;
	n=v;
    for(k=0;k<n;k++)
      for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          {
          	 d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		  }
}
int main()
{
	int d[10][10],v,i;
	printf("enter the number of vertices of graph:");
	scanf("%d",&v);
	printf("enter the weights of each vertices in matrix:");
	for(i=0;i<v;i++)
	   for(j=0;j<v;j++)
     	{
         scanf("%d",&d[i][j]);  
	    }
	all_pair(d,v);
	for(i=0;i<v;i++)
	   for(j=0;j<v;j++)
	   {
         printf(" %d",d[i][j]);
		   	
        }
}
