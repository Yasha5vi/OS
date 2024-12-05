#include<stdio.h>
#define size 10

int wt[size],st[size],ct[size],tat[size],bt[size],at[size];
int pname[size];
int n;

void takeInput(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        pname[i] = i+1;
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
    }
}

void display(){
    printf("Pid\tBT\tAT\tST\tCT\t\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",pname[i],bt[i],
        at[i],st[i],ct[i]);
    }
}

void sjfs(){
    int completed = 0;
    int visited[size];
    for(int i=0;i<n;i++) visited[i] = 0;
    int cur_time = 0;
    while(completed < n){
        int mini = 1e5,min_idx = -1;
        for(int i=0;i<n;i++){
            if(at[i] <= cur_time && visited[i] == 0){
                if(mini > bt[i]){
                    mini = bt[i];
                    min_idx = i;
                }
            }
        }
        if(min_idx == -1){
            cur_time++;
            continue;
        }
        st[min_idx] = cur_time;
        cur_time+=bt[min_idx];
        ct[min_idx] = cur_time;
        visited[min_idx] = 1;
        completed++;
    }
    int atat = 0,awt = 0;
    for(int i=0;i<n;i++){
        tat[i] = ct[i]-at[i];
        wt[i] = tat[i]-bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }
    display();
    printf("Average tat : %d\n",atat/n);
    printf("Average wt : %d\n",awt/n);
}

int main(){
    takeInput();
    sjfs();
    return 0;
}