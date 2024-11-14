#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* rep;
 struct node* next;
};
struct node* heads[50],*tails[50];
static int countRoot=0;

void makeSet(int x){
 struct node *newNode = (struct node *)malloc(sizeof(struct node));
 newNode->rep=newNode;
 newNode->next=NULL;
 newNode->data=x;
 heads[countRoot]=newNode;
 tails[countRoot++]=newNode;
}
struct node *find(int a){
 for(int i=0;i<countRoot;i++){
  struct node *tmp=heads[i];
  while(tmp){
   if(tmp->data==0)
      return tmp->rep;
    tmp=tmp->next;  
  }
 }
 return NULL;
}
void unionSets(int a,int b){
 struct node *rep1=find(a);
 struct node *rep2=find(b);
 
 if(rep1==NULL || rep2==NULL){
   printf("\n Element not present in the DS\n");
   return;
 }
 if(rep1!=rep2){
  struct node *temp=rep2;
  while(temp){
   temp->rep=rep1;
   temp=temp->next;
  }
  int index=-1;
  for(int i=0;i<countRoot;i++){
   if(heads[i]==rep2){
    index=i;
    break;
   }
  }
  if(index!=1){
   for(int i=0;i<countRoot;i++){
    if(heads[i]==rep1){
     tails[i]->next=rep2;
     tails[i]=tails[index];
     break;
    }
   }
   for(int i=index;i<countRoot-1;i++){
    heads[i]=heads[i+1];
    tails[i]=tails[i+1];
   }
   countRoot--;
  }
 }else{
  printf("\n  elements are already in the same set\n");
 }
}
int search(int x){
 for(int i=0;i<countRoot;i++){
  struct node *tmp=heads[i];
  while(tmp){
   if(tmp->data==x)
    return 1;
    tmp=tmp->next;
  }
 }
 return 0;
}
int main(){
 int choice,x,y;
 printf("Disjoint set operations using linked list\n");
 do{
  printf("\n---MENU---\n");
  printf("1.Make set \n");
  printf("2.Display set representatives \n");
  printf("3.Union \n");
  printf("4.Find Set \n");
  printf("5.Exit \n");
  printf("Enter your choice: ");
  scanf("%d",&choice);
  
   switch(choice){
    case 1:printf("\n Enter new element:");
           scanf("%d",&x);
           if(search(x))
            printf("\n elements already present in the disjoint set DS\n");
           else
            makeSet(x);
           break;  
     case 2:printf("\n Representation of sets:");
            for(int i=0;i<countRoot;i++)
              printf("%d",heads[i]->data);
             printf("\n");
             break;
      case 3:printf("\n	Enter first element:");
             scanf("%d",&x);
             printf("\n Enter second element:");
             scanf("%d",&y);
             unionSets(x,y);
             break;
       case 4:printf("\n Enter the element:");
              scanf("%d",&x);
              struct node *rep=find(x);
              if(rep==NULL)
                printf("\n Element not present in the DS\n");
              else
                printf("\n The representation of %d is %d\n",x,rep->data);
                  break;
       case 5:exit(0);
       default:printf("\n wronfg choice\n");
               break;                 
   }
 }while(1);
}
