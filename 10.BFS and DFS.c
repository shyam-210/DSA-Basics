#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a graph
struct Graph {
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
};

// Function to initialize a graph with the given number of nodes
void initializeGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numNodes && destination >= 0 && destination < graph->numNodes) {
        graph->adjacencyMatrix[source][destination] = 1;
        graph->adjacencyMatrix[destination][source] = 1; // Assuming an undirected graph
    } else {
        printf("Invalid edge: (%d, %d)\n", source, destination);
    }
}

// Function to perform Breadth-First Search (BFS) traversal
void bfsTraversal(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    printf("BFS Traversal starting from node %d: ", startNode);

    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        for (int i = 0; i < graph->numNodes; i++) {
            if (graph->adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

// Recursive function for Depth-First Search (DFS) traversal
void dfsRecursive(struct Graph* graph, int currentNode, int visited[]) {
    visited[currentNode] = 1;
    printf("%d ", currentNode);

    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
            dfsRecursive(graph, i, visited);
        }
    }
}

// Function to perform Depth-First Search (DFS) traversal
void dfsTraversal(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};

    printf("DFS Traversal starting from node %d: ", startNode);
    dfsRecursive(graph, startNode, visited);

    printf("\n");
}

int main() {
    struct Graph graph;
    int numNodes, choice, sourceNode;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    initializeGraph(&graph, numNodes);

    do {
        printf("\nGraph Traversal Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Breadth-First Search (BFS)\n");
        printf("3. Depth-First Search (DFS)\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination nodes for the edge: ");
                int source, destination;
                scanf("%d %d", &source, &destination);
                addEdge(&graph, source, destination);
                break;
            case 2:
                printf("Enter the starting node for BFS: ");
                scanf("%d", &sourceNode);
                bfsTraversal(&graph, sourceNode);
                break;
            case 3:
                printf("Enter the starting node for DFS: ");
                scanf("%d", &sourceNode);
                dfsTraversal(&graph, sourceNode);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
