/*Represent any given graph and perform depth first search and breadth first search.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];   // adjacency list
int visited[MAX];        // visited array

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u); // undirected graph
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Recursive DFS
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

// BFS
void BFS(int start) {
    for (int i = 0; i < MAX; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    front = rear = -1; // reset queue
    printf("BFS Traversal: ");
    BFS(start);
    printf("\n");

    return 0;
}
