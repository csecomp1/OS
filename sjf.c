#include <stdio.h>
struct process{
 int pid;
 int bt;
 int wt;
 int tat;
};
int main() {
 struct process P[20];
 int n;
 printf("Enter no of process : ");
 scanf("%d",&n);
 printf("\nEnter Burst time for %d processes: ",n);
 for(int i=0;i<n;i++){
 P[i].pid=i;
 scanf("%d",&P[i].bt);
 }
 
 for(int i=0;i<n-1;i++){
 int mini=i;
 for(int j=i+1;j<n;j++){
 if(P[j].bt <= P[mini].bt){
 mini=j;
 }
 }
 if(mini!=i){
 struct process temp=P[mini];
 P[mini]=P[i];
 P[i]=temp;
 }
 
 }
 
 
 P[0].wt=0;
 float twt=0,ttat=0;
 for(int i=1;i<n;i++){
 P[i].wt=P[i-1].wt+P[i-1].bt;
 twt+=P[i].wt;
 }
 for(int i=0;i<n;i++){
 P[i].tat=P[i].wt+P[i].bt;
 ttat+=P[i].tat;
 }
 printf("Process \t \t Waiting time \t \t Turn Around time \n");
 for(int i=0;i<n;i++){
 printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\n",P[i].pid,P[i].wt,P[i].tat);
 }
 printf("Average turn around time : %.2f\n",ttat/n);
 printf("Average waiting time : %.2f",twt/n);
 return 0;
}
