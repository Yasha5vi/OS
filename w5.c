// pipe system call inter process communication

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

int main(){
    int fd[2],nbr,nbw;
    char s[100],t[100];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if(pid == 0){
        printf("Enter the string : ");
        scanf("%s",s);
        nbw = write(fd[1],s,strlen(s));
        printf("Child wrote %d bytes\n",nbw);
    }else{
        nbr = read(fd[0],t,sizeof(t));
        printf("Parent read %d bytes\n",nbr);
        printf("String : %s",t);
    }
    return 0;
}