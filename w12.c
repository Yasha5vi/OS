#include<stdio.h>
#define size 3

int frame[size];
int front = 0;
int rear = -1;
int cur_size = 0;
int cap = size;

int isFull(){
    return cur_size == cap;
}

void enque(int el){
    rear = (rear+1)%size;
    frame[rear] = el;
    cur_size++;
}

void deque(){
    front = (front+1)%size;
    cur_size--;
}

int isPresent(int x){
    for(int i=0;i<cur_size;i++){
        int idx = (front+i)%size;
        if(frame[idx] == x){
            return 1;
        }
    }
    return 0;
}

void display(){
    for(int i = 0;i<cur_size;i++){
        printf("%d ",frame[(front+i)%size]);
    }
    printf("\n");
}

void fifo(int pages[],int n){
    int pagefault = 0;
    for(int i=0;i<n;i++){
        if(!isPresent(pages[i])){
            if(isFull()){
                deque();
            }
            enque(pages[i]);
            pagefault++;
            display();
        }else{
            printf("Page already present\n");
        }
    }
}

int main(){
    int n;scanf("%d",&n);
    int pages[n];
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    fifo(pages,n);
    return 0;
}
