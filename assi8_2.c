#include<stdio.h>
#include<stdlib.h>

int absolutevalue(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

void scan(int request[],int n,int head,int discsize)
{
    int totalseek=0,seek=0,i,j;

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(request[i]>request[j])
            {
                int temp=request[i];
                request[i]=request[j];
                request[j]=temp;
            }
        }
    }

    printf("seek sequence :");
    for(int i=0;i<n;i++)
    {   
        if(request[i]>=head)
        {
        seek=absolutevalue(head-request[i]);
        totalseek += seek;
        printf("head moves from %d to %d with seek %d",head,request[i],seek);
        head=request[i];
        }
    }

        seek=absolutevalue(head-discsize);
        totalseek += seek;
        printf("head moves from %d to %d with seek %d",head,discsize,seek);
        head=discsize;

    for(int i=n-1;i>=0;i--)
    {   
        if(request[i]<head)
        {
        seek=absolutevalue(head-request[i]);
        totalseek += seek;
        printf("head moves from %d to %d with seek %d",head,request[i],seek);
        head=request[i];
        }
    }
    printf("total seek is %d",totalseek);
}

int main()
{
    int n,head,discsize;
    printf("enter the discsize :");
    scanf("%d",&discsize);
    printf("enter request :");
    scanf("%d",&n);
    int request[n];
    printf("request sequences :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request[i]);
    }
    printf("enter the head position :");
    scanf("%d",&head);
    scan(request,n,head,discsize);
    return 0;
}