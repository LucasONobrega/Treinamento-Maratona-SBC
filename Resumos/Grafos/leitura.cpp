// Leitura de um grafo

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector< vector<int> > g;
 
    int n, m; // número de vértices e arestas
    cin >> n >> m;

    g.resize(n);

    int a, b;

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 0; i < g.size(); i++)
    {
        cout << i << ":";
    
        for(int j = 0; j < g[i].size(); j++)
            cout << " " << g[i][j];

        cout << "\n";
    }

    return 0;
}