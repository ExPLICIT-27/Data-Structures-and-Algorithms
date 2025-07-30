#include <stdio.h>
#include <stdlib.h>
void dfs(int**, int, int);
int main(){
    int **graph = (int**)malloc(6*sizeof(int*));
    for(int i = 0; i < 6; i++){
        graph[i] = (int*)calloc(6, sizeof(int));
    }
    int edges = 6;
    while(edges--){
        int first, second;
        printf("\nEnter connections: ");
        scanf(" %d %d", &first, &second);
        graph[first][second] = graph[second][first] = 1;
    }
    dfs(graph, 0, 6);
    return 0;
}
void dfs(int **graph, int source, int vertices){
    int *visited = (int*)calloc(vertices, sizeof(int));
    int stack[vertices];
    int top = -1;
    stack[++top] = source;
    visited[source] = 1;
    printf("%d ", source);
    while(top != -1){
        int node = stack[top--];
        for(int i = 0;i < vertices; i++){
            if(graph[node][i] == 1 && !visited[i]){
                visited[i] = 1;
                printf("%d ", i);
                stack[++top] = node;
                stack[++top] = i;
                break;
            }
        }
    }
}