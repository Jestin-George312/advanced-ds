#include<stdio.h>
int main(){
 int first[10][10],second[10][10],result[10][10];
 int rf,cf,rs,cs;
 printf("Enter rows and columns for the first matrix:");
 scanf("%d%d",&rf,&cf);
printf("Enter rows and columns for the second matrix:");
 scanf("%d%d",&rs,&cs);
 if(cf!=rs){
  printf("Matrix cant be multiplied");
  return 0;
 }
 printf("\n Enter element of first matrix:\n");
 for(int i=0;i<rf;i++){
  for(int j=0;j<cf;j++){
    scanf("%d",&first[i][j]);
  }
 }
 
 printf("\n Enter element of second matrix:\n");
 for(int i=0;i<rs;i++){
  for(int j=0;j<cs;j++){
    scanf("%d",&second[i][j]);
  }
 }
 
 for(int i=0;i<rf;i++){
  for(int j=0;j<cf;j++){
    result[i][j]=0;
    for(int k=0;k<cf;k++){
      result[i][j]+=first[i][k]*second[k][j];
     }
  }
 }
 
  printf("\n resultant matrix:\n");
 for(int i=0;i<rf;i++){
  for(int j=0;j<cf;j++){
    printf("%d",result[i][j]);
  }
  printf("\n");
 }
 return 0;
}
