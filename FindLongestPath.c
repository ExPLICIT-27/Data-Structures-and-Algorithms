// given a matrix of characters, find the longest consecutive set of
// characters starting from a given character
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int dfs(char**, int **, int directions[8][2], int, int, int, int, char);
int main(){
    int n, m;
    printf("\nEnter the number of rows and columns: ");
    scanf(" %d %d", &n, &m);
    char **graph = (char**)malloc(n*sizeof(char*));
    int **visited = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        visited[i] = (int*)calloc(m, sizeof(int));
        graph[i] = (char*)malloc(m*sizeof(char));
        printf("\nEnter row %d of characters: ", i+1);
        for(int j = 0; j < m; j++){
            scanf(" %c", &graph[i][j]);
        }
    }
    int longestPath = 0;
    char start;
    printf("\nEnter the starting character: ");
    scanf(" %c", &start);
    int directions[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == start){
                int currlen = dfs(graph, visited, directions, n, m, i, j, start-1);
                longestPath = (currlen > longestPath)? currlen : longestPath;
            }
        }
    }
    printf("\nLongest Path: %d", longestPath);
    return 0;
}
int dfs(char **graph, int **visited, int directions[8][2], int n, int m, int x, int y, char prevChar){
    if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || graph[x][y] != prevChar + 1){
        return 0;
    }
    visited[x][y] = 1;
    int maxlen = 0;
    for(int i = 0; i < 8; i++){
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        int currlen = dfs(graph, visited, directions, n, m, newX, newY, graph[x][y]);
        maxlen = (currlen > maxlen)? currlen : maxlen;
    }
    visited[x][y] = 0;
    return 1 + maxlen;
}