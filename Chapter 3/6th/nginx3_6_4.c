#include <stdio.h>
#include <stdlib.h>  //malloc,exit
#include <unistd.h>  //fork
#include <signal.h>

int main(int argc, char *const *argv)
{     
    ((fork() && fork()) || (fork() && fork()));
    for(;;)
    {        
        sleep(1); //休息1秒
        printf("休息1秒，进程id=%d!\n",getpid());
    }
    printf("再见了!\n");
    return 0;
}


