/* 27/11/2020
Main Function 
using all the functions 
and algo */

#include <stdio.h>
#include <string.h>
#include "init_MST.h"
#include "jsonparser.h"
#include <stdlib.h>
#include "graph.h"
#include "prims.h"
#define infinity 9999
#define MAX 20

int G[MAX][MAX],spanning[MAX][MAX],n;

int main(){
    printf("Euclidean Minimum Spanning Tree\n\n");
    printf("Enter the number of 2d points\n");
    int n;
    scanf("%d",&n);
    if(n==0){
        return 0;
    }
    int ar[n][2];
    
    for(int i=0;i<n;i++){
        int a,b;
        printf("%d) ",i+1);
        scanf("%d %d",&a,&b);
        if(a>=10 || a<0 || b>=10 || b<0){
            printf("coordinates must be between 0-9\n");
            i--;
            continue;
        }
        ar[i][0] =a;
        ar[i][1]= b;
    }
    Graph initG = initMST(ar,n);
    free_graph(initG);

}

