#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int res,n;
    char buffer[100];
    res=open("fifo1",O_RDONLY);
    n=read(res,buffer,100);
    printf("reader process havinh pid %d",getpid());
    printf("data recieved by reciever %d is :%s",getpid(),buffer);
}