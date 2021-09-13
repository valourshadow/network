#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handing(char* message);

int main(void)
{
    int fd;
    char buf[]="Let's go!\n ";

    fd=open("data.txt",O_CREAT|O_WRONLY|O_TRUNC);
    if(fd==-1)
    {
        error_handing("open() error");
    }

    close(fd);
    return 0;
}

void error_handing(char *message)
{
    
}