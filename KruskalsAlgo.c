#include <stdio.h>
#include <stdlib.h>

int comparator(const void*, const void*);
void makeSet(int*, int*, int);
int findParent(int*, int);
void unionSet(int, int, int*, int*);
void Kruskal(int n, int edges[n][3]);
int main(){
    int edgeCount;
    printf("\nEnter num of edges: ");
    scanf(" %d", &edgeCount);
    int edges[edgeCount][3];
    for(int i = 0; i < edgeCount; i++){
        printf("\nEnter the weighted edge: ");
        scanf(" %d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    Kruskal(edgeCount, edges);
    return 0;
}
void Kruskal(int n, int edges[n][3]){
    qsort(edges, n, sizeof(edges[0]), comparator);
    int parents[n], rank[n];
    makeSet(parents, rank, n);

    int mincost = 0;
    for(int i = 0; i < n; i++){
        int v1 = findParent(parents, edges[i][0]);
        int v2 = findParent(parents, edges[i][1]);
        int wt = edges[i][2];
        
        if(v1 != v2){
            unionSet(v1, v2, parents, rank);
            mincost += wt;
            printf("\n%d <-> %d : %d", edges[i][0], edges[i][1], wt);
        }
    }
    printf("\nMincost : %d", mincost);
}
void unionSet(int u, int v, int parents[], int rank[]){
    u = findParent(parents, u);
    v = findParent(parents, v);

    if(rank[u] < rank[v]){
        parents[u] = v;
    }
    else if(rank[v] < rank[u]){
        parents[v] = u;
    }
    else{
        parents[v] = u;
        rank[u]++;
    }
}
int findParent(int parents[], int component){
    if(parents[component] == component){
        return component;
    }
    return parents[component] = findParent(parents, parents[component]);
}
void makeSet(int parents[], int rank[], int n){
    for(int i = 0;i < n; i++){
        parents[i] = i, rank[i] = 0;
    }
}
int comparator(const void *p1, const void *p2){
    const int (*x)[3] = p1;
    const int (*y)[3] = p2;
    return (*x)[2]-(*y)[2];
}
