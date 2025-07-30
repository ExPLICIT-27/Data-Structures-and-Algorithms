#include <stdio.h>
#include <stdlib.h>
void dfs(int**, int*, int, int);
int main(){
    int **graph = (int**)malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++){
        graph[i] = (int*)calloc(5, sizeof(int));
    }
    int edges = 5;
    while(edges--){
        int first, second;
        printf("\nEnter connections: ");
        scanf(" %d %d", &first, &second);
        graph[first][second]= graph[second][first] = 1;
    }
    int *visited = (int*)calloc(5, sizeof(int));
    dfs(graph, visited, 0, 5);
    return 0;
}
void dfs(int **graph, int *visited, int source, int vertices){
    printf("%d ", source);
    visited[source] = 1;
    for(int i = 0; i < vertices; i++){
        if(graph[source][i] == 1 && !visited[i]){
            visited[i] = 1;
            dfs(graph, visited, i, vertices);
        }
    }
}