#include <stdio.h>
#include <stdlib.h>
int isCyclicUtilfunc(int**, int*, int, int, int);
int isCyclic(int **graph, int vertices){
    int *visited = (int*)calloc(vertices, sizeof(int));
    for(int i = 0; i < vertices; i++){
        if(!visited[i] && isCyclicUtilfunc(graph, visited, i, -1, vertices)){
            return 1;
        }
    }
    return 0;
}
int isCyclicUtilfunc(int **graph, int *visited, int u, int parent, int vertices){
    visited[u] = 1;
    for(int i = 0; i < vertices; i++){
        if(graph[u][i]){
            if(!visited[i]){
                if(isCyclicUtilfunc(graph, visited, i, u, vertices)){
                    return 1;
                }
            }
            else if(i != parent){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int vertices, edges;
    printf("\nEnter the vertices and edges: ");
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
    if(isCyclic(graph, vertices)){
        printf("\nYes");
    }
    else{
        printf("\nNo");
    }
    return 0;
}