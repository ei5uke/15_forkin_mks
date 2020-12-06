#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
 
#define SPACE "---------\n"

int main()
{
    srand(time(NULL));

    int c, c1, status, c_pid, time;
    time = 0;

    printf("Initial message before forking, my pid: %d\n", getpid());
    printf(SPACE);

    c = fork();
    if (c)
    {
        c1 = fork();
        if (c1 == 0)
        {
            printf("I'm c1! Here's my pid: %d\n", getpid());
            int ran = rand() % 9 + 2;
            sleep(ran);
            printf("c1 done\n");
            return ran;
        }
        //printf("I'm the parent! My child is: %d\n", c);
        wait(&status);
        time += WEXITSTATUS(status);
        //waitpid(c, &status, 0);
        printf(SPACE);
        printf("Child exited, I'm the parent; PID: %d\t Time: %d\n", c, time);
        printf("Parent process done\n");
        return 0;
    }
    else
    {
        printf("I'm c! Here's my pid: %d\n", getpid());
        int ran = rand() % 9 + 2;
        sleep(ran);
        printf("c done\n");
        return ran;
    }
    
    return 0;
}