#include<stdio.h>
#include<stdlib.h>

int absolutevalue(int x)
{
    if(x<0)
        return -x;
    else    
        return x;
}

void clock(int request[],int n,int head)
{
    int totalseek=0,seek=0,i,j,temp;
    int temp1=0,temp2=0,queue1[20],queue2[20];

    for(int i=0;i<n;i++)
    {
        if(request[i]>head)
            queue1[temp1++]=request[i];
        else    
            queue2[temp2++]=request[i];
    }

    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(queue1[i]>queue1[j])
            {
                    temp=queue1[i];
                    queue1[i]=queue1[j];
                    queue1[j]=temp;
            }
        }
    }

    for(i=0;i<temp2-1;i++)
    {
        for(j=i+1;j<temp2;j++)
        {
            if(queue2[i]>queue2[j])
            {
                    temp=queue2[i];
                    queue2[i]=queue2[j];
                    queue2[j]=temp;
            }
        }
    }

    for(int i=0;i<temp1;i++)
    {
        seek=absolutevalue(head-queue1[i]);
        totalseek += seek;
        printf("head moves from %d to %d with seek",head,queue1[i],seek);
        head=queue1[i];
    }

     for(int i=0;i<temp2;i++)
    {
        seek=absolutevalue(head-queue2[i]);
        totalseek += seek;
        printf("head moves from %d to %d with seek",head,queue2[i],seek);
        head=queue2[i];
    }

    printf("total seek time %d",totalseek);
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
    clock(request,n,head);
    return 0;
}