#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

typedef pair<int, int> pii;

vector<vector<pii>> graph; // Adjacency list representation of the graph

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;
    
    graph.resize(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    
    int start; // Starting node
    cin >> start;
    
    vector<int> dist = dijkstra(start, n);
    
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
    
    return 0;
}
