#ifndef GRAPH_ADJLIST_HPP_
#define GRAPH_ADJLIST_HPP_
#include <iostream>
#include "list/dlist.hpp"
#include "pair.hpp"
#include "priority_queue/priority_queue.hpp"


template <typename T, typename W>
class GraphAdjList{
  public:
	struct Edge;
	struct Vertex;

	dlinklist<Edge*> edge_list;
	dlinklist<Vertex*> vertex_list;
	int vertices_amount;
	Vertex* V_tmp;

	//Access method
	Pair<Vertex*, Vertex*>endVertices(Edge *E)
	{
		Pair<Vertex*, Vertex*> pair_tmp;
		pair_tmp.first = E->start;
		pair_tmp.second = E->end;

		return pair_tmp;
	}

	Vertex* opposite(Vertex* V, Edge* E)
	{
		if(E->start == V)
			return E->end;
		return E->start;
	}

	bool areAdjacent(Vertex* V1, Vertex* V2)
	{
		if((V1->inclist.begin() != nullptr) && (V2->inclist.begin() != nullptr))
		{
			for(auto i = V1->inclist.begin(); i != V1->inclist.end(); i++)
				for(auto j = V2->inclist.begin(); j != V2->inclist.end(); j++)
					if(*i==*j)
						return true;
		}
		return false;
	}

	void replace(Vertex* V, W X) { V->data = X;}

	void replace(Edge* E, W X) { E->weight = X;}

	//Update methods
	Vertex* insertVertex(W O)
	{
		Vertex* vertex_tmp = new Vertex;
		vertex_tmp->data = O;
		vertex_tmp->idx = vertices_amount++;
		vertex_list.push_front(vertex_tmp);
		return vertex_tmp;
		
	}

	Edge* insertEdge(Vertex* V_start, Vertex* V_end, W O)
	{
		Edge* edge_tmp = new Edge;
		edge_tmp->start = V_start;		//Wierzchołek początkowy
		edge_tmp->end = V_end;			//Wierzchołek końcowy
		edge_tmp->weight = O;

		V_start->inclist.push_front(edge_tmp);
		V_end->inclist.push_front(edge_tmp);

		edge_tmp->inclist_start = V_start->inclist.front();
		edge_tmp->inclist_end = V_end->inclist.front();

		edge_list.push_front(edge_tmp);
		return edge_tmp;
	}

	void removeVertex(Vertex *V)
	{
		Edge* edge_tmp;
		for(auto j = vertex_list.begin(); j != vertex_list.end(); j++)
		{
			if(*j == V)
			{
				for(auto i = V->inclist.begin(); i != V->inclist.end(); i++)
				{
					edge_tmp = *i;
					removeEdge(edge_tmp);
				}

				vertex_list.erase(j);
				delete V;
				break;
			}
		}
	}

	void removeEdge(Edge* E)
	{
		auto i = E->start->inclist.begin();
		auto j = E->end->inclist.begin();

		for(; i != E->start->inclist.end(); i++)
		{
			if(*i == E->inclist_start)
			{
				//cout << "ok1" <<endl;
				//E->start->inclist.erase(i);
				//cout << "ok2" <<endl;
				break;
			}
		}

		for(; j != E->end->inclist.end(); j++)
		{
			if(*j == E->inclist_end)
			{
				//cout << "ok3" << endl;
				//E->end->inclist.erase(j);
				//cout << "ok4" <<endl;
				break;
			}
		}


		for(auto k = edge_list.begin(); k != edge_list.end(); k++)
		{

			if(*k == E)
			{
				E->start->inclist.erase(i);
				E->end->inclist.erase(j);
				edge_list.erase(k);
				delete E;
				break;
			}
		}


	}

	//Iterator methods
	dlinklist<Edge*> incidentEdges(Vertex* V) {return V->inclist;}

	dlinklist<Vertex*> vertices(void) {return vertex_list;}

	dlinklist<Edge*> edges(void) {return edge_list;}

	//Additional methods
	void displayVertices(void)
	{
		std::cout << "displayVertices():" << std::endl;
		Vertex* vertex_tmp;
		for(auto i = vertex_list.begin(); i != vertex_list.end(); i++)
		{
			vertex_tmp = *i;
			std::cout << "Address: " << vertex_tmp << " Data: " << vertex_tmp->data << std::endl;
		}
	}

	void displayEdges(void)
	{
		cout << "displayEdges():" << std::endl;
		Edge* edge_tmp;
		for(auto i = edge_list.begin(); i != edge_list.end(); i++)
		{
			edge_tmp = *i;
			std::cout << "Address: " << edge_tmp << " Weight: " << edge_tmp->weight << std::endl;
		}
	}

