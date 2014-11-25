//************************************
//Programer: Brett Yeager
//Course Title: CS316
//Assignment no: MP5
//Instructor: Dr. Tai-Chi Lee
//************************************
//Program Definition:
//	This programs reads in a data to construct a 
//	graph. It then creates a minimal spanning tree
//*************************************
//
// NO GLOBAL VAR USED
//*************************************
/* Developmet History
	11/24/2014
		Started project
		Read in matrix
		Found min spanning tree
		Created output
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	//getting number of vertices 
	int num_of_vert;
	ifstream infile;
	infile.open("cs316mp5.dat");
	infile >> num_of_vert;

	//Dynamicly resizing 2D array
	//	based on size of graph
	vector<vector<int>> raw_graph;
	raw_graph.resize(num_of_vert);
	for(int i=0; i < num_of_vert; i++)
		raw_graph[i].resize(num_of_vert);

	//reading in the matrix
	cout <<"Input adjacency matrix: " <<endl;
	for(int i=0; i < num_of_vert; i++)
	{
		for(int j=0; j < num_of_vert; j++)
		{
			infile >> raw_graph[i][j];
			cout << raw_graph[i][j] << " ";
		}
		cout <<endl <<endl;
	}

	//declaring output distances
	vector<int> span_dis;
	span_dis.resize(num_of_vert);

	//declaring finnal flag
	vector<bool> span_flag;
	span_flag.resize(num_of_vert);

	//setting the distance to inf. 
	//	and the flags to false
	for(int i=0; i< num_of_vert; i++)
	{
		span_dis[i] = INT_MAX;
		span_flag[i] = false;
	}
	span_dis[0] = 0;
	for(int i=0; i < num_of_vert - 1; i++)
	{
		//finding the vertex with the shortest distance
		int min = INT_MAX, min_index;
		for(int j=0; j < num_of_vert; j++)
		{
			if(span_flag[j] == false && span_dis[j] <= min)
			{
				min = span_dis[j];
				min_index = j;
			}
		}
		//the vertex is now finnal
		span_flag[min_index] = true;

		//updateing the spanning tree if the path is sorter
		for(int j=0; j < num_of_vert; j++)
		{
			if(!span_flag[j] && raw_graph[min_index][j] && span_dis[min_index] != INT_MAX
				&& span_dis[min_index] + raw_graph[min_index][j] < span_dis[j])
			{
				span_dis[j] = span_dis[min_index] + raw_graph[min_index][j];
			}
		}
	}

	//output
	cout<<"Minimum Spanning Tree: " <<endl;
	cout<<"Vertex        Distance from the first vertex" <<endl;
	for(int i=0; i < num_of_vert; i++)
	{
		cout<< i <<"         "<< span_dis[i] <<endl;
	}


	return 0;
}

