
// Message queue for reader process
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
    int msgid,c;
    key = ftok("file",'A');
    msgid = msgget(key,0666|IPC_CREAT);
    c = msgrcv(msgid,&svarname,sizeof(svarname.mtext),0,1);
    printf("Data recieved is : %s\n",svarname.mtext);
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}
