#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handing(char* message);

int main(void)
{
    int fd;
    char buf[BUF_SIZE];

    fd=open("data.txt",O_RDONLY);
    if(fd==-1)
    {
        error_handling("open() error!");
    }
    prinf("file descriptor: %d \n",fd);

    if(read(fd ,buf, sizeof(buf)==-1))
    {
        error_handling("read() error!");
    }

    close(fd);
    return 0;
}

void error_handing(char* message)
{
    
}