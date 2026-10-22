#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  char bar;
  struct stack *next;
} stack;

stack *top = NULL; // empty stack

void push(char c) {
  stack *n = malloc(sizeof(stack));
  if (n == NULL) {
    printf("Out of memory\n");
    exit(1);
  }
  n->bar = c;
  n->next = top;
  top = n;
}

char pop(void) { // caller must make sure the stack is not empty
  stack *t = top;
  char c = t->bar;
  top = t->next;
  free(t);
  return c;
}

int main() {
  char tar[100];
  printf("Enter the string : ");
  scanf("%99s", tar);

  int status = 1;
  for (int i = 0; tar[i] != '\0'; i++) {
    char c = tar[i];

    if (c == '(' || c == '[' || c == '{') {
      push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (top == NULL) { // closer with nothing to match
        status = 0;
        break;
      }
      char open = pop();
      if ((c == ')' && open != '(') || (c == ']' && open != '[') ||
          (c == '}' && open != '{')) {
        status = 0;
        break;
      }
    }
  }

  if (top != NULL)
    status = 0; // leftover openers, e.g. "(("
  while (top != NULL)
    pop(); // free leftover nodes

  if (status) {
    printf("balanced\n");
  } else {
    printf("unbalanced\n");
  }
  return 0;
}