	void dijkstra(void)
	{
		cout << vertices_amount; 
		cout << "Dijkstra" << endl;
		Vertex* v = V_tmp; //startowy
		Vertex* tmp;

		int U_idx = vertices_amount-1; // indeks vertexow
		int distance[vertices_amount]; // tablica odleglosci
		int locator[vertices_amount]; // tablica heapidx
		Vertex* map[vertices_amount]; // mapowanie z indeksów vertexa na wksaźnik vertexa 

		priority_queue<int, int> Q(vertices_amount); // tworzenie heap

		for(auto u = vertex_list.begin(); u != vertex_list.end(); u++) //For all Vertices in Graph
		{
			map[U_idx] = *u;						//Remap!! wpisywanie wskaźników na vertexy do tablicy 
			tmp = *u;

			if(*u == v)
				distance[U_idx] = 0;									//Initialize D[v] = 0
			else																															
				distance[U_idx] = 2000000;								//Initialize D[u] = inf

			locator[U_idx] = Q.insert(distance[U_idx], U_idx);		//Let a priority queue Q contain all the vertices of G using the D labels as keys

			U_idx--;																								
		}
		
    /*-----------------------------DBG--------------------------*/
		cout << "inicjalizacja D[u]" << endl;

		for(int idx_tmp = 0; idx_tmp < vertices_amount; idx_tmp++)
			cout << "D(" << idx_tmp << ") = " <<distance[idx_tmp] << endl;
		cout << "Kopiec: " << endl;
				Q.display();
 		/*-----------------------------DBG--------------------------*/
		
		while(!Q.empty())
		{
			auto u = Q.removeMin(); // u to index vertexa 
			cout << "indeks vertexa dla ktorego sprawdzamy edge incydentne : " << u << endl;
			auto e_val = incidentEdges(map[u]);
			for(auto e = e_val.begin(); e != e_val.end(); e++)	//for all e e G.indicentEdges(u)
			{
				Vertex* z = opposite(map[u], *e);  
				
				auto e_tmp = *e;
				int r = distance[u] + e_tmp->weight;
				if(r < distance[z->idx])
				{
 //cout << u << " d(u) " << distance[u] << " eval e: " << e_val[e]->weight << " distance z "<<distance[z->idx] << " r " << r << endl;
					distance[z->idx] = r;
					Q.replaceKey(locator[z->idx], z->idx);
				}
				

			}
		}

		for(int i = 0; i < vertices_amount; i++)
			cout << "i " << i << " D(i) " << distance[i] << endl;
	}

	GraphAdjList(int V_amount, float G_density)
	{
		int E_amount_max = (V_amount*V_amount - V_amount);
		int E_amount = G_density * E_amount_max;
		Vertex* V_curr[V_amount];

		for(int i = 0; i < V_amount; i++)
			V_curr[i] = insertVertex(i);

		int added_edges = 0;
		for(int a = 0; a < E_amount/V_amount + 1; a++)
			for(int b = 0; b < V_amount; b++)
				if( !((a == b) || added_edges > E_amount))
				{
					insertEdge(V_curr[a], V_curr[b], a+b);
					added_edges++;
				}
	}

	GraphAdjList()
	{
		vertices_amount = 0;
	}

	GraphAdjList(FILE* imp_file)
	{
		vertices_amount = 0;
		int E_amount, V_amount, V_start;
		int V_first, V_second, E_weight;

		fscanf(imp_file, "%d %d %d", &V_amount, &E_amount, &V_start);
		cout << "Start: " << "E: "<< E_amount << " V: " << V_amount << " V2: "<< V_start << endl;

		Vertex* V_curr[V_amount];
		for(int i = 0; i < V_amount; i++)
			 V_curr[i] = insertVertex(i);
		V_tmp = V_curr[V_start];

		for(int i = 0; i < E_amount; i++)
		{
			fscanf(imp_file, "%d %d %d", &V_first, &V_second, &E_weight);
			cout << " i: " << i << " V: " << V_first << " V2: " << V_second << " E: " << E_weight << endl;
			insertEdge(V_curr[V_first], V_curr[V_second], E_weight);
		}
	}

	struct Vertex
	{
		W data;
		dlinklist<Edge*> inclist;
		int idx;
	};

	struct Edge
	{
		W weight;
		struct Vertex* start;
		struct Vertex* end;
		Edge* inclist_start;
		Edge* inclist_end;
	};

};
#endif