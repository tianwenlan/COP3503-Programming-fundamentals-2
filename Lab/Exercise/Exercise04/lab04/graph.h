#ifndef GRAPH_H
#define GRAPH_H
#include <string>

using namespace std;



// A graph structure implemented with arrays
class Graph{
	private:
	static const int MAX_VERTICES = 100;
    static const int MAX_EDGES = 4950;

    string vertices[MAX_VERTICES];
    int edges[MAX_EDGES][2];
    int numVertices;
    int numEdges;

	public:
	void printGraph();
	void printEdgesOfVertex(string);
	void addVertex(string);
	void addEdge(string, string);
	int findVertexIndex (string);
	int num_vertices();

};	

#endif
