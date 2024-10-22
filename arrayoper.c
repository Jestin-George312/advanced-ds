#include<stdio.h>
#include<stdlib.h>
int a[30];
int n;
int i;
void create(){
 printf("Enter the limit");
 scanf("%d",&n);
 printf("Enter the element of array ");
 for(i=0;i<n;i++){
  scanf("%d",&a[i]);
 }
}
void insert(){
int l,num;
printf("Enter the location to insert");
scanf("%d",&l);
printf("Enter the number :");
scanf("%d",&num);
if(l<0 || l>n)
 printf("Invalid location");
 else{
   for(i=n-1;i>=l;i--){
   a[i+1]=a[i];
    }
    a[i]=num;
    n++;
    printf("\n new number inserted");
 }
}
void delete(){
 if(n==0){
  printf("Array is empty");
 }
 else{
  int l;
   printf("Enter the location to delete ");
   scanf("%d",&l);
   if(l<0 || l>n)
    printf("\n Invalid location");
    else{
     for(i=l;i<n;i++){
      a[i]=a[i+1];
     }
     n--;
     printf("\n deleted element");
    }
 }
}
void show(){
 if(n==0){
  printf("Array empty");
 }
 else{
  printf("The array is :");
  for(i=0;i<n;i++)
  {
   printf("%d\t",a[i]);
  }
 }
}
void main(){
int c;
create();
while(1){
 printf("\n 1.insert\n2.delete\n3.show \n 4.exit");
 printf("Enter your choice:");
 scanf("%d",&c);
 switch(c){
  case 1:insert();break;
  case 2:delete();break;
  case 3:show();break;
  case 4:exit(0);
  default:printf("\n invalid choice");
 }
}
}
