
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(int argc, char *const *argv)
{    
    pid_t pid;
    printf("非常高兴，和大家一起学习本书\n");

    for(;;)
    {
        sleep(1);
        printf("进程休息1秒!\n");
    }
    printf("程序退出!再见!\n");
    return 0;
}


