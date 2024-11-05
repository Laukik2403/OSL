#include<stdio.h>
#include<stdlib.h>

int request[50];
long size;
int visited[50];

int absdiff(int a,int b)
{
    if(a>b)
        return a-b;
    else
        return b-a;
}

int findclosest(int head,int n)
{
    int mindist=9999,index=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            int distance=absdiff(head,request[i]);
            if(distance<mindist)
            {
                mindist=distance;
                index=i;
            }
        }
    }
    return index;
}

void sstf(int n)
{
    int head,totalseek=0;
    printf("enter the head position :");
    scanf("%d",&head);
    printf("seek sequence :");
    for(int i=0;i<n;i++)
    {
        int closest=findclosest(head,n);
        if(closest != -1)
        {
            visited[closest]=1;
            printf("head %d",head);
            totalseek +=absdiff(head,request[closest]);
            head=request[closest];
        }
    }
    printf("total seek sequence %d",totalseek);
}

int main()
{
    int n;
    printf("enter disc size :");
    scanf("%d",&size);
    printf("enter request :");
    scanf("%d",&n);
    printf("enter request sequence :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request[i]);
        visited[i]=0;
    }
    sstf(n);
    return 0;
}
