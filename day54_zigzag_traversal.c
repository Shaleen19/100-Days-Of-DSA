#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue implementation
struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* current = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    int leftToRight = 1;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;
        int level[1000];

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue(&q);

            // Store in correct order
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->data;

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        // Print level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        // Toggle direction
        leftToRight = !leftToRight;
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}