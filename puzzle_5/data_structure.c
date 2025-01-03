#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "read_input.h"
#include "data_structure.h"

/*
G = (V,E) V, vertices, E, edges
We use a method similar to BFS to struct all the vertix in the graph,
not knowing if all the vertix are connected, we also need to go 
down the list of edges to find the adjacency list of each vertix.   
*/

vertex **myGraph;

void lineToEdge(char *line, edge **e) {
    int i = 0;
    char *from;
    char *to;
    from = malloc(FROM_SIZE * sizeof(char));
    to = malloc(TO_SIZE * sizeof(char));
    *e = malloc(sizeof(edge));
    while (line[i] != '\0') {
        if (i <= 1) {
            from[i] = line[i];
        } else if (i > 2) {
            to[i - 3] = line[i];
        }
        i++;
    }
    from[2] = '\0';
    to[2] = '\0';
    (*e)->from = atoi(from); //Need to use (*e) or it will view it as *(e->from)
    (*e)->to = atoi(to);
    #ifdef DEBUG
        //printEdge(*e);
    #endif
    free(from);
    free(to);
}

void toListOfEdges(const char *filename, edge ***edges) {
    char **data = NULL;
    readInput(filename, &data);
    *edges = malloc(getPointerSize((void **)data) * sizeof(edge*)); // allocate memory for data
    int i = 0;
    
    while (*(data + i) != NULL) {
        lineToEdge(*(data + i), &(*edges)[i]);
        i++;
    }
    
    freeDoubleArray((void **)data, (void (*)(void *))freeString);
}

void edgesToVertices(const char *filename) {
    edge **edges = NULL;
    toListOfEdges(filename, &edges);

    myGraph = malloc(MAX_SIZE_GRAPH * sizeof(vertex *));
    int i = 0; // edge index

    // Use hashTable to check if the vertex is already in the graph, if not create a new vertex
    // finish the adjacency list later
    while (edges[i] != NULL) {
        if (myGraph[edges[i]->from] == NULL) {
            #ifdef DEBUG
                //printf("Creating vertex: %d\n", edges[i]->from);
            #endif
            myGraph[edges[i]->from] = malloc(sizeof(vertex));
            myGraph[edges[i]->from]->vertexName = edges[i]->from;
            myGraph[edges[i]->from]->adjacencyList = malloc(MAX_SIZE_GRAPH * sizeof(vertex *)); //trade space for time
        }
        if (myGraph[edges[i]->to] == NULL) {
             #ifdef DEBUG
                //printf("Creating vertex: %d\n", edges[i]->to);
            #endif
            myGraph[edges[i]->to] = malloc(sizeof(vertex));
            myGraph[edges[i]->to]->vertexName = edges[i]->to;
            myGraph[edges[i]->to]->adjacencyList = malloc(MAX_SIZE_GRAPH * sizeof(vertex *)); //trade space for time
        }
        i++;
    }

    for (int vertexName = 0; vertexName < MAX_SIZE_GRAPH; vertexName++) {
        if (myGraph[vertexName] != NULL) {
            i = 0;
            while (edges[i] != NULL) {
                int from = edges[i]->from;
                int to = edges[i]->to;
                if (from == vertexName) {
                    myGraph[vertexName]->adjacencyList[to] = myGraph[to]; //HAAAAASH is good
                }
                i++;
            }
            #ifdef DEBUG
                //printVertex(myGraph[vertexName]);
            #endif
        }

    }

    //Go through the edges again to create the adjacency list



    #ifdef DEBUG
        for (int k = 0; k < 100; k++) {
            if (myGraph[k] != NULL) {
                //printf("Vertex: %d\n", myGraph[k]->vertexName);
            }
        }
    #endif

    freeDoubleArray((void **)edges, (void (*)(void *))freeEdge);
}

void printVertex(vertex *g) {
    printf("[Vertex: %d]", g->vertexName);
    for (int i = 0; i < MAX_SIZE_GRAPH; i++) {
        if (g->adjacencyList[i] != NULL) {
            printf("->[");
            printf("%d", g->adjacencyList[i]->vertexName);
            printf("]");
        }
    }
    printf("\n");
}

void printEdge(edge *e) {
    printf("From: %d To: %d\n", e->from, e->to);
}
