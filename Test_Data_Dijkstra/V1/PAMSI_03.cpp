#include <iostream>
#include "Graph_AdjList.hpp"
#include "Graph_AdjMatrix.hpp"
#include "pair.hpp"
//#include<bits/stdc++.h>


FILE* file_open(const char *adress, const char *operation)
{
	FILE* file;
	file = fopen(adress, operation);
	if (file == 0)
	{
		cout << "File isn't open." << endl;
		return 0;
	}
	return file;
}

int main(int argc,char **argv)
{	

	//FILE* file_in = fopen(argv[1], "a+");
	//if(file_in ==NULL)
    //std::cout << "ERROR!";
  
  //GraphAdjMx<int, int> graf(file_in);
   GraphAdjMx<int, int> graf;
   
    auto v0 = graf.insertVertex(0);
    auto v1 = graf.insertVertex(1);
    auto v2 = graf.insertVertex(2);
    auto v3 = graf.insertVertex(3);
	auto v4 = graf.insertVertex(4);
	auto v5 = graf.insertVertex(5);
	auto e0=graf.insertEdge(v0,v1,10);
	auto e1=graf.insertEdge(v0,v2,20);
	auto e2=graf.insertEdge(v0,v3,30);
	auto e3=graf.insertEdge(v0,v4,40);
	auto e4=graf.insertEdge(v0,v5,50);
	auto e5=graf.insertEdge(v1,v4,1);
	auto e6=graf.insertEdge(v4,v5,1);
	auto e7=graf.insertEdge(v1,v2,1);
	auto e8=graf.insertEdge(v3,v4,1);
	auto e9=graf.insertEdge(v0,v5,1);
  graf.V_tmp=v0;
	graf.dijkstra();



}
