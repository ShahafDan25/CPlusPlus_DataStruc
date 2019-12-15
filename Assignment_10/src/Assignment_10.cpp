//============================================================================
// Name        : Assignment_10.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ostream>
#include <vector>
using namespace std;
const string filePath = "/Users/shahafdan/eclipse-workspace/Assignment_10/data.txt";


struct Vertex
{
	int value;
	bool visited;
	vector <Vertex * > neighbors;
};


//*******************    FUNCTION DECLARATION      *****************************//
void bft (vector <Vertex*> graph);
void dft (vector <Vertex*> graph);
void dftInternal(vector <Vertex *> graph, Vertex *& v);
void buildGraph(vector <Vertex*> graph);





void buildGraph(vector <Vertex*> graph)
{

	/// STAGE I : OPEN AND READ FILE
	ifstream dataFile;
	dataFile.open(filePath);
	int curNum;
	if(dataFile.fail())
	{
		cout << "FAILED OPENING FILE, TERMINATING PROGRAM" << endl;
		throw "file did not open. ";
	}
	else
	{
		cout << "SUCCESSFULLY OPENED DATA FILE" << endl << endl;
		cout << " ** HERE IS OUR GRAPH: " << endl << endl;;
		Vertex * v = new Vertex;
		int counter = 0;
		dataFile >> curNum;
		v -> value = curNum;
		v -> visited = false;
	////// STAGE II : BUILD THE GRAPH
		while(!dataFile.eof())
		{
			dataFile >> curNum;
			if(curNum == -1) //list of neighbors over
			{
				graph.push_back(v);
				v = new Vertex;
				counter++;
				dataFile >> curNum;
				v -> value = curNum;
				v -> visited = false;
			}
			else
			{
				Vertex * vNeigh = new Vertex;
				vNeigh -> visited = false;
				vNeigh -> value = curNum;
				v -> neighbors.push_back(vNeigh);
			}

		}
		delete v;					//get rid of what we dynamically allocated
	} // end else

	//// OPEN III: PRINT OUT THE GRAPH
	for (int i = 0 ; i < graph.size(); i++)
	{
		cout << "vertex number " << i << ", value: " << graph[i] -> value << ", neighbors -> ";
		for(int j = 0; j < graph[i] -> neighbors.size(); j++ ) //traverse through neighbors in the vertex's vectors of graph
		{
			cout << graph[i] -> neighbors[j] -> value << "  ";
		}
		cout << endl;
	}
	return;
}


//*******************     DEPTH - FIRST TRAVERSAL      *****************************//
void dft (vector <Vertex*> graph)
{
	for(int i = 0; i < graph.size(); i++)
	{
		graph[i] -> visited = false;
	}
	Vertex * v = new Vertex;

	int counter = 0;
	v = graph[counter];	///set v to the first vertex
	while(counter < graph.size())
	{
		if(!v -> visited) dftInternal (graph, v);
		counter++;
		v = graph[counter];
	}	// end while
	delete v;	//delete the trav vertex we dynamically allocated
	return;
}

void dftInternal(vector <Vertex *> graph, Vertex *& v) //pass by reference the vertex so we can change its "visited" value
{
	/// QUESTIONS: what does visiting a vertex mean? is it supposed to do something?
	v -> visited = true;
	Vertex * vNeighTemp = new Vertex;
	int counter = 0;
	vNeighTemp = v -> neighbors[counter];
	while(v -> neighbors[counter])
	{
		if(vNeighTemp -> visited == false) dftInternal(graph, vNeighTemp);
	}
	vNeighTemp = v -> neighbors[++counter];

	return;
}


//*******************     BREADTH - FIRST TRAVERSAL      *****************************//
void bft (vector <Vertex*> graph)
{

	return;
}




//***************************     MAIN      **************************************//
int main() {
	cout << " ----------- HELLO WORLD! WELCOME TO THE LAST ASSIGNMENT IN CS20! ------------" << endl << endl;
	vector <Vertex * >  graph; //NOT VERTEXES!!
	buildGraph(graph);
	cout << endl <<  "Have a great day! TAF" << endl;
	return 0;
}
