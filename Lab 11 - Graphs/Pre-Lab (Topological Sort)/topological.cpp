/**
 * \author Nathaniel Goldammer (wsn8pk)
 * \date April 26, 2022
 * \file topological.cpp
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Creates an adjacency list-based graph using a file of vertices.
 * @param The file from which the graph is constructed.
 * @return The map implementation of the graph
**/
map<string, vector<string> > makegraph(string file)
{
	//Let filestream = the file's corresponding ifstream
	ifstream filestream(file);

	//If filestream has opened the file
	if(filestream.is_open() == true)
	{
		//Let graph = the map-implementation of the graph to be returned
		map<string, vector<string> > graph;

		//Let vertex1 and vertex2 = arbitrary vertices read from the file
		string vertex1, vertex2;

		//While filestream is reading vertex1 and vertex2 from the file
		while(filestream >> vertex1 >> vertex2)
		{
			//If filestream has not reached the end of the file
			if(vertex1 != "0" && vertex2 != "0")
			{
				//If graph doesn't contain the key vertex1
				if(graph.count(vertex1) == 0)
				{
					//Insert vertex1 into the graph
					graph[vertex1];

					//Insert vertex2 into vertex1's adjacency list
					graph[vertex1].push_back(vertex2);
				}
				else
				{
					//Insert vertex2 into vertex1's adjacency list
					graph[vertex1].push_back(vertex2);
				}

				//If graph doesn't contain the key vertex2
				if(graph.count(vertex2) == 0)
				{
					//Insert vertex2 into the graph
					graph[vertex2];
				}
			}
		}

		//Return the graph
		return graph;
	}
	else
	{
		//Print an error message and terminate the program
		cout << "Error: Unable to open the " << file << "." << endl;
		exit(1);
	}
}

/**
 * @brief Computes the indegree of each vertex in a graph.
 * @param The graph for which the indegrees are computed.
 * @return A vertex-indegree map.
**/
map<string, int> indegree(map<string, vector<string> > graph)
{
	//Let vertexindegree = the vertex-indegree map to be returned
	map<string, int> vertexindegree;

	//For each vertex-adjacency list pair in the graph
	for(auto const& [vertex, adjacencylist] : graph)
	{
		//Insert the vertex into vertexindegree
		vertexindegree[vertex];
	}

	//For each vertex-indegree pair in vertexindegree
	for(auto const& [vertex1, indegree] : vertexindegree)
	{
		//For each vertex-adjacency list pair in the graph
		for(auto const& [vertex2, adjacencylist] : graph)
		{
			//If vertex1 != vertex2
			if(vertex1 != vertex2)
			{
				//For each element of vertex2's adjacency list
				for(int i = 0; i < adjacencylist.size(); i++)
				{
					//If vertex1 = adjacencylist[i]
					if(vertex1 == adjacencylist[i])
					{
						//Increment the indegree of vertex1
						vertexindegree[vertex1]++;
					}
				}
			}
		}
	}

	//Return the vertex-indegree map 
	return vertexindegree;
}

/**
 * @brief Displays a possible topological sort of the vertices in a graph.
 * @param The graph for which the topological sort will be displayed.
**/
void topologicalsort(map<string, vector<string> > graph)
{
	//Base Case: If the graph is empty
	if(graph.empty() == true)
	{
		//Break the current line of output
		cout << endl;

		//Return control back to the driver
		return;
	}
	//Recursive Case: If the graph is not empty
	else
	{
		//Let indegreemap = the graph's corresponding vertex-indegree map
		map<string, int> indegreemap = indegree(graph);

		//For each vertex-indegree pair in the indegreemap
		for(auto const& [vertex, indegree] : indegreemap)
		{
			//If the vertex has an indegree of 0
			if(indegreemap[vertex] == 0)
			{
				//Print the vertex
				cout << vertex << " ";

				//Remove the vertex and it's adjacency list from the graph
				graph.erase(vertex);

				//Break the current iteration of the loop
				break;
			}
		}

		//Invoke topologicalsort() with the new graph
		topologicalsort(graph);
	}
}

//Driver 
int main(int argc, char* argv[])
{
	//If the user has passed 1 command-line parameter
	if(argc == 2)
	{
		//Let graph = the graph constructed from the vertices in argv[1]
		map<string, vector<string> > graph = makegraph(argv[1]);

		topologicalsort(graph);
		
		//Let vimap = the vertex-indegree map constructed from the graph
		//map<string, int> vimap = indegree(graph);

		//End of main
		exit(0);
	}
	else
	{
		//Print an error message and terminate the execution of main()
		cout << "Invalid Input: Must supply the input file name as the one and only parameter." << endl;
		exit(1);
	}
}