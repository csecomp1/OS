#include <stdio.h>
struct frames{
 int f;
 int ru;
};
int main() {
 int ch[20];
 int nf,sl;
 struct frames F[20];
 printf("Enter length of reference string : ");
 scanf("%d",&sl);
 printf("Enter reference string :");
 for(int i=0;i<sl;i++)
 scanf("%d",&ch[i]);
 printf("Enter no of frames : ");
 scanf("%d",&nf);
 int i=0;
 for(int i=0;i<nf;i++){
 F[i].f=-1;
 }
 float ph=0;
 int af=0;
 while(i<sl){
 int data=ch[i];
 int f=0;
 
 for(int j=0;j<nf;j++){
 if(data==F[j].f){
 ph++;
 i++;
 f=1;
 int k=F[j].ru;
 F[j].ru=nf-1;
 for(int i=0;i<nf;i++){
 if(i!=j && F[i].ru>k){
 F[i].ru=F[i].ru-1;
 }
 }
 break;
 }
 }
 if(f==1) continue;
 if(af<=nf-1){
 F[af].f=data;
 F[af].ru=af;
 af++;
 i++;
 }
 else{
 int mini=0;
 for(int i=1;i<nf;i++){
 if(F[i].ru<F[mini].ru){
 mini=i;
 }
 }
 F[mini].f=data;
 F[mini].ru=nf-1;
 for(int i=0;i<nf;i++){
 if(i!=mini){
 F[i].ru=F[i].ru-1;
 }
 }
 
 }
 
 
 
 printf("%d\t\n",data);
 for(int i=0;i<nf;i++){
 printf("|%d|",F[i].f);
 }
 printf("\n");
 
 }
 printf("\n Page hit % : %.2f",(ph/sl)*100);
 printf("\n Page miss % : %.2f",((sl-ph)/sl)*100);
 
 return 0;
}
