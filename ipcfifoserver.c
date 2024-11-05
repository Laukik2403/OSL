#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int res,n;
    res=open("fifo1",O_WRONLY);
    write(res,"message",7);
    printf("sender process having pid %dvsent data",getpid());
}