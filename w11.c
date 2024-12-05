#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct node{
    char name[3];
    int burst;
    int priority;
    int waiting;
    int tat;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void insert(){
    node* p = (node*)malloc(sizeof(node));
    scanf("%s",p->name);
    scanf("%d",&p->burst);
    scanf("%d",&p->priority);

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
    printf("Process\tBT\tPri\tWT\tTAT\n");
    while(temp){
        printf("%s\t%d\t%d\t%d\t%d\n",temp->name,
        temp->burst,temp->priority,temp->waiting,temp->tat);
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
            if(a->priority > b->priority){
                temp->name[0] = a->name[0];
                temp->name[1] = a->name[1];
                a->name[0] = b->name[0];
                a->name[1] = b->name[1];
                b->name[0] = temp->name[0];
                b->name[1] = temp->name[1];
                temp->burst = a->burst;
                a->burst = b->burst;
                b->burst = temp->burst;
                temp->priority = a->priority;
                a->priority = b->priority;
                b->priority = temp->priority;
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
    float tat = 0,wt = 0;
    while(temp){
        temp->waiting = cur;
        cur+=temp->burst;
        temp->tat = cur;
        
        tat+=temp->tat;
        wt+=temp->waiting;
        temp = temp->next;
    }
    display();
    printf("Average TAT : %f\n",tat/n);
    printf("Average WT : %f\n",wt/n);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insert();
    }
    sortProcess(n);
    calculate(n);
    return 0;
}