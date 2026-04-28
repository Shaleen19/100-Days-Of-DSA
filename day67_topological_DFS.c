#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

// Push onto stack
void push(int node) {
    stack[++top] = node;
}

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    // push after visiting all neighbors
    push(node);
}

// Topological sort function
void topoSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (reverse order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topoSort();

    return 0;
}