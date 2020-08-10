// BUSCA EM PROFUNDIDADE

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(int N, int inicio, int final, vector<vector<int>> adj)
{
    bool visitados[N];
    stack<int> s;

    for(int i = 0; i < N; i++)
        visitados[i] = false;

    s.push(inicio);

    while(!s.empty())
    {
        int a = s.top();
        s.pop();
        
        for(int i = 0; i < adj[a].size(); i++)
            if(!visitados[adj[a][i]])
            {
                visitados[adj[a][i]] = true;
                s.push(adj[a][i]);

                if(adj[a][i] == final)
                    return true;
            }
    }

    return false;
}

int main()
{
    vector< vector<int> > adj;
 
    int n = 4;
    
    adj.resize(n);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(1);

    cout << dfs(n, 0, 3, adj) << endl;
}