/*
Implement prim's algorithm to generate minimum cost spanning tree
(graph representation : use adjacency matrix)
vertices to be stored in a priority queue implemented using heap (each node contains vertex id and distance of this vertex from the nearest vertex in the spanning tree and nearest vertex id)

Input Format

0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Output Format

Edge Weight
0 - 1 2
1 - 2 3
0 - 3 6
1 - 4 5 

*/

#include <stdio.h>
#include <limits.h>
#define V 5

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
    
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    //printf("Edge Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int graph[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    primMST(graph);

    return 0;
}
