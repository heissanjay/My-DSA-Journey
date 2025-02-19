#include <bits/stdc++.h>


void dijkstra(std::vector<std::vector<std::pair<int,int>>> &adj, int n, int src) {
    // create distance list which holds the distance of each node from the given source
    // and initialize all to inf.
    std::vector<int> dist(n+1, INT_MAX);
    // set the source's distance to 0
    dist[src] = 0;
    // we need priority queue (min-heap) to hold the short node from the current node.
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;

        for(auto &edge: adj[u]){ // visit the adjacent nodes of the current node
            int v = edge.first; // the adjacent node
            int w = edge.second; // cost to traverse from the current node to this node (u -> v)
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i < n; i++){
        std::cout<<"Shortest path from src:"<<src<<" to the Node: "<<i<<" is "<<dist[i]<<std::endl;
    }
}


int main() {
    int n = 7;
    std::vector<std::vector<std::pair<int, int>>> adj(n+1);
    // directed weighted graph
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 4});
    adj[2].push_back({4, 7});
    adj[2].push_back({3, 1});
    adj[3].push_back({5, 3});
    adj[4].push_back({6, 1});
    adj[5].push_back({4, 2});
    adj[5].push_back({6, 5});

    dijkstra(adj, n, 1);

}