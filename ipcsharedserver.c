#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;

    shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
    printf("key of shared memory %d",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("process attached at %p",shared_memory);
    printf("enter some data to write into shared memory ...");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("you wrote %s",(char *)shared_memory);
}
