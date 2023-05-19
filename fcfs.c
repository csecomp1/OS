#include <stdio.h>
int main() {
 int wt[20],at[20],bt[20],tat[20],n,ct[20];
 printf("Enter no of process : ");
 scanf("%d",&n);
 printf("\nEnter burst time for %d processes: ",n);
 for(int i=0;i<n;i++){
 scanf("%d",&bt[i]);
 }
 printf("\nEnter Arrival time for %d processes: ",n);
 for(int i=0;i<n;i++)
 {
 scanf("%d",&at[i]);
 }
 ct[0]=bt[0];
 for(int i=1;i<n;i++){
 ct[i]=ct[i-1]+bt[i];
 }
 wt[0]=0;
 float twt=0,ttat=0;
 for(int i=1;i<n;i++){
 wt[i]=ct[i-1]-at[i];
 twt+=wt[i];
 }
 for(int i=0;i<n;i++){
 tat[i]=wt[i]+bt[i];
 ttat+=tat[i];
 }
 printf("Process \t \t Waiting time \t \t Turn Around time \n");
 for(int i=0;i<n;i++){
 printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\tn",i,wt[i],tat[i]);
 }
 printf("Average turn around time : %.2f",ttat/n);
 printf("Average waiting time : %.2f",twt/n);
 return 0;
}