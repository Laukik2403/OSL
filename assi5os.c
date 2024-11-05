#include<stdio.h>

int main()
{
    int n,m;
    printf("enter the number of process :");
    scanf("%d",&n);
    printf("enter number of resources :");
    scanf("%d",&m);

    int alloc[n][m];
    int max[n][m];
    int aval[m];

    printf("enter the allocation matrics :");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("enter the max matrics :");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("enter the available matrics :");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&aval[i]);
    }

    int need[n][m],f[n],ans[n],ind=0;

    for(int k=0;k<n;k++)
    {
        f[k]=0;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>aval[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[ind++]=i;
                    for(int y=0;y<m;y++)
                    {
                        aval[y]+=alloc[i][y];
                        f[i]=1;
                    }
                }
            }
        }
    }
    printf("print safe sequence :");
    for(int i=0;i<n;i++)
    {
        printf("P%d",ans[i]);
        if(i<n-1) printf("->");
    }
    printf("\n");
    return 0;
}