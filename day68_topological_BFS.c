#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V, E;
int adj[MAX][MAX];
int indegree[MAX];

// Function for Kahn's Algorithm
void topoSort() {
    int queue[MAX];
    int front = 0, rear = 0;

    // Step 1: Push all nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int result[MAX];

    // Step 2: BFS
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Step 3: Check for cycle
    if (count != V) {
        printf("Cycle exists! Topological sort not possible.\n");
        return;
    }

    // Step 4: Print result
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        indegree[v]++;
    }

    topoSort();

    return 0;
}