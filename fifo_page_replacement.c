#include <stdio.h>
int main() {
 int ch[20];
 int F[20],nf,sl;
 printf("Enter length of reference string : ");
 scanf("%d",&sl);
 printf("Enter reference string :");
 for(int i=0;i<sl;i++)
 scanf("%d",&ch[i]);
 printf("Enter no of frames : ");
 scanf("%d",&nf);
 int i=0;
 for(int i=0;i<nf;i++){
 F[i]=-1;
 }
 float ph=0;
 int af=0;
 while(i<sl){
 int data=ch[i];
 int f=0;
 
 for(int j=0;j<nf;j++){
 if(data==F[j]){
 ph++;
 i++;
 f=1;
 break;
 }
 }
 if(f==1)continue;
 if(af<=nf-1){
 F[af++]=data;
 i++;
 }
 else{
 af=0;
 F[af++]=data; 
 i++;
 }
 printf("%d\t\n",data);
 for(int i=0;i<nf;i++){
 printf("|%d|",F[i]);
 }
 printf("\n");
 
 }
 printf("\n Page hit % : %.2f",(ph/sl)*100);
 printf("\n Page miss % : %.2f",((sl-ph)/sl)*100);
 
 return 0;
}
