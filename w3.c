// demonstration of wait system call
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    int status;
    pid = fork();
    if(pid == 0){
        printf("I am child\n");
    }else{
        wait(&status);
        printf("I am parent\n");
        printf("Child PID : %d",pid);
    }
    return 0;
}