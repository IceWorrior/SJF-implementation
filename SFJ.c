#include<stdio.h>
#include<stdlib.h>

struct Process{

  int arrival_t;
  int Pid;
  int burst_t;

};

typedef struct Process process;

process* getProcesses(int n){
  process *processes= malloc(sizeof(process)* n);

  for(int i=0;i<n;i++){
    
    int at, bt, pid;
    printf("Enter the PId, Arrival Time, Burst Time\n");
    scanf("%d %d %d",&pid,&at,&bt);

    processes[i].arrival_t = at;
    processes[i].Pid = pid;
    processes[i].burst_t = bt;
  }

  return processes;
}

void displayprocesses(process *p, int n){
  
  printf("Pid   Arrival   BurstTime\n");

  for(int i=0;i<n;i++){
      printf("%d     %d         %d\n",p[i].Pid,p[i].arrival_t,p[i].burst_t);
  }
}
void displayExecutinprocesses(process *p,int n){

  printf("\nExecution Queue:\n");
  for(int i=0;i<n;i++){
    printf("P%d->",p[i].Pid);
  }
  printf("Termination\n");

}

void SJF(){
  
  printf("Enter the number of processes: ");
  int n;
  scanf("%d",&n);
  process *processes = getProcesses(n);
  printf("got the process!\n");
  printf("\ncurrent Processes\n");
  displayprocesses(processes,n);

  for(int i=0;i<n;i++){
    if(processes[i].arrival_t == 0){
      process temp = processes[i];
      processes[i] = processes[0];
      processes[0] = temp;
      break;
    }
  }

  
  for(int i=1;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(processes[i].burst_t > processes[j].burst_t){
        process temp;
        temp = processes[i];
        processes[i] =processes[j];
        processes[j] = temp;
      }
    }
  }
  displayExecutinprocesses(processes,n); 
}


