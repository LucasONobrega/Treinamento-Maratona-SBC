// ALGORITMO DE KRUSKAL
// Árvore Geradora Mínima

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int kruskal(int n, vector<iii> arestas)
{
    int u, v;
    int pi[n], comp_sz[n];
    int result = 0;

    iii e;

    for(int i = 0; i < n; i++)
    {
        comp_sz[i] = 1;
        pi[i] = i;
    }

    // ordenação das arestas
    sort(arestas.begin(), arestas.end());

    // arvore geradora máxima!
    //sort(arestas.begin(), arestas.end(), greater<iii>());

    for(int i = 0, k = 0; i < arestas.size() && k < n-1; i++)
    {
        e = arestas[i];

        //union-find
        for(u = (e.second).first; u != pi[u]; u = pi[u]);
        for(v = (e.second).second; v != pi[v]; v = pi[v]);

        if(u == v) //se a aresta gera um ciclo
            continue;

        if(comp_sz[u] < comp_sz[v])
        {
            pi[u] = v;
            comp_sz[v] += comp_sz[u];
        }

        else
        {
           pi[v] = u;
           comp_sz[u] += comp_sz[v];
        }
       
        result += arestas[i].first;
        k++;
    }

    for(int i = 0; i<n; i++)
        cout << comp_sz[i] << endl;

    return result;
}

int main()
{
    int N = 5;

    vector< iii > arestas;

    arestas.push_back(iii(9, ii(0,2)));
    arestas.push_back(iii(1, ii(0,3)));
    arestas.push_back(iii(1, ii(0,4)));
    arestas.push_back(iii(2, ii(1,4)));
    arestas.push_back(iii(5, ii(1,4)));
    arestas.push_back(iii(9, ii(2,3)));    
    
    cout << kruskal(N, arestas) << endl;
    
    return 0;
}

