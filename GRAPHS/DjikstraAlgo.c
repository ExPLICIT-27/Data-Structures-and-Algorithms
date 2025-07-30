#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minDis(int*, int*, int);
void Print(int*, int, int);
void Djikstras(int**, int, int);
int main(){
    int vertices;
    printf("\nEnter num vertices: ");
    scanf(" %d", &vertices);

    int **graph = (int**)malloc(vertices*sizeof(int*));
    for(int i = 0; i < vertices; i++){
        graph[i] = (int*)malloc(vertices*sizeof(int));
        printf("\nEnter row %d connections: ", i);
        for(int j = 0; j < vertices; j++){
            scanf(" %d", &graph[i][j]);
        }
    }
    Djikstras(graph, vertices, 0);
    return 0;
}
void Print(int *distances, int vertices, int src){
    for(int i = 0; i < vertices; i++){
        if(i == src){
            continue;
        }
        printf("\n%d -> %d\t%d", src, i, distances[i]);
    }
}
int minDis(int *distances, int *sptSet, int vertices){
    int mindis = INT_MAX,minidx;
    for(int i = 0; i < vertices; i++){
        if(!sptSet[i] && distances[i] < mindis){
            mindis = distances[i], minidx = i;
        }
    }
    return minidx;
}
void Djikstras(int **graph, int vertices, int src){
    int distances[vertices], sptSet[vertices];
    for(int i = 0; i < vertices; i++){
        distances[i] = INT_MAX, sptSet[i] = 0;
    }

    distances[src] = 0;
    for(int i = 0; i < vertices - 1; i++){
        int u = minDis(distances, sptSet, vertices);
        sptSet[u] = 1;

        for(int v = 0; v < vertices; v++){
            if(graph[u][v] && !sptSet[v] && distances[u] != INT_MAX && (distances[u] + graph[u][v] < distances[v]) ){
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
    Print(distances, vertices, src);
}