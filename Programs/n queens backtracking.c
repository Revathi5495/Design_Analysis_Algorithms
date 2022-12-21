#include<stdio.h>
int pos[10],count=0,n;

void display();

int place(int k)
{
  int i;
  for(i=1;i<k;i++)
   if((pos[i]==pos[k]) || (i-pos[i]==k-pos[k]) || (i+pos[i]==k+pos[k]))
     return 0;

  return 1;
}


void queen()
{
  int k=1;
  pos[k]=0;

  while(k!=0)
  {
    pos[k]=pos[k]+1;

    while(pos[k]<=n && !place(k))
       pos[k]=pos[k]+1;

    if(pos[k]<=n)

       if(k==n)
       {
            count++;
            printf("\n Solution:%d\n",count);
            display();
       }

       else
       {
        k=k+1;
        pos[k]=0;
       }

    else
       k=k-1;
  }
}

void display()
{
   int i,j;
   for(i=1;i<=n;i++)
   {

    for(j=1;j<=n;j++)
      if(j==pos[i])
            printf(" Q ");
      else
            printf(" _ ");
      printf("\n\n");
   }
}
void main()                                                                   
{
printf("Enter the no of queens:\n");
scanf("%d",&n);
queen();
printf("\n\nTotal no of solutions=%d\n",count);
}
