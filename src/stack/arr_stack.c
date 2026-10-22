#include <stdio.h>

int my_stack[100];
int top = -1;
void push(int val) {
  if (top == 100) {
    printf("stack overflow\n");
    return;
  }
  top++;
  my_stack[top] = val;
  return;
}

int pop() {
  if (top == -1) {
    printf("stack underflow\n");
    return -1;
  }
  int val = my_stack[top];
  top--;
  return val;
}
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    push(arr[i]);
  }
  for (int i = 0; i < 5; i++) {
    printf("%d\n", pop());
  }
}
