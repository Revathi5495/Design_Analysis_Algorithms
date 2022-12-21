#include<stdio.h>
void wars();
int a[20][20],n,i,j,k;

void main()
{
            printf("ENTER THE NO OF NODES");
            scanf("%d",&n);
            printf("ENTER THE ADJECENCY MATRIX\n");

            for(i=0;i<n;i++)
            {
                        for(j=0;j<n;j++)
                        {
                                    scanf("%d",&a[i][j]);
                        }

            }

            wars();
}

void wars()
{
            int k;
            for(k=0;k<n;k++)
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            a[i][j]=(a[i][k]&&a[k][j])||a[i][j];
            printf("THE TRANSITIVE MATRIX IS\n");
            for(i=0;i<n;i++)
            {
                        for(j=0;j<n;j++)
                        {
                                    printf("%d\t",a[i][j]);
                        }
                        printf("\n");
            }
            return;
}
