#include<stdio.h>
#define size 10

int wt[size],st[size],ct[size],tat[size],bt[size],at[size];
int pname[size],pri[size];
int n;

void takeInput(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        pname[i] = i+1;
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        scanf("%d",&pri[i]);
    }
}

void display(){
    printf("Pid\tBT\tAT\tPri\tST\tCT\t\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pname[i],bt[i],
        at[i],pri[i],st[i],ct[i]);
    }
}

void priority(){
    int completed = 0;
    int visited[size];
    for(int i=0;i<n;i++) visited[i] = 0;
    int cur_time = 0;
    while(completed < n){
        int mxpri = -1,max_idx = -1;
        for(int i=0;i<n;i++){
            if(at[i] <= cur_time && visited[i] == 0){
                if(mxpri < pri[i]){
                    mxpri = pri[i];
                    max_idx = i;
                }else if(mxpri == pri[i] && at[i] < at[max_idx]){
                    max_idx = i;
                }
            }
        }
        if(max_idx == -1){
            cur_time++;
            continue;
        }
        st[max_idx] = cur_time;
        cur_time+=bt[max_idx];
        ct[max_idx] = cur_time;
        visited[max_idx] = 1;
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
    priority();
    return 0;
}