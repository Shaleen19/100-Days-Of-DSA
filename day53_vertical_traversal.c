#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd; 
    struct Node *left, *right;
};

struct QNode {
    struct Node* treeNode;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->hd = 0;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QNode* temp = q->front;
    struct Node* node = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue();
    root->hd = 0;
    enqueue(q, root);

    int min = 0, max = 0;

    int map[200][200];   
    int size[200] = {0};

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);
        int hd = temp->hd + 100; 

        map[hd][size[hd]++] = temp->data;

        if (temp->hd < min) min = temp->hd;
        if (temp->hd > max) max = temp->hd;

        if (temp->left) {
            temp->left->hd = temp->hd - 1;
            enqueue(q, temp->left);
        }

        if (temp->right) {
            temp->right->hd = temp->hd + 1;
            enqueue(q, temp->right);
        }
    }

    for (int i = min; i <= max; i++) {
        int idx = i + 100;
        for (int j = 0; j < size[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}