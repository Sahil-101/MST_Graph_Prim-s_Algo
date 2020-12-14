/* 27/11/2020
All Graph functions implemented
and various typedefs */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"

//Vertex struct
typedef struct vertex
{
    int vertex;
    double weight;
    struct vertex *next;
} myvertex;

//Vertex pointer is Vertex
typedef myvertex *Vertex;

//Edges struct
typedef struct edges
{
    int vertex1;
    int vertex2;
    double weight;
} myedges;

//graph having size and pointer to first vertex
typedef struct graph
{
    int size;
    Vertex vertex_array;
} mygraph;

//Static function
//function to get all vertex worked up
static void initialize_vertex(Graph graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        graph->vertex_array[i].vertex = i;
        graph->vertex_array[i].weight = 0;
        graph->vertex_array[i].next = NULL;
    }
}

//function to get a pointer to newly created graph with N vertices
Graph New_Graph(int n)
{
    Graph new = malloc(sizeof(mygraph));
    assert(new!=NULL);

    Vertex temp = malloc(sizeof(myvertex) * n);
    assert(temp!=NULL);

    new->vertex_array = temp;
    new->size = n;

    initialize_vertex(new);

    return new;
}

//function to insert new vertex() with vertex number and
//weight i.e is the length of the edge connecting to
void insert_edge(Graph graph, int vertex1, int vertex2, double weight)
{
    assert(graph != NULL);

    if (graph->vertex_array[vertex1].next == NULL)
    {
        Vertex new = malloc(sizeof(myvertex));
        new->vertex = vertex2;
        new->weight = weight;
        new->next = NULL;

        graph->vertex_array[vertex1].next = new;
    }
    else
    {
        Vertex temp = graph->vertex_array[vertex1].next;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Vertex new = malloc(sizeof(myvertex));
        new->vertex = vertex2;
        new->weight = weight;
        new->next = NULL;

        temp->next = new;
    }
}

//returns size of graph i.e no. of vertex
int get_size(Graph g){
    return g->size;
}

//function to remove a vertex and it's respective edges
void delete_vertex(Graph, int vertex);

//function to remove a specif edge from the graph
void delete_edge(Graph graph, int vertex1, int vertex2);

//get weight
double get_weight(Graph graph, int vertex1, int vertex2)
{
    assert(graph != NULL);

    Vertex temp = graph->vertex_array[vertex1].next;

    while (temp->vertex != vertex2 && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        return temp->weight;
    }

    return 0;
}

//get edges
Edges get_Edges(Graph graph)
{
    assert(graph != NULL);

    myedges max_arr[graph->size * graph->size], temp_edge;
    int count = 0;
    Vertex temp;

    for (int i = 0; i < graph->size; i++)
    {
        if (graph->vertex_array[i].next != NULL)
        {
            temp = graph->vertex_array[i].next;

            while (temp->next != NULL)
            {
                temp_edge.vertex1 = i;
                temp_edge.vertex2 = temp->vertex;
                temp_edge.weight = temp->weight;

                max_arr[count] = temp_edge;
                count++;

                temp = temp->next;
            }

            temp_edge.vertex1 = i;
            temp_edge.vertex2 = temp->vertex;
            temp_edge.weight = temp->weight;

            max_arr[count] = temp_edge;
            count++;
        }
    }

    Edges edges = malloc(sizeof(myedges) * (count));

    for (int i = 0; i < count; i++)
    {
        edges[i] = max_arr[i];
    }

    return edges;
}

//get edgesCount
int get_Edges_count(Graph graph)
{
    assert(graph != NULL);

    int count = 0;
    Vertex temp;

    for (int i = 0; i < graph->size; i++)
    {
        if (graph->vertex_array[i].next != NULL)
        {
            temp = graph->vertex_array[i].next;

            // printf("temp vertex is %d and next is %d", temp->vertex, temp->next->vertex);

            while (temp->next != NULL)
            {
               // printf("temp is %d and temp next is %d\n", temp->vertex, temp->next->vertex);
                count++;
                temp = temp->next;
            }
            count++;
        }
    }
    return count;
}
//free function
void free_graph(Graph graph)
{
    assert(graph != NULL);

    Vertex temp, temp1;

    for (int i = 0; i < graph->size; i++)
    {
        if (graph->vertex_array[i].next == NULL)
        {
            continue;
        }

        temp = graph->vertex_array[i].next;
        temp1 = temp;

        while (temp->next != NULL)
        {
            temp = temp->next;
            free(temp1);
            temp1 = temp;
        }

        free(temp);
    }

    free(graph->vertex_array);
    free(graph);
}
