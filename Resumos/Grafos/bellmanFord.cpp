// ALGORITMO DE BELLMAN-FORD
// Caminho mínimo

#include <iostream>
#include <vector>
#define INF 0x3F3F3F3F

using namespace std; 

typedef pair<int,int> ii;

// retorna false se tem ciclo negativo, true caso contrário
bool bellmanFord(int N, int s, vector<ii> *adj)
{ 
    int dis[N];
    bool ret = true;

    for (int i = 0; i < N; i++) 
        dis[i] = INF; 

    dis[s] = 0; 

    // Relaxamento das arestas
    for (int i = 0; i < (N-1); i++) 
    { 
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < adj[j].size(); k++)
            {
                if (dis[j] + adj[j][k].second < dis[adj[j][k].first]) 
                    dis[adj[j][k].first] = dis[j] + adj[j][k].second; 
            }
        }
    } 

    // Checando se existe ciclos negativos
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < adj[i].size(); j++)
        {                        
            if (dis[i] != INF && ((dis[i] + adj[i][j].second) < dis[adj[i][j].first]))
                ret = false;
        }
    }

    for (int i = 0; i < N; i++) 
        cout << i << " " << dis[i] << endl; 

    return ret;
} 

int main() 
{
    int N = 7;

    vector< ii > adj[N]; //lista de adjacência
    
    adj[0].push_back(ii(2,9));
    adj[0].push_back(ii(3,1));
    adj[0].push_back(ii(4,1));
    adj[1].push_back(ii(5,2));
    adj[1].push_back(ii(6,10));
    adj[3].push_back(ii(2,9));
    adj[4].push_back(ii(1,6));
    adj[5].push_back(ii(4,1));

    cout << bellmanFord(N, 0, adj) << endl;

    return 0;
}
