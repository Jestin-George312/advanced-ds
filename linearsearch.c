#include<stdio.h>
int main(){
 int size,target;
 printf("Enter the no of elements");
 scanf("%d",&size);
 int arr[size];
 printf("Enter the elements of the array:\n");
 for(int i=0;i<size;i++){
  scanf("%d",&arr[i]);
 }
 printf("Enter he value to search for :");
 scanf("%d",&target);
 int result=-1;
 for(int i=0;i<size;i++){
  if(arr[i]==target){
   result=i;
   break;
  }
 }
 if(result=-1){
  printf("element %d found at index %d ",target,result);
 }
 else{
  printf("Element %d not found in the array",target);
 }
 return 0;
}
