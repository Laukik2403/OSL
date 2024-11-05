#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void printarray(int arr[],int size);
void bubblesort(int arr[],int size);
void insertionsort(int arr[],int size);

void bubblesort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionsort(int arr[],int size)
{
    for(in i=1;i<size;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]=key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n,i;
    printf("enter the number of intergers :");
    scanf("%d",&n);

    int *arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        perror("failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    printf("enter the integers :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("unsorted array...");
    printarray(arr,n);

    pid_t pid=fork();

    if(pid<0)
    {
        perror("failed to load..");
        free(arr);
        exit(EXIT_FAILURE);
    }
    else if(pid==0)
    {
        printf("child process with insertion sort ... ",getpid());
        insertionsort(arr,n);
        printf("childern sorted array..");
        printarray(arr,n);
    }
    else
    {
        printf("parent process with bubble sort..",getpid());
        bubblesort(arr,n);
        printf("sorted array..");
        printarray(arr,n);
        wait(NULL);
        printf("child process completed....")
    }
    return 0;
}