//测试：是否允许，一个pipe有一个写端，多个读端呢？是否允许有一个读端多个写端呢？
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;
    int fd[2], i, n;
    char buf[1024];

    int ret = pipe(fd);
    if (ret == -1)
    {
        perror("pipe error");
        exit(1);
    }

    for (i = 0; i < 2; i++)
    {
        if ((pid = fork()) == 0)
            break;
        else if (pid == -1)
        {
            perror("pipe error");
            exit(1);
        }
    }

    if (i == 0)
    {
        close(fd[0]);
        write(fd[1], "1.hello\n", strlen("1.hello\n"));
    }
    else if (i == 1)
    {
        close(fd[0]);
        write(fd[1], "2.world\n", strlen("2.world\n"));
    }
    else
    {
        close(fd[1]);               //父进程关闭写端,留读端读取数据
                                    //		sleep(1);
        n = read(fd[0], buf, 1024); //从管道中读数据
        write(STDOUT_FILENO, buf, n);

        for (i = 0; i < 2; i++) //两个儿子wait两次
            wait(NULL);
    }

    return 0;
}

---------------------作者：oguro
                        来源：CSDN
                            原文：https : //blog.csdn.net/oguro/article/details/53841949
                                          版权声明：本文为博主原创文章，转载请附上博文链接！