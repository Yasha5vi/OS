#include<stdio.h>
#define size 3

int time[size];
int frame[size];
int cap = size;

int findLRU(){
    int min = time[0];int pos = 0;
    for(int i=0;i<cap;i++){
        if(min > time[i]){
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

void display(){
    for(int i=0;i<cap;i++){
        printf("%d ",frame[i]);
    }printf("\n");
}

void lru(int pages[],int n){
    int cur_time = 1;
    int pagefault = 0;

    for(int i=0;i<cap;i++) frame[i] = -1;

    for(int i=0;i<n;i++){
        int found = 0;
        for(int j=0;j<cap;j++){
            if(frame[j] == pages[i]){
                found = 1;
                time[j] = cur_time++;
                printf("Page %d is already present\n",pages[i]);
                break;
            }
        }

        if(!found){
            int pos;
            if(i < cap){
                pos = i;
            }else{
                pos = findLRU();
            }
            frame[pos] = pages[i];
            time[pos] = cur_time++;
            pagefault++;
            display();
        }
    }
}

int main(){
    int n;scanf("%d",&n);
    int pages[n];
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    lru(pages,n);
    return 0;
}