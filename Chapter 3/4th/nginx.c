
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h> //用到errno则需要包含此头文件

int g_mysign=0;
void muNEfunc(int value)
{
    //....其他处理
    g_mysign = value;  //函数muNEfunc能够修改全局变量g_mysign的值
    //....其他处理
}


void sig_usr(int signo)
{
    /*
    muNEfunc(22);

    if(signo == SIGUSR1)
    {
        printf("收到了SIGUSR1信号!\n");
    }
    else if(signo == SIGUSR2)
    {
        printf("收到了SIGUSR2信号!\n");
    }
    else
    {
        printf("收到了未捕捉的信号%d!\n",signo);
    }*/

    int myerrno = errno;  //备份errno值
    
    muNEfunc(22);
    if(signo == SIGUSR1)
    {
        printf("收到了SIGUSR1信号!\n");
    }
    else if(signo == SIGUSR2)
    {
        printf("收到了SIGUSR2信号!\n");
    }
    else
    {
        printf("收到了未捕捉的信号%d!\n",signo);
    }

    errno = myerrno; //还原errno值
}
int main(int argc, char *const *argv)
{
    if(signal(SIGUSR1,sig_usr) == SIG_ERR)  //系统函数，参数1：是个信号，参数2：是个函数指针，代表一个针对该信号的捕捉处理函数
    {
        printf("无法捕捉SIGUSR1信号!\n");
    }
    if(signal(SIGUSR2,sig_usr) == SIG_ERR) 
    {
        printf("无法捕捉SIGUSR2信号!\n");
    }
    for(;;)
    {
        sleep(1); //休息1秒
        printf("休息1秒\n");

        muNEfunc(15);
        printf("g_mysign=%d\n",g_mysign);
    }
    return 0;
}

