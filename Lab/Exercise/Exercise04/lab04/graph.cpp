#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

	  // Print the entire graph according to the format in the
  	  // lab description
  	  void Graph::printGraph(){
        cout << "Vertices: " ;
     	for (int i=0; i<numVertices; i++){
			cout << "[" << vertices[i] << "]" ;
		}
            cout << endl;

		cout << "Edges: ";
      	for (int i=0; i<numEdges; i++){
          	cout << "(" << vertices[edges[i][0]] << "," << vertices[edges[i][1]] << ")";
		}
			cout << endl;
			cout << "\nprintGraph\n" << endl;

   	 }
        

   	 // Print the edges of a given vertex
   	void Graph::printEdgesOfVertex(string vert){
			int p = findVertexIndex(vert);
			if (p==-1){
				cout << "Error: [" << vert << "] does not exist" << endl; return;
			}
			    cout << "[" << vert << "]:";
			for (int i=0; i<numEdges; i++)
				if (edges[i][0] == p || edges[i][1] == p)
				cout << "(" << vertices[edges[i][0]] << "," << vertices[edges[i][1]] << ")" << flush;
				cout << "\nprintEdgesOfVertex" << endl;

   	 }

      	

   	 // Add a vertex to the graph
   	 void  Graph::addVertex(string vert){
		vertices[numVertices] = vert;
		numVertices++;
		cout << "addVertex\n" << endl;

	}

   	 // Add an edge to the graph
   	 void  Graph::addEdge(string vert1, string vert2){
		int p = findVertexIndex(vert1);
		int q = findVertexIndex(vert2);
		if (p==-1) {
			cout << "Error: [" << vert1 << "] does not exist" << endl; return;
		}
		if (q==-1) {
			cout << "Error: [" << vert2 << "] does not exist" << endl; return;
		}
		if (p==q) {
			cout << "Error: Edge must connect two different vertices" << endl; return;
		}
         
		 edges[numEdges][0] = p; edges[numEdges][1] = q;
     	 numEdges++;
		 cout << "addEdge\n" << endl;


    	}

	 //construct a function to find the index of the vertices
	 int Graph::findVertexIndex (string vert){
		 int a = 0;
		 while (a<numVertices && vertices[a]!=vert) a++;
		 if (a == numVertices) a=-1;
		 return a;
	 }

	//returns the number of vertices
	int Graph::num_vertices(){
		return numVertices;
	}

