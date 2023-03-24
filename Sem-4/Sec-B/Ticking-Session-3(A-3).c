/*
Given a directed acyclic graph with V vertices and E edges, represented as an adjacency matrix A, find a print a topological sort ordering of the same.
(source removal method)

Input Format

Sample input:
4			// V
0 1 1 0		// adjacency matrix A
0 0 0 1
0 0 0 1
0 0 0 0

Output Format

Sample output:
1 2 3 4		// topologically sorted ordering

*/

#include <stdlib.h>

int n;
int index = 0;

void topologicalsort(int v,int visited[100],int graph[100][100],int res[100]) {
    visited[v]=1;
    for (int i= 1;i<n+1;i++) {
        if(graph[v][i] && !visited[i]) {
            topologicalsort(i,visited,graph,res);
        }
    }
    res[index--] = v;
}

int main() {
    scanf("%d", &n);
    int graph[100][100];
    int visited[100];
    int res[100];
    for (int i=1;i<n+1;i++) {
        for (int j=1;j<n+1;j++) {
            scanf("%d",&graph[i][j]);
        }
    }
    index=n-1;
    for (int i=1;i<n+1;i++) {
        if (!visited[i]) {
            topologicalsort(i,visited,graph,res);
        }
    }
    for (int i=0;i<n;i++) {
        printf("%d ",res[i]);
    }
    return 0;
}
