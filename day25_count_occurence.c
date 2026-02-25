#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value, key, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    // Create Linked List
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    scanf("%d", &key);

    // Count occurrences
    temp = head;
    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}