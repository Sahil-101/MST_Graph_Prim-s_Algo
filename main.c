
#include <stdio.h>
#include <stdlib.h>
#include "prims.h"
 
#define infinity 9999
#define MAX 20
 
int G[MAX][MAX],spanning[MAX][MAX],n;
 
int prims();

int main()
{
    int i,j,total_cost;
    printf("Enter no. of vertices :");
    scanf("%d",&n);
    
    printf("\nEnter the Adjacency Matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
     total_cost = prims();

    printf("\nSpanning Tree Matrix:\n");
    
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d\t",spanning[i][j]);
    }
    
    printf("\n\nTotal cost of Spanning Tree=%d",total_cost);
    return 0;
}
