#ifndef jsonheader
#define jsonheader

typedef struct jsonNode{
    char *id;
    char *label;
    int size;
    int x,y;
}jsonNode;

typedef struct jsonEdge{
    char *id;
    int source;
    int target;
}jsonEdge;

void parseJson(jsonNode* ar[],int n,jsonEdge* ed[],int m);
#endif
