#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 5 // Maximum number of vertices
#define INF INT_MAX

void addEdge(int graph[MAX_V][MAX_V], int u, int v, int w) {
    graph[u][v] = w; // Add directed edge with weight
}

// Function to find the shortest path using Dijkstra's algorithm
int shortestPath(int graph[MAX_V][MAX_V], int src, int dest, int V) {
    int dist[MAX_V];
    int visited[MAX_V] = {0}; // Track visited vertices
    for (int i = 0; i < V; i++) {
        dist[i] = INF; // Initialize distances as infinite
    }
    dist[src] = 0; // Distance to source is 0

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i; // Find the vertex with the minimum distance
            }
        }

        if (u == -1) break; // If no vertex is found, break

        visited[u] = 1; // Mark this vertex as visited

        // Update the distance for the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v]) { // There is an edge
                if (dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    
    return dist[dest]; // Return the shortest distance to the destination
}

// Function to find the length of the shortest cycle in the graph
int findShortestCycle(int graph[MAX_V][MAX_V], int V) {
    int minCycle = INF;

    // Iterate over all edges in the graph
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0) { // Check if there is an edge
                int weight = graph[u][v];

                // Remove the edge temporarily
                graph[u][v] = 0;

                // Check the shortest path from v to u
                int distance = shortestPath(graph, v, u, V);

                // If a path is found, update the minimum cycle length
                if (distance != INF) {
                    minCycle = (minCycle < distance + weight) ? minCycle : distance + weight;
                }

                // Add the edge back
                graph[u][v] = weight;
            }
        }
    }

    return (minCycle == INF) ? -1 : minCycle; // Return -1 if no cycle found
}

int main() {
    int V, E;
    int graph[MAX_V][MAX_V] = {0}; // Initialize the adjacency matrix

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        printf("Enter edge (source, destination, weight): ");
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w); // Add edge to the graph
    }

    int shortestCycle = findShortestCycle(graph, V);
    if (shortestCycle >= 0) {
        printf("Length of the shortest cycle: %d\n", shortestCycle);
    } else {
        printf("No cycle found in the graph.\n");
    }

    return 0;
}
