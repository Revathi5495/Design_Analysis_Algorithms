#include<stdio.h>
int main()
{
	int n=3,m=6;
	int p[]={0,1,2,3};
	int w[]={0,3,4,2};
	/*dkp(p,w,n,m);*/
	printf("%d",p[1]);
}
int dkp(int p,int w,int n,int m)
{
    int s[]={(0,0)};
    int s1[10],i;
	for(i=0;i<n;i++)
	{
		s1[i]=s[i]+(p[i+1],w[i+1]);
    }
}
