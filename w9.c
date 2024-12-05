#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct node{
    char name[3];
    int burst;
    int arrival;
    int start;
    int end;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void insert(){
    node* p = (node*)malloc(sizeof(node));

    // printf("Enter the process name : ");
    scanf("%s",p->name);
    // printf("Enter the burst time : ");
    scanf("%d",&p->burst);
    // printf("Enter the arrival time : ");
    scanf("%d",&p->arrival);
    p->start = p->end = 0;
    p->next = NULL;
    
    if(!front){
        front = p;
        rear = p;
    }else{
        rear->next = p;
        rear = p;
    }
    printf("Node inserted\n");

}

void display(){
    node* temp = front;
    printf("Process\tBT\tAT\tST\tCT\n");
    while(temp){
        printf("%s\t%d\t%d\t%d\t%d\n",temp->name,
        temp->burst,temp->arrival
        ,temp->start,temp->end);
        temp = temp->next;
    }
}

void sortProcess(int n){

    node* temp = (node*)malloc(sizeof(node));
    int count = n;
    while(count > 1){
        node* a = front;
        node* b = front->next;
        for(int i=0;i<(count-1);i++){
            if(a->arrival > b->arrival){
                temp->name[0] = a->name[0];
                temp->name[1] = a->name[1];
                a->name[0] = b->name[0];
                a->name[1] = b->name[1];
                b->name[0] = temp->name[0];
                b->name[1] = temp->name[1];
                temp->arrival = a->arrival;
                a->arrival = b->arrival;
                b->arrival = temp->arrival;
                temp->burst = a->burst;
                a->burst = b->burst;
                b->burst = temp->burst;
            }
            a = a->next;
            b = b->next;
        }
        count--;
    }
}

void calculate(int n){
    node* temp = front;

    int cur = 0;
    int tat = 0,wt = 0;
    while(temp){
        if(temp->arrival <= cur){
            temp->start = cur;
            temp->end = cur+temp->burst;
            cur+=temp->burst;
        }else{
            cur = temp->arrival;
            temp->start = cur;
            temp->end = cur+temp->burst;
            cur+=temp->burst;
        }

        tat+=temp->end-temp->arrival;
        wt+=(temp->end-temp->arrival-temp->burst);
        
        temp = temp->next;
    }
    printf("Average TAT : %d\n",tat/n);
    printf("Average WT : %d\n",wt/n);
}

int main(){
    int n;
    // printf("Enter the number of process : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insert();
    }
    sortProcess(n);
    calculate(n);
    display();
    return 0;
}