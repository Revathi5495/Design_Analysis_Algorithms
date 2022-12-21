#include<stdio.h>
# define L 999
int a[10][10],n,visit[10];
int cost_opt=0;
int optimal(int c)
{
  int i,nc=L;
  int min=L,kmin=L;
    for(i=1;i<=n;i++)
        {
         if((a[c][i]!=0)&&(visit[i]==0))
            if(a[c][i]<min)
            {
            min=a[i][1]+a[c][i];
            kmin=a[c][i];
             nc=i;
            }
         }
      if(min!=L)
        cost_opt+=kmin;
   return nc;
}
void mincost(int city)
{
 int i,ncity;
  visit[city]=1;
  printf("%d-->",city);
  ncity=optimal(city);
  if(ncity==L)
  {
      ncity=1;
      printf("%d",ncity);
      cost_opt+=a[city][ncity];
      return;
      }
      mincost(ncity);
}
 void main()
{
    int i,j;
      printf("Enter No. of cities:\n");
      scanf("%d",&n);

    printf("Enter the cost matrix\n");
      for(i=1;i<=n;i++)
        {
         for(j=1;j<=n;j++)
		     scanf("%d",&a[i][j]);
             visit[i]=0;
       }
     printf("The cost list is \n");
        for(i=1;i<=n;i++)
          {
           printf("\n");
           for(j=1;j<=n;j++)
               printf("\t%d",a[i][j]);
            }
    printf("\n Optimal Solution :\n");
    printf(" * The path is :\n");
    mincost(1);
     printf("\n  * Minimum cost:");
     printf("%d",cost_opt);
}
