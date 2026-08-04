#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

typedef struct entry {
    char *key;
    int value;
    struct entry *next;
} entry_t;

entry_t *table[SIZE];   // 7 slots, all NULL at start (global = auto-zeroed)

// djb2 hash function
unsigned int hash(char *str) {
    unsigned int h = 5381;
    while (*str) {
        h = ((h << 5) + h) + (unsigned char)(*str++);
    }
    return h % SIZE;
}

// store key -> value
void insert(char *key, int value) {
    unsigned int idx = hash(key);

    entry_t *e = malloc(sizeof(entry_t));
    e->key = key;
    e->value = value;
    e->next = table[idx];   // point to old head (or NULL if bucket empty)
    table[idx] = e;         // this becomes new head
}

// look up value for key; return -1 if not found
int lookup(char *key) {
    unsigned int idx = hash(key);
    entry_t *e = table[idx];
    while (e != NULL) {
        if (strcmp(e->key, key) == 0) {
            return e->value;
        }
        e = e->next;
    }
    return -1;
}

int main(void) {
    insert("cat", 10);
    insert("dog", 20);
    insert("bird", 30);

    printf("cat  -> %d\n", lookup("cat"));
    printf("dog  -> %d\n", lookup("dog"));
    printf("bird -> %d\n", lookup("bird"));
    printf("fish -> %d\n", lookup("fish"));  // not inserted, should print -1

    return 0;
}