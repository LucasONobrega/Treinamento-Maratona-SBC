// ALGORITMO DE DIJKSTRA
// Caminho mínimo

#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3F3F3F3F

using namespace std;

typedef pair<int,int> ii;

void dijkstra(int s, vector<ii> *adj, int N)
{
    int D[N], pi[N]; // distância e antecessor
    
    for(int i = 0; i < N; i++)
    {
        D[i] = INF;
        pi[i] = -1;
    }
    
    priority_queue< ii, vector< ii >, greater< ii > > Q;

    D[s] = 0;
    Q.push(ii(0, s));

    while(!Q.empty())
    {
        ii top = Q.top();
        Q.pop();
 
        int u = top.second, d = top.first;

        if( d <= D[u] )
            for(int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first, cost = adj[u][i].second;
    
                if( D[v] > (D[u] + cost) )
                {
                    D[v] = D[u] + cost;
                    pi[v] = u;
                    Q.push(ii(D[v], v));
                }
            }
    }

    for(int i=0; i<N; i++)
    {
        cout << "distância para " << i << " = " << D[i] << endl;
    }
}

int main()
{
    int N = 5;

    vector< ii > adj[N]; //lista de adjacência
    
    adj[0].push_back(ii(2,9));
    adj[0].push_back(ii(3,1));
    adj[0].push_back(ii(4,1));
    adj[1].push_back(ii(4,2));
    adj[3].push_back(ii(2,9));
    adj[4].push_back(ii(1,5));

    dijkstra(0, adj, N);

    return 0;
}
