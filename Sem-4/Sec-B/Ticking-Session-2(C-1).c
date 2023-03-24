/*
Problem solving 1

You are given an undirected graph with N vertices where each vertex is numbered from 0 to N-1. You are also given an adjacency matrix E, where E[i][j] indicates the existence of an edge between vertexi and vertexj (1 if it exists, 0 otherwise). You have to return the total number of vertices that are unreachable in this graph.
Note: Start at vertex 0 always

Input Format

3			// Number of vertices, N
1 1 0		// Adjacency Matrix
1 0 0
0 0 0 

Output Format

1 
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int adj_mat[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int x;

void dfs(int s)
{
    visited[s] = 1;
    for (int i = 1; i <= x; i++)
    {
        if (adj_mat[s][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() 
{
    scanf("%d", &x);
    for (int i=0;i<x;i++) 
    {
        for (int j=0;j<x;j++) 
        {
            scanf("%d",&adj_mat[i][j]);
        }
        visited[i]=0;
    }
    dfs(0);
    int count = 0;
    for (int i=0;i<x;i++)
    {
        if (!visited[i]) 
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
