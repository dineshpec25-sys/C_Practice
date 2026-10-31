#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct song 
{
    char name[50];
    struct song *next;
} song;

//global
song *head = NULL, *cur = NULL;

song *create(char n[])
{
    song *s = malloc(sizeof(song));
    strcpy(s->name, n);
    s->next = NULL;
    return s;
}

void add(char n[])
{
    song *s = create(n);
    song *t = head;

    if(head == NULL) 
    {
        head=cur=s;
        return;
    }
    while(t != NULL) t = t->next;
    t->next = s;
}

void search(char n[])
{
    song *t=head;
    int pos = 1;
    while(t != NULL)
    {
        if(strcmp(t->name,n) == 0)
        {
            printf("Found at %d\n", pos);
            return;
        }
        t=t->next;
        pos++;
    }
}
void del(char n[])
{
    song *t=head, *perv=NULL;
    while(t != NULL && strcpy(t->name,n) != 0)
    {
        perv=t;
        t=t->next;
    }
    if(t==NULL) {printf("Not found"); return;}
    if(perv == NULL)head=t->next;
    else perv->next=t->next;
    if(cur == t) cur=head;
    free(t);
}

void display()
{
    song *t = head;
    int pos = 1;
    while(t != NULL)
    {
        printf("%d. %s %s", pos++, t->name,cur==t ? "-> Playing" : " ");
        t=t->next;
    }
}

void play_next()
{
    if(cur == NULL)
    {
        printf("EMPTY");
        return;
    }
    cur = (cur->next != NULL) ? cur->next : head;
}

int main()
{
    int ch;
    char n[30];
    do {
        printf("\n1.Add\n2.Delete\n3.Search\n4.Display\n5.Next\n6.Exit\n");
        scanf("%d", &ch);
        if (ch >= 1 && ch <= 4) { printf("Name: "); scanf("%s", n); }
        switch (ch) {
            case 1: add(n); break;
            case 2: del(n); break;
            case 3: search(n); break;
            case 4: display(); break;
            case 5: play_next(); break;
        }
    } while (ch != 6);
    return 0;
}
