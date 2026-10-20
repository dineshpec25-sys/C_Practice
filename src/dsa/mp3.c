#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S {
  char title[50];
  struct S *next;
} S;

S *head, *cur;

void add(char *n) {
  S *s = malloc(sizeof(S));
  S *t = head;

  strcpy(s->title, n);
  s->next = NULL;

  if (!head)
    head = cur = s;
  else {
    while (t->next)
      t = t->next;
    t->next = s;
  }
}

void del(char *n) {
  S *t = head;
  S *p = NULL;

  while (t && strcmp(t->title, n)) {
    p = t;
    t = t->next;
  }

  if (!t) {
    printf("Not found");
    return;
  }
  if (cur == t)
    cur = t->next ? t->next : head;
  if (p)
    p->next = t->next;
  else
    head = t->next;
  if (!head)
    cur = NULL;
  free(t);
}

void show() {
  for (S *t = head; t; t = t->next)
    printf("%s%s\n", t == cur ? "> " : " ", t->title);
}

void next() {
  if (!cur) {
    printf("Empty");
    return;
  }
  printf("Playing: %s\n", cur->title);
  cur = cur->next ? cur->next : head;
}

int main() {
  int c;
  char n[50];
  while (
      printf("\n1.Add\n2.Delete\n3.Show\n4.Play/Next\n5.Exit\nChoice Entre: "),
      scanf("%d", &c) == 1 && c != 5) {
    if (c == 1 || c == 2) {
      printf("Song name: ");
      scanf(" %49[^\n]", n);
      c == 1 ? add(n) : del(n);
    } else if (c == 3)
      show();
    else if (c == 4)
      next();
  }
  return 0;
}
