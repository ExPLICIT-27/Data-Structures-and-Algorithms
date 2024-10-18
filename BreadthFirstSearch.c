#include <stdio.h>
#include <stdlib.h>
// connections : (undirected/ doubly directed graph)
/*
0,1
0,2
1,3
1,4
2,4
*/
void bfs(int**, int, int);
int main(){
    int **graph = (int**)malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++){
        graph[i] = (int*)calloc(5, sizeof(int));
    }
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[1][4] = 1;
    graph[4][1] = 1;
    graph[2][4] = 1;
    graph[4][2] = 1;
    // let us assume root/source is 0
    bfs(graph, 0, 5);
    return 0;
}
void bfs(int **graph, int source, int vertices){
    int *visited = (int*)calloc(vertices, sizeof(int));
    visited[source] = 1;
    int queue[vertices];
    int front = 0, rear = 0;
    queue[rear++] = source;
    while(front < rear){
        int node = queue[front++];
        printf("%d ", node);
        for(int i = 0; i < vertices; i++){
            if(graph[node][i] == 1 && !visited[i]){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}