#include <bits/stdc++.h>
using namespace std;

void bellman_ford(vector<vector<pair<int,int>>> adj, int N, int src){
    vector<int> dist(N+1, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < N; i++){
        for(int j = 1; j <= N; j++){
            for (const auto& node: adj[j]){
                if(dist[j] != INT_MAX && dist[j]+node.second < dist[node.first]){
                    dist[node.first] = dist[j]+node.second;
                }
            }   
        }
    }


    for (int i = 1; i <= N; i++){
        for (const auto& node: adj[i]){
            if(dist[i]+node.second < dist[node.first]){
                cout << "Graph has negative cycle" << endl;
                return;
            }
        }
    }

    for(int i = 1; i < N; i++){
        cout << "Distance from src node: " << src <<" to node: "<<i<<" is "<<dist[i]<<endl;
    }
}


int main(){
    int N {7};
    vector<vector<pair<int,int>>> adj(N+1);

    adj[1].push_back({2, 2});
    adj[1].push_back({3, 4});
    adj[2].push_back({4, 7});
    adj[2].push_back({3, 1});
    adj[3].push_back({5, -3});
    adj[4].push_back({6, 1});
    adj[5].push_back({4, 2});
    adj[5].push_back({6, 5});
    


    bellman_ford(adj, N, 1);
}