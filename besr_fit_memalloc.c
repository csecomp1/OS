#include<stdio.h>
int main(){
 int nf,f[20],nb,b[20],temp,ff[20],high=1000;
 static int ba[20],frag[20];
 printf("\nEnter no of files : ");
 scanf("%d",&nf);
 printf("\nEnter size of each files: ");
 for(int i=0;i<nf;i++){
 scanf("%d",&f[i]);
 ff[i]=-1;
 }
 printf("\nEnter no of blocks: ");
 scanf("%d",&nb);
 printf("\nEnter size of each block: ");
 for(int i=0;i<nb;i++){
 scanf("%d",&b[i]);
 }
 for(int i=0;i<nf;i++){
 high=1000;
 int vis=0;
 int in;
 for(int j=0;j<nb;j++){
 if(ba[j]==0){
 temp=b[j]-f[i];
 if(temp>=0 && temp<=high){
 
 vis=1;
 in=j;
 high=temp;
 
 }
 }
 }
 if(vis==1){
 ba[in]=1;
 ff[i]=in;
 frag[in]=high;
 }
 
 }
 printf("\nFile \t\tFile Size \t\t Block Number \t\t Block size \t\t Fragment 
\t\t\n");
 for(int i=0;i<nf;i++){
 if(ff[i]!=-1){
 
printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",i,f[i],ff[i],b[ff[i]],frag[ff[i]]);
 }
 }
 return 0;
}
