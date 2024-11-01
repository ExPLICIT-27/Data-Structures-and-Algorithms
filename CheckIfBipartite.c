#include <stdio.h>
#include <stdlib.h>

int checkBipartite(int**, int);
int main(){
    int vertices, edges;
    printf("\nEnter the number of vertices and edges: ");
    scanf(" %d %d", &vertices, &edges);
    int **graph = (int**)malloc(vertices * sizeof(int*));
    for(int i = 0; i < vertices; i++){
        graph[i] = (int*)calloc(vertices, sizeof(int));
    }
    int u, v;
    while(edges--){
        printf("\nEnter the edge: ");
        scanf(" %d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    if(checkBipartite(graph, vertices)){
        printf("\nYes");
    }
    else{
        printf("\nNo");
    }
    return 0;
}
int checkBipartite(int **graph, int vertices){
    int *color = (int*)malloc(vertices * sizeof(int));
    for(int i = 0; i < vertices; i++){
        color[i] = -1;
    }
    for(int i = 0; i < vertices; i++){
        if(color[i] == -1){
            color[i] = 0;
            int queue[vertices];
            int front = 0, rear = 0;
            queue[rear++] = i;
            while(front < rear){
                int node = queue[front++];
                for(int u = 0; u < vertices; u++){
                    if(graph[node][u]){
                        if(color[u] == -1){
                            color[u] = 1 - color[node];
                            queue[rear++] = u;
                        }
                        else if(color[u] == color[node]){
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}