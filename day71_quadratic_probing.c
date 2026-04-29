#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int *table;
int m;

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
int search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY)
            return 0;

        if (table[index] == key)
            return 1;
    }

    return 0;
}

int main() {
    int q;

    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    table = (int*)malloc(m * sizeof(int));

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}