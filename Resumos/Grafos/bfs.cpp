// BUSCA EM LARGURA

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs (int N, int inicio, int final, vector<vector<int>> adj)
{
    bool visitados[N];
    int sucessor[N], distancia[N];
    queue<int> f;
    
    for(int i = 0; i < N; i++)
        visitados[i] = false;

    distancia[inicio] = 0;
    f.push(inicio);

    while(!f.empty())
    {
        int a = f.front();
        f.pop();

        for(int i = 0; i < adj[a].size(); i++)
            if(!visitados[adj[a][i]])
            {
                visitados[adj[a][i]] = true;
                sucessor[adj[a][i]] = a;
                distancia[adj[a][i]] = distancia[a] + 1;
                f.push(adj[a][i]);

                if(adj[a][i] == final)
                    return;
            }
    }
}

int main()
{
    vector< vector<int> > adj;
 
    int n = 4;
    
    adj.resize(n);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(1);

    bfs(n, 0, 1, adj);
}