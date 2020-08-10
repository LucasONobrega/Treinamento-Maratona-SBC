// ALGORITMO DE FLOYD-WARSHALL
// Caminho mínimo

#include <iostream>
#include <vector>
#define INF 0x3F3F3F3F

using namespace std; 

typedef pair<int,int> ii;

void floydWarshall(int N, vector<ii> *adj)
{ 
    int dis[N][N];

    for (int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
    	{
	        if(i != j)
	        	dis[i][j] = INF;
	        else
	       		dis[i][j] = 0;
	    } 
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < adj[i].size(); j++)
        	dis[i][adj[i][j].first] = adj[i][j].second;

	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
	        for(int j = 0; j < N; j++)
	            if(dis[i][j] > dis[i][k] + dis[k][j])
	                dis[i][j] = dis[i][k] + dis[k][j];

    for(int i = 0; i < N; i++)
    	for(int j = 0; j < N; j++)
    		cout << i << " " << j << " = " << dis[i][j] << endl;
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

    floydWarshall(N, adj);

    return 0;
}




