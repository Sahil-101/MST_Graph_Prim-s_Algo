/* 27/11/2020
All MST functions implemented
and various typedefs */
// #include "init_MST.h"
#include <stdio.h>
#include "graph.h"

//TO DO

double calcW(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
Graph initMST(int ar[][2],int n){
    Graph g = New_Graph(n);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a = ar[i][0]*10+ar[i][1];
            int b = ar[j][0]*10+ar[j][1];
            double w = calcW(ar[i][0],ar[i][1],ar[j][0],ar[j][1]);
            insert_edge(g,a,b,w);
        }
    }
    Edges e = get_Edges(g);
    for(int i = 0;i<edge;i++){
        printf("%d %d %d \n",e[i].vertex1,e[i].vertex2,e[i].weight);
    }
    return g;
}
