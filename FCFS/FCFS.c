
//First Come First Serve (FCFS) CPU time scheduling
#include<stdio.h>

int main(){
    int i=0,t=0,n=0,p[10],at[10],bt[10],ct[10],tat[10],wt[10],rt[10],avg_tat=0,ttat=0,tp=0;
    printf("how many process: ");
    scanf("%d",&t);
//assiging all the value of process no,arival time,burst time.
    for(i=1;i<=t;i++){
        printf("Process no: ");
        scanf("%d",&p[i]);
        printf("Arival time: ");
        scanf("%d",&at[i]);
        printf("Burst time: ");
        scanf("%d",&bt[i]);
        printf("\n");
    }
//calculating completion time
     for (i=1;i<=t;i++){
            if(at[i]<=at[t]){
                ct[i]=at[i]+bt[i];
            }
    }

//calculating turn around time { TAT = CT - AT}
     for (i=1;i<=t;i++){
            tat[i]=ct[i]-at[i];


    }
//calculating waiting time {WT = TAT-BT}
     for (i=1;i<=t;i++){
            wt[i]=tat[i]-bt[i];
    }
//calculating response time {response time =  the first time process set cpu - AT}
     for (i=1;i<=t;i++){
         rt[i]= ct[i-1]-at[i];
    }
//calculating Average Total around time {AVG TAT = Total sum TAT / Total process}
     for (i=1;i<=t;i++){
    ttat += tat[i]; // ttat means total time around time
    }
//Display the Average total around time
    avg_tat = ttat/t;
    printf("avarage total around time: %d\n\n",avg_tat);


//Display the final CPU process schedule
    printf("process no     Arival Time     Burst Time     Completion Time    Turn around time     Waiting Time     Response Time \n");
     for (i=1;i<=t;i++){
    printf("   %d               %d             %d              %d                %d                   %d                 %d \n" ,i,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }



return 0;
}
