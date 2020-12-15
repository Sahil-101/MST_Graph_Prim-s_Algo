/* 27/11/2020
All MST functions implemented
and various typedefs */
// #include "init_MST.h"
#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include "prims.h"
#include "jsonparser.h"
//TO DO
//bug check 
typedef struct edges
{
    int vertex1;
    int vertex2;
    double weight;
} myedges;
//bug check portion finished

double calcW(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


int map[10000];//maps vectices to original 2d points

int get2dpoint(int ind){
    return map[ind];
}

int getIndexfrom2dpoint(int x, int y,int n){

    for(int i = 0 ; i <n;i++){
        if(map[i] == x*10+y){
            return i;
        }
    }
}
Graph initMST(int ar[][2],int n){
    Graph g = New_Graph(n);

    for(int i = 0; i<n;i++){
        map[i] = ar[i][0]*10+ar[i][1];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a = i;
            int b = j;

            double w = calcW(ar[i][0],ar[i][1],ar[j][0],ar[j][1]);
            insert_edge(g,a,b,w);
        }
    }



    Edges initialEdges = get_Edges(g);
    for(int i = 0;i<get_Edges_count(g);i++){
        printf("(%d,%d) (%d,%d) %lf \n",get2dpoint(initialEdges[i].vertex1)/10,get2dpoint(initialEdges[i].vertex1)%10, get2dpoint(initialEdges[i].vertex2)/10, get2dpoint(initialEdges[i].vertex2)%10,initialEdges[i].weight);
    }
    printf("\n\nMinimum Spanning tree\n");

    Graph mst = prims(g);
    Edges finalEdges = get_Edges(mst);
    printf("%d\n",get_Edges_count(mst));

    int m = get_Edges_count(mst);
    jsonEdge* jsonEdges[m];

    for(int i = 0;i<m;i++){
        printf("(%d,%d) (%d,%d) %lf \n",get2dpoint(finalEdges[i].vertex1)/10,get2dpoint(finalEdges[i].vertex1)%10, get2dpoint(finalEdges[i].vertex2)/10, get2dpoint(finalEdges[i].vertex2)%10,finalEdges[i].weight);
        jsonEdges[i] = malloc(sizeof(jsonEdge));
        jsonEdges[i]->source =(finalEdges[i].vertex1) ;
        jsonEdges[i]->target  =(finalEdges[i].vertex2);
    }

    jsonNode* jsonNodes[n];

    for(int i = 0;  i <n;i++){
        jsonNodes[i] = malloc(sizeof(jsonNode));
        jsonNodes[i]->x = get2dpoint(i)/10;
        jsonNodes[i]->y = get2dpoint(i)%10;
        jsonNodes[i]->id = i;
    }
    parseJson(jsonNodes,n,jsonEdges,m);
    for(int i = 0;i<get_Edges_count(mst);i++){
        free(jsonEdges[i]);
    }
    for(int i = 0;  i <n;i++){
        free(jsonNodes[i]);
    }

    
    
    free(finalEdges);
    free(initialEdges);
    free_graph(mst);
    printf("\n\n");
    return g;
}

