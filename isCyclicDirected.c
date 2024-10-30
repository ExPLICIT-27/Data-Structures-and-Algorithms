#include <stdio.h>
#include <stdlib.h>

int isCyclic(int**, int);
int isCyclicUtil(int**, int*, int*, int, int);
int main(){
    int vertices, edges;
    printf("\nEnter number of vertices and edges: ");
    scanf(" %d %d", &vertices, &edges);
    int **graph = (int**)malloc(vertices*sizeof(int*));
    for(int i = 0; i < vertices; i++){
        graph[i] = (int*)calloc(vertices, sizeof(int));
    }
    int con1, con2;
    while(edges--){
        printf("\nEnter the connection: ");
        scanf(" %d %d", &con1, &con2);
        graph[con1][con2] = 1;
    }
    if(isCyclic(graph, vertices)){
        printf("\nYES");
    }
    else{
        printf("\nNO");
    }
    return 0;
}
int isCyclicUtil(int **graph, int *visited, int *recstack, int vertices, int u){
    if(!visited[u]){
        visited[u] = 1;
        recstack[u] = 1;
        for(int i = 0; i < vertices; i++){
            if(graph[u][i] && !visited[i] && isCyclicUtil(graph, visited, recstack, vertices, i)){
                return 1;
            }
            else if(graph[u][i] && recstack[i]){
                return 1;
            }
        }
    }
    recstack[u] = 0;
    return 0;
}
int isCyclic(int **graph, int vertices){
    int *visited = (int*)calloc(vertices, sizeof(int));
    int *recstack = (int*)calloc(vertices, sizeof(int));
    for(int i = 0; i < vertices; i++){
        if(!visited[i] && isCyclicUtil(graph, visited, recstack, vertices, i)){
            return 1;
        }
    }
    return 0;
}