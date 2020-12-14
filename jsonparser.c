
#include <stdio.h>
#include "jsonparser.h"
#include <string.h>
#include <stdlib.h>
#include "graph.h"

void parseJson(jsonNode* ar[],int n,jsonEdge* ed[],int m){
    
    char json1[10000]="{'edges': [{'id': 'e0','source': 'n0','target': 'n1'},{'id': 'e1','source': 'n1','target': 'n2'},{'id': 'e2','source': 'n2','target': 'n0'}],'nodes': [{";
    char json[10000]="{'edges':[";
    int len = strlen(json);
    int i;
    
    int c = 0;
    if(m!=0){
        strcat(json,"{");
        for( i = strlen(json);;){
        // parses id=n2,x=6,y=3,labels=(6,3),size=3 to 
        //{"id":"n2","x":"6","y":"3","size":"3","label":"(6,3)"}

        strcat(json,"\"id\":\"e");
        i = strlen(json);
        json[i]= 48+c;

        strcat(json,"\",\"source\":\"");
        i = strlen(json);

        json[i]= 48+ed[c]->source;

        strcat(json,"\",\"target\":\"");
        i = strlen(json);
        
         json[i]= 48+ed[c]->target;
        
        strcat(json,"\"");
        i= strlen(json);
       
        //  json[i]= 48+ ar[c]->x;
        // i++;
        //  json[i]= ',';
        // i++;
        //  json[i]= 48+ ar[c]->y;

        strcat(json,"}");
        i = strlen(json);

        c++;
        if(c>=m)break;
         json[i]= ',';
        i++;
        json[i]= '{';
        i++;

        
    }
    }
    strcat(json,"],'nodes': [{");
     c = 0;

    for( i = len;;){
        // parses id=n2,x=6,y=3,labels=(6,3),size=3 to 
        //{"id":"n2","x":"6","y":"3","size":"3","label":"(6,3)"}

        strcat(json,"\"id\":\"");
        i = strlen(json);
        json[i]= 48+c;

        strcat(json,"\",\"x\":\"");
        i = strlen(json);

        json[i]= 48+ar[c]->x;

        strcat(json,"\",\"y\":\"");
        i = strlen(json);
        
         json[i]= 48+ar[c]->y;
        
        strcat(json,"\",\"size\":\"3\",\"label\":\"(");
        i= strlen(json);
       
         json[i]= 48+ ar[c]->x;
        i++;
         json[i]= ',';
        i++;
         json[i]= 48+ ar[c]->y;

        strcat(json,")\"}");
        i = strlen(json);

        c++;
        if(c>=n)break;
         json[i]= ',';
        i++;
        json[i]= '{';
        i++;

        
    }
    strcat(json,"]}");

    FILE *fileAddress;
    fileAddress = fopen("data1.json", "w");

    len = strlen(json);
    for (int i = 0; i < len; i++) {
       if(json[i]=='\'')
        json[i] = '\"';
	   fputc (json[i], fileAddress);
	}
	fclose(fileAddress);

}