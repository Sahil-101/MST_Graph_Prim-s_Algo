
#include <stdio.h>
#include "jsonparser.h"
#include <string.h>
#include <stdlib.h>


void parseJson(Node* ar[],int n){
    
    char json[1000]="{'edges': [{'id': 'e0','source': 'n0','target': 'n1'},{'id': 'e1','source': 'n1','target': 'n2'},{'id': 'e2','source': 'n2','target': 'n0'}],'nodes': [{";
    
   int len = strlen(json);
   printf("%d\n",len);
    int i;
    int c = 0;
    for( i = len;;){
        // json[i] = "{";
        // i++;
        json[i]= '\"';
        i++;
         json[i]= 'i';
        i++;
         json[i]= 'd';
        i++;
         json[i]= '\"';
        i++;
         json[i]= ':';
        i++;
         json[i]= '\"';
        i++;
         json[i]= 'n'+ c/10;
        i++;
         json[i]= 48+c;
        i++;
         json[i]= '\"';
        i++;
        

        json[i]= ',';
        i++;


        json[i]= '\"';
        i++;
         json[i]= 'x';
        i++;
         json[i]= '\"';
        i++;
         json[i]= ':';
        i++;
         json[i]= '\"';
        i++;

         json[i]= 48+ar[c]->x;
        i++;
         json[i]= '\"';
        i++;


        
        json[i]= ',';
        i++;

        
        json[i]= '\"';
        i++;
         json[i]= 'y';
        i++;
         json[i]= '\"';
        i++;
         json[i]= ':';
        i++;
         json[i]= '\"';
        i++;
         json[i]= 48+ar[c]->x;
        i++;
         json[i]= '\"';
        i++;


         json[i]= '}';
        i++;
        c++;
        if(c>=n)break;
         json[i]= ',';
        i++;
        json[i]= '{';
        i++;


        
    }

    json[i]= ']';
    i++;
    json[i]= '}';
    i++;
    FILE *fileAddress;
   fileAddress = fopen("data1.json", "w");

    len = strlen(json);
    printf("%d\n",len);
   for (int i = 0; i < len; i++) {
       if(json[i]=='\'')
        json[i] = '\"';
	   fputc (json[i], fileAddress);
	}
	fclose(fileAddress);

}