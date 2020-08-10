// ALGORITMO DE PRIM
// Árvore Geradora Mínima

#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3F3F3F3F

using namespace std; 

typedef pair<int,int> ii;

int prim(int N, vector<ii> *adj)
{
	int D[N], pi[N];
	bool visited[N];
	int ans = 0;

	for(int i = 0; i < N; i++)
	{
		D[i] = INF;
		pi[i] = -1;
		visited[i] = false;
	}

	priority_queue< ii, vector<ii>, greater<ii>> Q;

	D[0] = 0;
	Q.push(ii(0,0));

	while(!Q.empty())
	{
		ii top = Q.top();  
		Q.pop();
		int u = top.second, d = top.first;

		if(!visited[u])
		{
			ans += d;
			visited[u] = true;

			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].first, cost = adj[u][i].second;

				if(!visited[v] && (D[v] > cost))
				{
					D[v] = cost;
					pi[v] = u;
					Q.push( ii(D[v], v));
				}
			}
		}
	}

	for(int i=0;i<N;i++)
		cout << D[i] << endl; 

	return ans;
}

int main() 
{
    int N = 5;

    vector< ii > adj[N]; //lista de adjacência
    
    adj[0].push_back(ii(2,9));
    adj[2].push_back(ii(0,9));

    adj[0].push_back(ii(3,1));
    adj[3].push_back(ii(0,1));

    adj[0].push_back(ii(4,1));
    adj[4].push_back(ii(0,1));

    adj[1].push_back(ii(4,2));
    adj[4].push_back(ii(1,2));

	adj[1].push_back(ii(4,5));
    adj[4].push_back(ii(1,5));

    adj[2].push_back(ii(3,9));
    adj[3].push_back(ii(2,9));
    
    cout << prim(N, adj) << endl;

    return 0;
}