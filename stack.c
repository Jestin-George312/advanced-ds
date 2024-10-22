#include <stdio.h>
#include <stdlib.h>
#define MAX 50 // Maximum size of the stack
int stack[MAX], top = -1; // Initialize stack and top
void push() 
{
 int elem;
 if (top == MAX - 1) 
 {
  printf("Stack Overflow! Cannot push more elements.\n");
  return;
 }
 printf("Enter the element to be pushed: ");
 scanf("%d", &elem);
 top++; // Move top to next position
 stack[top] = elem; // Insert element at the new top
 printf("%d pushed to the stack.\n", elem);
}
void pop() 
{
 if (top == -1) {
 printf("Stack Underflow! No elements to pop.\n");
 return;
}
printf("Popped element: %d\n", stack[top]);
top--; // Decrease the top pointer
}
void display() 
{
 int i;
 if (top == -1) {
 printf("Stack is empty.\n");
 return;
}
printf("Stack elements are:\n");
for (i = top; i >= 0; i--)
{
 printf("%d\n", stack[i]);
}
}
int main()
{
 int ch;
 while (1) {
 printf("\n--- Stack Menu ---\n");
 printf("1. Push\n");
 printf("2. Pop\n");
 printf("3. Display\n");
 printf("4. Exit\n");

 printf("Enter your choice: ");
 scanf("%d", &ch);
 switch (ch) 
 {
 case 1:
  push();
  break;
 case 2:
  pop();
  break;
 case 3:
   display();
   break;
 case 4:
   exit(0);
 default:
  printf("Invalid choice, please try again.\n");
 }
}
return 0;
}
