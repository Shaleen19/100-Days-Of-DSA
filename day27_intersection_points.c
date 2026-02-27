#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* longer = (len1 > len2) ? head1 : head2;
    struct Node* shorter = (len1 > len2) ? head2 : head1;

    for (int i = 0; i < diff; i++)
        longer = longer->next;

    while (longer != NULL && shorter != NULL) {
        if (longer == shorter)
            return longer;

        longer = longer->next;
        shorter = shorter->next;
    }

    return NULL;
}

struct Node* findNode(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }

    scanf("%d", &m);

    int arr[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < m; i++) {
        struct Node* intersectNode = findNode(head1, arr[i]);

        if (intersectNode != NULL) {
            // Attach remaining part from first list
            if (head2 == NULL)
                head2 = intersectNode;
            else {
                struct Node* temp = head2;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = intersectNode;
            }
            break;
        } else {
            append(&head2, arr[i]);
        }
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}