
typedef struct Node{
    char *id;
    char *label;
    int size;
    int x,y;
}Node;
void parseJson(Node* ar[],int n);