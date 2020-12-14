// Prims_Algorithm
// This algorithm creates spanning tree with minimum weight from a given weighted graph.
// 1.Begin
// 2.Create edge list of given graph, with their weights.
// 3.Draw all nodes to create skeleton for spanning tree.
// 4.Select an edge with lowest weight and add it to skeleton and delete edge from edge list.
// 5.Add other edges. While adding an edge take care that the one end of the edge should always be in the skeleton tree and its cost should be minimum.
// 6.Repeat step 5 until n-1 edges are added.
// 7.Return.

#include "graph.h"
#include "prims.h"
Graph prims(Graph g)
{
    int n = get_size(g);
    Graph mst = New_Graph(n);
    printf("edge len of the new graph %d",get_Edges_count(mst));
    double cost[MAX][MAX];
    int u,v,min_distance,distance[MAX],from[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;
    
    //create cost[][] matrix,spanning[][]
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=get_weight(g,i,j);
                spanning[i][j]=0;
        }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%lf ",cost[i][j]);
        }
        printf("\n");
    }
    //initialise visited[],distance[] and from[]
    distance[0]=0;
    visited[0]=1;
    
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
    
    min_cost=0;        //cost of spanning tree
    no_of_edges=n-1;        //no. of edges to be added
    
    while(no_of_edges>0)
    {
        //find the vertex at minimum distance from the tree
        min_distance=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }
        printf(" %d ",v);
        u=from[v];
        
        //insert the edge in spanning tree
        insert_edge(mst,u,v,distance[v]);
        insert_edge(mst,v,u,distance[v]);
        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;
        
        //updated the distance[] array
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][v]<distance[i])
            {
                distance[i]=cost[i][v];
                from[i]=v;
            }
        
        min_cost=min_cost+cost[u][v];
    }
        printf("edge len of the new graph %d",get_Edges_count(mst));

    // return(min_cost);
    return mst;
}

