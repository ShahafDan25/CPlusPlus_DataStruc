
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
#include <queue>	///include QUEUE for BFT
using namespace std;
const string filePath = "/Users/shahafdan/eclipse-workspace/Assignment_10/data.txt";


struct Vertex
{
	int value;
	bool visited;
	vector <int> neighbors;
};


//*******************    FUNCTION DECLARATION      *****************************//
void bft (vector <Vertex*>  &graph);
void dft (vector <Vertex*> & graph);
void dftInternal(vector <Vertex *> & graph, Vertex *& v);
void buildGraph(vector <Vertex*> & graph);
int lookup(vector <Vertex *> graph, int value);

int lookup(vector <Vertex *> graph, int numeric)
{
	for(int i = 0; i < graph.size(); i++)
	{
		if(graph[i] -> value == numeric) return i;
	}
	return -1;
}


void buildGraph(vector <Vertex*> & graph)
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
	else //File opened successfully
	{
		cout << "SUCCESSFULLY OPENED DATA FILE" << endl << endl;
		cout << " ** HERE IS OUR GRAPH: " << endl << endl;;
		Vertex * v; //for building purposes

	////// STAGE II : BUILD THE GRAPH
		while(!dataFile.eof())
		{
			v = new Vertex; //so it will not override each vertex in the graph
			dataFile >> curNum;
			if(curNum == -1) break;
			v -> value = curNum;
			while(!dataFile.eof())
			{
				dataFile >> curNum;
				if(curNum == -1) break;
				v -> neighbors.push_back(curNum);
			}
			graph.push_back(v);
		}

		//// STAGE III: PRINT OUT THE GRAPH
		for(int k = 0; k < graph.size(); k++)
		{
			cout << "Vertex: " << k << ".   Value: " << graph[k] -> value << ".   Neightbors -> ";
			//loop to print neighbors
			for(int i = 0; i < graph[k] -> neighbors.size(); i++)
			{
				cout << graph[k] -> neighbors[i] << " ";
			}
			cout << endl;
		}
		delete v;					//get rid of what we dynamically allocated
	} // end else



	return;
}

int counter;
//*******************     DEPTH - FIRST TRAVERSAL      *****************************//
void dft (vector <Vertex*> & graph)
{


}
int numerator;

void dftInternal(vector <Vertex *> & graph, Vertex *& v) //pass by reference the vertex so we can change its "visited" value
{

	return;
}


//*******************     BREADTH - FIRST TRAVERSAL      *****************************//
void bft (vector <Vertex*> & graph)
{
	queue <Vertex *> vs; // create a queue of pointers to vertices calles vs
	graph[0] -> visited = true;
	cout << graph[0] -> value << ", ";
	cout << graph[0] -> value << ", ";
	vs.push(graph[0]); ///push the first element
	Vertex * temp = new Vertex;
	Vertex * curv = new Vertex;
	temp = vs.front();
	while(!vs.empty())
	{
		for(int i = 0; i < temp -> neighbors.size(); i++)
		{
			curv = graph[lookup(graph, temp -> neighbors[i])];
			if(curv -> visited == false)
			{
				curv -> visited = true;
				cout << curv -> value << ", ";
				vs.push(curv);
			}
		}
		vs.pop();
	}
	for(int i = 0; i < graph.size(); i++)
	{
		if(graph[i] -> visited == false)
		{
			graph[i] -> visited = true;
			cout << graph[i] -> value << ", ";
		}
	}
	return;
}// end functions




//***************************     MAIN      **************************************//
int main() {
	cout << " ----------- HELLO WORLD! WELCOME TO THE LAST ASSIGNMENT IN CS20! ------------" << endl << endl;
	vector <Vertex * >  graph; //NOT VERTEXES!!
	buildGraph(graph);
	cout << endl << "Displaying Breadth - First Traversal:" << endl;
	bft(graph);
	cout << endl << "Displaying Depth - First Traversal:" << endl;
	dft(graph);
	cout << endl <<  "Have a great day! TAF" << endl;
	return 0;
}
