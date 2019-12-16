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
	vector <Vertex * > neighbors;
};


//*******************    FUNCTION DECLARATION      *****************************//
void bft (vector <Vertex*>  &graph);
void dft (vector <Vertex*> & graph);
void dftInternal(vector <Vertex *> & graph, Vertex *& v);
void buildGraph(vector <Vertex*> & graph);

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
		Vertex * v = new Vertex;
		int counter = 0;
		dataFile >> curNum;
		v -> value = curNum;
		v -> visited = false;
		bool found;
		//graph.push_back(v); //add to the graph the first vertex (0)
		Vertex * vN = new Vertex;
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

	// STAGE II.V : RE EDIT THE GRAPH TO MATCH WITH POINTERS
	Vertex * vT = new Vertex;
	for(int i = 0; i < graph.size() - 1; i++)
	{
		vT = new Vertex;
		for(int k = 0; k < graph[i] -> neighbors.size(); k++)
		{
			for(int l = i; l < graph.size(); l++)
			{
				if(graph[i] -> neighbors[k] -> value == graph [l] -> value)
				{
					graph[i] -> neighbors[k] = graph[l];
				}
			}
		}
	}

	/// STAGE III: PRINT GRAPH
	for (int i = 0 ; i < graph.size(); i++)
	{
		cout << "vertex number " << i << ", value: " << graph[i] -> value << ", neighbors -> ";
		for(int j = 0; j < graph[i] -> neighbors.size(); j++ ) //traverse through neighbors in the vertex's vectors of graph
		{
			cout << graph[i] -> neighbors[j] -> value << "  ";
		}
		cout << endl;
	} //the first vertex was inserted twice (find out why?) TODO

	delete vT; //finished building graph correctly
	return;
}

int counter;
//*******************     DEPTH - FIRST TRAVERSAL      *****************************//
void dft (vector <Vertex*> & graph)
{

	counter = 0; // becasue the first one is inserted twice
	for(int i = 0; i < graph.size(); i++) //begin by setting all of the visited nodes to 0
	{
		graph[i] -> visited = false;
	}
	Vertex * v = new Vertex;
	v = graph [counter];
	while(counter < graph.size())
	{
		if(v -> visited == false) dftInternal (graph, v); // quitting here for some reason, check internal function
		v = graph[++counter];
	}	// end while
	delete v;	//delete the trav vertex we dynamically allocated
	return;
}
int numerator;

void dftInternal(vector <Vertex *> & graph, Vertex *& v) //pass by reference the vertex so we can change its "visited" value
{
	if(v -> visited == false)
	{
		cout << v -> value << "\t";
	}
	v -> visited = true;
	numerator = 0;
	while(numerator < v -> neighbors.size())
	{
 		if(v -> neighbors[numerator] -> visited == false)
 		{
 			if(v -> neighbors[numerator] -> neighbors.size() > 0)
 			{
 				dftInternal(graph, v -> neighbors[numerator]);
 				numerator++;
 			}
 			else
 			{
 				v -> neighbors[numerator] -> visited = true;
 				cout << v -> neighbors[numerator] -> value << ", ";
 				return;
 			}
 		}
	}
	return;
}


//*******************     BREADTH - FIRST TRAVERSAL      *****************************//
void bft (vector <Vertex*> & graph)
{
	Vertex * curV = new Vertex;	//curv for current vertex
	Vertex * curvTemp = new Vertex;
	queue <Vertex *> vs; // create a queue of pointers to vertices calles vs
	for(int i = 0; i < graph.size(); i++)
	{
		graph[i] -> visited = false;	//setting all vreteices to unvisited
	}


	for(int i = 0; i < graph.size(); i++)
	{
		if(graph[i] -> visited == false)
		{
			graph[i] -> visited = true;
			vs.push(graph[i]);
		}
		while(!vs.empty())
		{
			curV = vs.front();
			vs.pop();
			cout << curV -> value << ", ";
			for(int j = 0; j < curV -> neighbors.size(); j++)
			{
				curvTemp = curV -> neighbors[j];
				for(int k = 0; k < graph.size(); k++)
				{
					if(curvTemp -> value == graph[k] -> value)
					{
						if(graph[k] -> visited == false)
						{
							graph[k] -> visited = true;
							vs.push(graph[k]);
						}
					}
				}
			}
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


