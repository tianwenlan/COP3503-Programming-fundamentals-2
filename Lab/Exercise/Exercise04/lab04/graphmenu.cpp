#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

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
    cout << "1.Add an edge" << endl;
    cout << "2.Add a vertex" << endl;
    cout << "3.Print the graph" << endl;
    cout << "4.Print the edges of a vertex" << endl;
	cout << "5.Print the number of vertices\n" << endl;
	cout << ">";

		cin >> option;
		switch (option){
			case 0:
        	return (0);
		
	        case 2:
        	cout << "Vertex name -- ";
            cin >> vert;
            g.addVertex(vert);
			break;

			case 1:
            cout << "First vertex in edge -- ";
			cin >> vert1;
            cout << "Second vertex in edge -- ";
			cin >> vert2;
            g.addEdge(vert1, vert2);
			break;

			case 3:
            g.printGraph();
			break;

			case 4:
	    	cout << "Vertex name: ";
		    cin >> vertIn;
			g.printEdgesOfVertex(vertIn);
			cout << endl;
			break;

			case 5:
			cout << g.num_vertices() << endl;
			break;

			default:
			cout << "Sorry, you can only enter from 0 to 4:" << '\n' << endl;
			break;		
	    	}
	}

    return 0;
}

