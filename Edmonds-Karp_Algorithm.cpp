#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int n; // Number of nodes

bool bfs(vector<vector<int>>& graph, vector<int>& parent, int source, int sink) {
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(source);
    visited[source] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    return visited[sink];
}

int edmondsKarp(vector<vector<int>>& graph, int source, int sink) {
    vector<int> parent(n);
    int maxFlow = 0;
    
    while (bfs(graph, parent, source, sink)) {
        int pathFlow = INF;
        int v = sink;
        
        while (v != source) {
            int u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
            v = u;
        }
        
        v = sink;
        
        while (v != source) {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
            v = u;
        }
        
        maxFlow += pathFlow;
    }
    
    return maxFlow;
}

int main() {
    int m; // Number of edges
    cin >> n >> m;
    
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with capacity w
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    
    int source, sink; // Source and sink nodes
    cin >> source >> sink;
    
    int maxFlow = edmondsKarp(graph, source, sink);
    
    cout << "Max Flow: " << maxFlow << endl;
    
    return 0;
}
