/* 27/11/2020
All Graph functions prototype
and various typedefs */

//graph pointer
typedef struct graph* Graph;

typedef struct edges* Edges;

//function to get a pointer to newly created graph with N vertices
Graph New_Graph(int n); //tested

//function to insert new vertex() with vertex number and 
//weight i.e is the length of the edge connecting to 
void insert_edge(Graph graph, int vertex1, int vertex2, double weight); //tested

//function to remove a vertex and it's respective edges
void delete_vertex(Graph , int vertex );

//function to remove a specif edge from the graph
void delete_edge(Graph graph, int vertex1 , int vertex2 );

//get weight
double get_weight(Graph graph, int vertex1, int vertex2);//tested

//get edges
Edges get_Edges(Graph graph);//partially tested

//get edgesCount 
int get_Edges_count(Graph graph); //tested 

//free function
void free_graph(Graph graph); //tested