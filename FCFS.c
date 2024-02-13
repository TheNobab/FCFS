#include<stdio.h>

int main(){
    int i=0,t=0,p[10],at[10],bt[10],ct[10],tat[10],wt[10],rt[10],avg_tat=0,ttat=0,tp=0,temp=0;
    printf("how many process: ");
    scanf("%d",&t);
    //assigning all the values of process no, arrival time, burst time
    for(i=1;i<=t;i++){
        printf("Process no: ");
        scanf("%d",&p[i]);
        printf("Arrival time: ");
        scanf("%d",&at[i]);
        printf("Burst time: ");
        scanf("%d",&bt[i]);
        printf("\n");
    }

    // Sorting the processes based on arrival time in ascending order
    for (i = 1; i <= t; i++) {
        for (int j = i + 1; j <= t; j++) {
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    //calculating completion time
    for (i = 1; i <= t; i++){
        if (at[i] <= ct[i-1]){
            ct[i] = ct[i-1] + bt[i];
        } else {
            ct[i] = at[i] + bt[i];
        }
    }

    //calculating turn around time { TAT = CT - AT}
    for (i = 1; i <= t; i++){
        tat[i] = ct[i] - at[i];
    }

    //calculating waiting time {WT = TAT-BT}
    for (i = 1; i <= t; i++){
        wt[i] = tat[i] - bt[i];
    }

    //calculating response time {response time = the first time process sets CPU - AT}
    rt[1] = 0; // Initializing the first process's response time to 0
    for (i = 2; i <= t; i++){
        rt[i] = ct[i-1] - at[i];
    }

    //calculating Average Total turn around time {AVG TAT = Total sum TAT / Total processes}
    for (i = 1; i <= t; i++){
        ttat += tat[i]; // ttat means total turn around time
    }
    //Display the Average total turn around time
    avg_tat = ttat / t;
    printf("average total turn around time: %d\n\n", avg_tat);

    //Display the final CPU process schedule
    printf("Process no\tArrival Time\tBurst Time\tCompletion Time\tTurn around time\tWaiting Time\tResponse Time\n");
    for (i = 1; i <= t; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
    return 0;
}
