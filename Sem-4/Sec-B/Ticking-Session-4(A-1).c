/*
Problem solving 1

A connected acyclic graph representing N cities of a state is given by the matrix ‘cities’, where city[i][j] represents the distance between city i and city j. Find the minimum distances between the city given by the node ‘src’ to every other city in the graph. ( Print distance in the order of increasing index of the cities in the adjacency matrix).

Input Format

3	// N : number of cities in the graph
0	// src: city from which the minimum distances are calculated
0 1 10	//adjacency matrix representing the cities and their distances.
1 0 2
10 2 0 

Output Format

0
1
3 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 100

int cities[MAX_CITIES][MAX_CITIES];
int dist[MAX_CITIES];
int visited[MAX_CITIES];

int minDistance(int n) {
    int minDist = INT_MAX, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void fdist(int src, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(n);
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && cities[u][v] && dist[u] != INT_MAX && dist[u] + cities[u][v] < dist[v]) {
                dist[v] = dist[u] + cities[u][v];
            }
        }
    }
}

int main() {
    int n, src;
    scanf("%d", &n);
    scanf("%d", &src);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cities[i][j]);
        }
    }
    fdist(src, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", dist[i]);
    }
    return 0;
}
