#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node;

node *top = NULL;
void push(int valu) {
  node *s;
  s = malloc(sizeof(node));

  s->val = valu;
  s->next = top;
  top = s;
  return;
}

int pop() {
  if (top == NULL) {
    printf("stack underflow\n");
    return -1;
  }
  int valu = top->val;
  top = top->next;
  return valu;
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
