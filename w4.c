// orphan process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        sleep(6);
        printf("I am child \n");
        printf("My PID : %d\n",getpid());
        printf("Parent PID : %d\n",getppid());
    }else{
        printf("I am parent\n");
        printf("My PID : %d\n",getpid());
        printf("My child PID : %d\n",pid);
    }
    printf("Terminating PID  : %d\n",getpid());
    return 0;
}
