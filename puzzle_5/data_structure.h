#ifndef DATA_STRUCTURE_H_
#define DATA_STRUCTURE_H_

#define FROM_SIZE 2
#define TO_SIZE 2
#define MAX_SIZE_GRAPH 100

typedef struct{
    int from;
    int to;
} edge;

typedef struct vertex {
    int vertexName;
    struct vertex **adjacencyList;
} vertex;

extern vertex **myGraph;

void printVertex(vertex *g);

void printEdge(edge *e);

void toListOfEdges(const char *filename, edge ***edges);

/*
LineToEdge:
@param line: the line to convert to an edge
@param e: the edge to store the data
lineToEdge converts a string to an edge
*/
void lineToEdge(char *line, edge **e);

void edgesToVertices(const char *filename);


#endif