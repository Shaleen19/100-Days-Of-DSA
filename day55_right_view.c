#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure
struct Queue {
    int front, rear, size;
    struct Node* *array;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->array = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1) return;
    if (q->front == -1) q->front = 0;
    q->array[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->array[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);

    enqueue(q, root);
    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Print right view
void rightView(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = q->rear - q->front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue(q);

            // Last node of level
            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left)
                enqueue(q, curr->left);
            if (curr->right)
                enqueue(q, curr->right);
        }
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}