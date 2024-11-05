#include<stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 50

int n;
int nf;
int pages[MAX_PAGES];
int frames[MAX_FRAMES];
int pagefaultcount=0;

void getdata()
{
    printf("enter the number of pages :")
    scanf("%d",&n);
    printf("enter the page sequence :")
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("enter the number of frames :");
    scanf("%d",&nf);
}

void initializeframe()
{
    for(int i=0;i<nf;i++)
    {
        frames[i]=-1;
    }
    pagefaultcount=0;
}

void ispagehit(int page)
{
    for(int i=0;i<nf;i++)
    {
        if(frames[i]==page)
        {
            return 1;
        }
    }
    return 0;
}

void displayframes()
{
    for(int i=0;i<nf;i++)
    {
        if(frames[i] != -1)
        {
            printf("%d",frames[i])
        }
    }
    printf("\n");
}

void fifo()
{
    initializeframe();
    int nextframe=0;

    for(int i=0;i<n;i++)
    {
        printf("page reference %d",pages[i]);
        if(!ispagehit(pages[i]))
        {
            frames[nextframe]=pages[i];
            nextframe=(nextframe+1)%nf;
            pagefaultcount++;
            displayframes();
        }
        else
        {
            printf("no page fault ...");
        }
    }
    printf("total page fault %d",pagefaultcount);
}

void optimal()
{
    initializeframe();
    for(int i=0;i<n;i++)
    {
        printf("page references %d",pages[i]);
        if(!ispagehit(pages[i]))
        {
            int farthest=-1;
            int replaceindex=-1;
            for(int j=0;j<nf;j++)
            {
                int next=-1;
                for(k=i+1;k<n;k++)
                {
                    if(frames[j]==pages[k])
                    {
                        next=k;
                        break;
                    }
                }
                if(next==-1)
                {
                    replaceindex=j;
                    break;
                }
                if(next>farthest)
                {
                    farthest=next;
                    replaceindex=j;
                }
            }
            frames[replaceindex]=pages[i];
            pagefaultcount++;
            displayframes();
        }
        else
        {
            printf("no page fault ....");
        }
    }
    printf("total page fault ...%d",pagefaultcount);
}

void lru()
{
    initializeframe();
    int leastrecentlyused[MAX_FRAMES];

    for(int i=0;i<n;i++)
    {
        printf("page references :",pages[i]);
        if(!ispagehit(pages[i]))
        {
            for(int j=0;j<nf;j++)
            {
                leastrecentlyused[j]=-1;
                for(int k=i-1;k>=0;k--)
                {
                    if(frames[j]==pages[k])
                    {
                        leastrecentlyused[j]=k;
                        break;
                    }
                }
            }
            int lruindex=0;
            for(int j=1;j<nf;j++)
            {
                if(leastrecentlyused[j]<leastrecentlyused[lruindex] && leastrecentlyused[j] != -1)
                {
                    lruindex=j
                }
            }
            frames[lruindex]=pages[i];
            pagefaultcount++;
            displayframes();
        }
        else
        {
            printf("no page fault ...");
        }
    }
    printf("total page fault .. %d",pagefaultcount);
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n page scheduling algorithms \n1.enter data \n2.fifo \n3. optimal \n4. lru \n5. exit \nenter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                getdata();
                break;
            case 2:
                fifo();
                break;
            case 3:
                optimal();
                break;
            case 4:
                lru();
                break;
            case 5:
                return 0;
            default:
                printf("enter valid choice ...");
                break;
        }
    }
}