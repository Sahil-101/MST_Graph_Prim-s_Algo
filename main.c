/* 27/11/2020
Main Function 
using all the functions 
and algo */

#include <stdio.h>
#include <string.h>
#include "init_MST.h"
#include "jsonparser.h"
#include <stdlib.h>


int main(){
    printf("Euclidean Minimum Spanning Tree\n\n");
    printf("Enter the number of 2d points\n");
    int n;
    // scanf("%d",&n);
    int ar[n][2];

    // initMST accepts the pointer of a 2d array and then generates a graph  
    // ar -> pointer to the 2d array
    // graph* pt  = initMST(ar);
    // pt -> pointer to the initial graph
    // graph finalMST  = prims(pt);
    // finalMST returns the pointer to a minimum spanning tree
    // print the minimum spanning tree

    // upload the graph to a database and show it on the website
    Node *nodes[3];
    for(int i =0 ;i<3;i++){
        Node* node = malloc(sizeof(Node));
        char id[2] ;
        id[0]= 'n',id[1] = '0'+i;
        node->id="n1";
        node->x = i+4;
        node->y = i+1;
        nodes[i] = node;
    }
   
    parseJson(nodes,3);
 for(int i  = 0 ;i <3;i++){
        free(nodes[i]);
    }
}