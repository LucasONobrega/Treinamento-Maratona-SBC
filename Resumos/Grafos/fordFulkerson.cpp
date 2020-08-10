// ALGORITMO DE EDMONDS-KARP
// Fluxo máximo em redes

#include <iostream> 
#include <string.h> 
#include <queue>
#define INF 0x3F3F3F3F

using namespace std; 

typedef pair<int, int> ii;

bool bfs(int n, vector<vector<int>> rGraph, int s, int t, int* parent) 
{ 
	bool visited[n]; 
	
	for(int i = 0; i < n; i++)
		visited[i] = false;

	queue <int> q; 
	q.push(s); 
	visited[s] = true; 
	parent[s] = -1; 

	while (!q.empty()) 
	{ 
		int u = q.front(); 
		q.pop(); 

		for (int v=0; v<n; v++) 
		{ 
			if (visited[v]==false && rGraph[u][v] > 0) 
			{ 
				q.push(v); 
				parent[v] = u; 
				visited[v] = true; 
			} 
		} 
	} 

	return (visited[t] == true); 
} 

int fordFulkerson(int n, int s, int t, vector<ii> *G) 
{ 
	// grafo residual
	vector<vector<int>> rGraph;

	rGraph.resize(n);

	for(int i = 0; i < n; i++)
	{
		rGraph[i].resize(n);
		for(int j = 0; j < n; j++)
			rGraph[i][j] = 0;		
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < G[i].size(); j++)
			rGraph[i][G[i][j].first] = G[i][j].second; //first é o vértice que é conectado, second é a capacidade da aresta

	int parent[n]; // preenchida pelo BFS, guarda o caminho
	int max_flow = 0; 

	while (bfs(n, rGraph, s, t, parent)) 
	{ 
		int path_flow = INF; 
		for (int v = t; v != s; v = parent[v]) 
		{ 
			int u = parent[v]; 
			path_flow = min(path_flow, rGraph[u][v]); 
		} 

		// atualizando a capacidade das arestas
		for (int v = t; v != s; v = parent[v]) 
		{ 
			int u = parent[v]; 
			rGraph[u][v] -= path_flow; 
			rGraph[v][u] += path_flow; 
		} 

		max_flow += path_flow; 
	} 
	
	return max_flow; 
} 

int main() 
{ 
	int N = 6;
	vector<ii> G[N];

	G[0].push_back(ii(1,16));
	G[0].push_back(ii(2,13));
	G[1].push_back(ii(2,10));
	G[1].push_back(ii(3,12));
	G[2].push_back(ii(1,4));
	G[2].push_back(ii(4,14));
	G[3].push_back(ii(2,9));
	G[3].push_back(ii(5,20));
	G[4].push_back(ii(3,7));
	G[4].push_back(ii(5,4));

	cout << fordFulkerson(N, 0, 5, G) << endl; 

	return 0; 
} 
