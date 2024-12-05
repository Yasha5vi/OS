#include<stdio.h>
#include<unistd.h>

int main(){
    fork();
    printf("hello\n");
    fork();
    printf("I am \n");
    fork();
    printf("Yashasvi Chandra\n");
    return 0;
}