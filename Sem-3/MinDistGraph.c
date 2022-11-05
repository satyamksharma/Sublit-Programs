/*
Find the minimum distance between source and destination vertex in a directed graph.


A Graph is a non-linear data structure consisting of vertices and edges. More formally a Graph is composed of a set of vertices( V ) and a set of edges( E ). The edges form the connection between the vertices.The graph is denoted by G(E, V). 

A graph can be represented as an adjacency matrix, or an adjacency list. For this problem we will be going ahead with an adjacency matrix.
The input of the graph will be given in the form of edges between two vertices. The helper function create_graph has been provided, which will create an adjacency matrix representation for you.

You are required to complete the find_dist function, which finds the distance between source and destination vertices in the graph, using BFS(Breadth First Search) traversal technique.
Int find_dist(Graph * adj_mat , int source, int dest)
Takes in the adjacency matrix, source and destination vertex,
and prints the distance from source to destination vertex.

You are required to use the code provided to you as the boiler plate.
The skeleton for the graph is provided to you along with the function to create the adjacency matrix. 
Note that the given graph is a directed graph.
Some helper functions to implement insertion and deletion in queue is also provided.

Input Format

The first line consists of an integer, denoting the number of vertices in the graph.
The next few lines takes in two integers, vertex1 and vertex2 separated by space, which has an edge between them. You can enter unlimited number of edges until you enter a, -1 -1.
The next two lines takes in an integer value of source vertex and destination vertex.

Output Format

Print the distance from source to destination vertex.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph {
int n; /* Number of vertices in graph */
int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;
int c;
void create_graph(Graph * adj_mat)
    {
        
        int i, j;
        for (int i = 0; i < adj_mat->n; ++i)
        {
            for (int j = 0; j < adj_mat->n; ++j)
            {
                adj_mat->adj[i][j] = 0;
            }
        }
        while (1)
        {
            scanf("%d %d\n", &i, &j);
            if (i < 0 || j < 0 || i >= adj_mat->n || j >= adj_mat->n)
            {
                break;
            }

            adj_mat->adj[i][j] = 1;
        }
    }

void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}

int delete (int *queue, int *pqr)
{
    int res = queue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        queue[i] = queue[i + 1];
    }
    --(*pqr);
    return res;
}

int allZero(Graph* adj_mat, int s){
    int c = 0;
    for(int i =0; i<adj_mat->n; i++){
        if(adj_mat->adj[s][i]==1){
            c++;
            break;
        }
    }
    if(c==0)
        return 1;
    else
        return 0;
    
}

int find_dist(Graph * adj_mat, int source, int dest)
{
    if(source==dest)
        return 0;
    if(adj_mat->adj[source][dest]==1){
        return 1;
    }
    for(int i =0; i<adj_mat->n; i++){
        if(adj_mat->adj[source][i]==1){ 
            c++;
            return 1+find_dist(adj_mat, i, dest);
        }    
        if(allZero(adj_mat, source)==1)
            return -1-c;
    }
}


int main()
{
    Graph adj_mat;

    int source, dest;

    //number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    //source vertex
    scanf("%d\n", &source);

    //destination vertex
    scanf("%d", &dest);
    
    int result = find_dist(&adj_mat, source, dest);
    printf("%d",result);
    return 0;
}