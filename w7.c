// Message queue for writer process
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>

struct mb{
    long mtype;
    char mtext[100];
}svarname;

int main(){
    key_t key;
    int c,msgid;
    key = ftok("file",'A');
    msgid = msgget(key,0666|IPC_CREAT);
    svarname.mtype = 1;
    printf("Enter the string : ");
    gets(svarname.mtext);
    c = msgsnd(msgid,&svarname,strlen(svarname.mtext),0);
    return 0;
}