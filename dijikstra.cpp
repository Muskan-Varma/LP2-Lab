#include <bits/stdc++.h>
using namespace std;
#define V 9
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++)
		if (mstSet[i] == false && key[i] < min)
			min = key[i], min_index = i;
	return min_index;
}
void printDijkstra(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"<< graph[parent[i]][i] << " \n";
}
void dijkstra(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		
		int u = minKey(key, mstSet);
		
        mstSet[u] = true;
		
		for (int v = 0; v < V; v++)

			if (graph[u][v]!=0 && mstSet[v] == false && key[u] != INT_MAX && (key[u]+graph[u][v] < key[v]))
				parent[v] = u, key[v] = key[u]+graph[u][v];
	}
	printDijkstra(parent, graph);
}
int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0} };

	dijkstra(graph);
	return 0;
}