/*You are given an edge list of edges in a graph you are required to use a traversal of your choice to detect whether there is a cycle or not. Use the boilerplate code and return true if a cycle exists and return false if there are no cycles.

Input Format

3
3
0 1
1 2
2 0

Output Format

cyclic

*/
#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;


unsigned int isCycle(int v, int parent, int visited[], unsigned int order, int adj[order][order])
{
    visited[v] = 1;
    for(int i = 0; i < order; ++i)
    {
        if(adj[v][i])
        {
            if(visited[i]==0)
            {
                if(isCycle(i, v, visited, order, adj)==1)
                    return 1;
            }
            else if(i!=parent)
                return 1;
        }
    }
    return 0;
}

unsigned int cycle_finder(const edge *edges , unsigned int n, unsigned int order)
{
    int adj[order][order];
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            adj[i][j] = 0;

    for (int i = 0; i < n; ++i)
    {
    	adj[edges[i].first][edges[i].second] = 1;
    	adj[edges[i].second][edges[i].first] = 1;
    }

    int visited[order];
    for (int i = 0; i < order; i++)
        visited[i] = 0;

    for (int i = 0; i < order; i++)
    {
        if (visited[i] == 0)
            if (isCycle(i, -1, visited, order, adj)==1)
                return 1;
    }
    return 0;
}
/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }
        
    ans= cycle_finder(edges, n, order);
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;

}