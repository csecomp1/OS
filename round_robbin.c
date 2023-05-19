#include <stdio.h>
struct process{
 int pid;
 int bt;
 int wt;
 int tat;
 int rt;
};
int main() {
 struct process P[20];
 int n,ts;
 printf("Enter no of process : ");
 scanf("%d",&n);
 printf("\nEnter Burst time for %d processes: ",n);
 for(int i=0;i<n;i++){
 P[i].pid=i;
 scanf("%d",&P[i].bt);
 }
 printf("Enter time slice : ");
 scanf("%d",&ts);
 
 float twt=0,ttat=0;
 for(int i=0;i<n;i++){
 P[i].rt=P[i].bt;
 }
 int ep=0;
 while(1){
 int cnt=0;
 
 for(int i=0;i<n;i++){
 if(P[i].rt==0)
 {cnt++;continue;}
 else if(P[i].rt>ts){
 P[i].rt=P[i].rt-ts;
 ep+=ts;
 }
 else if(P[i].rt>=0){
 
 ep+=P[i].rt;
 P[i].rt=0;
 }
 P[i].tat=ep;
 
 }
 if(cnt==n)break;
 }
 for(int i=0;i<n;i++){
 P[i].wt=P[i].tat-P[i].bt;
 twt+=P[i].wt;
 ttat+=P[i].tat;
 }
