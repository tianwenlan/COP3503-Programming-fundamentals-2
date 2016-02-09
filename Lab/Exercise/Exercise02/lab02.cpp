#include <iostream>
#include <string>

using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = 4950;

// A graph structure implemented with arrays
struct Graph{
    string vertices[MAX_VERTICES];
    int edges[MAX_EDGES][2];
    int numVertices;
    int numEdges;

    // Constructor, called when a graph is created
    Graph(){
   	 	numVertices = 0;
   	 	numEdges = 0;
    }


	  // Print the entire graph according to the format in the
  	  // lab description
  	  void printGraph(){
        cout << "Vertices: " ;
     	for (int i=0; i<numVertices; i++){
			cout << "[" << vertices[i] << "]";
		}
            cout << endl;

		cout << "Edges: ";
      	for (int i=0; i<numEdges; i++){
          	cout << "(" << vertices[edges[i][0]] << "," << vertices[edges[i][1]] << ")";
		}
			cout << '\n'<< endl;

   	 }
        

   	 // Print the edges of a given vertex
    	void printEdgesOfVertex(string vert){
			int p = findVertexIndex(vert);
			if (p==-1){
				cout << "Error: [" << vert << "] does not exist" << endl; return;
			}
			    cout << "[" << vert << "]:";
			for (int i=0; i<numEdges; i++)
				if (edges[i][0] == p || edges[i][1] == p)
				cout << "(" << vertices[edges[i][0]] << "," << vertices[edges[i][1]] << ")";
				cout << endl;
   	 }

      	

   	 // Add a vertex to the graph
   	 void addVertex(string vert){
		vertices[numVertices] = vert;
		numVertices++;   	 
	}

   	 // Add an edge to the graph
   	 void addEdge(string vert1, string vert2){
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

    	}
	 //construct a function to find the index of the vertices
	 int findVertexIndex (string vert){
		 int a = 0;
		 while (a<numVertices && vertices[a]!=vert) a++;
		 if (a == numVertices) a=-1;
		 return a;
	 }


};

// Should provide the functionality described in the lab
int main(int argc, char ** argv){
	Graph g;

    int option;
    string vert, vert1, vert2, vertIn;
    string addVertex;
    string addEdge;
    string printGraph;
    string printEdgesOfVertex;

    while (1) {

    cout << "0.Exit" << endl;
    cout << "1.Add a vertex" << endl;
    cout << "2.Add an edge" << endl;
    cout << "3.Print the graph" << endl;
    cout << "4.Print the edges of a vertex\n" << endl;
	cout << ">";

		cin >> option;
		switch (option){
			case 0:
        	return (0);
		
	        case 1:
        	cout << "Vertex name -- ";
            cin >> vert;
            g.addVertex(vert);
			break;


			case 2:
            cout << "First vertex in edge -- ";
			cin >> vert1;
            cout << "Second vertex in edge -- ";
			cin >> vert2;
            g.addEdge(vert1, vert2);
			cout << endl;
			break;

			case 3:
            g.printGraph();
			break;

			case 4:
	    	cout << "Vertex name -- ";
		    cin >> vertIn;
	        g.printEdgesOfVertex(vertIn);
			cout << endl;
			
			break;

			default:
			cout << "Sorry, you can only enter from 0 to 4:" << '\n' << endl;
	    	}
	}

    return 0;
}

