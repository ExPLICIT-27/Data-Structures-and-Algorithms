#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void printMST(int*, int, int**);
void PrimMST(int**, int);
int minEdge(int*, int*, int);
int main(){
    int vertices, edges;
    printf("\nEnter the number of vertices: ");
    scanf(" %d", &vertices);
    int **graph = (int**)malloc(vertices*sizeof(int*));
    for(int i = 0; i < vertices; i++){
        graph[i] = (int*)calloc(vertices, sizeof(int));
    }
    printf("\nEnter the number of edges: ");
    scanf(" %d", &edges);
    while(edges--){
        printf("\nEnter connection and weight: ");
        int i, j, w;
        scanf(" %d %d %d", &i, &j, &w);
        graph[i][j] = graph[j][i] = w;
    }
    PrimMST(graph, vertices);
    return 0;
}
int minEdge(int *keys, int *mstSet, int vertices){
    int min = INT_MIN, min_index;
    for(int i = 0; i < vertices; i++){
        if(!mstSet[i] && keys[i] > min){
            min = keys[i], min_index = i;
        }
    }
    return min_index;
}
void PrimMST(int **graph, int vertices){
    int parents[vertices];
    int mstSet[vertices];
    int keys[vertices];

    for(int i = 0; i < vertices; i++){
        mstSet[i] = 0, keys[i] = INT_MIN;
    }
    parents[0] = -1;
    keys[0] = 0;
    for(int i = 0; i < vertices-1; i++){
        int u = minEdge(keys, mstSet, vertices);

        mstSet[u] = 1;
        for(int j = 0; j < vertices; j++){
            if(graph[u][j] && !mstSet[j] && graph[u][j] > keys[j]){
                parents[j] = u;
                keys[j] = graph[u][j];
            }
        }
    }
    printMST(parents, vertices, graph);
}
void printMST(int *parents, int vertices, int **graph){
    printf("\nEdge Weight\n");
    for(int i = 1; i < vertices; i++){
        printf("\n%d <-> %d\t%d", parents[i], i, graph[i][parents[i]]);
    }
}
