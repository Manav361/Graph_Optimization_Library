#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, capacity, flow;
    Edge(int t, int c) : to(t), capacity(c), flow(0) {}
};

class FordFulkerson {
public:
    int numVertices;
    vector<vector<Edge>> graph;

    FordFulkerson(int V) {
        numVertices = V;
        graph.resize(V);
    }

    void addEdge(int from, int to, int capacity) {
        graph[from].emplace_back(to, capacity);
        graph[to].emplace_back(from, 0); // Backward edge with zero capacity
    }

    int maxFlow(int source, int sink) {
        int maxFlow = 0;

        while (true) {
            vector<int> parent(numVertices, -1);
            queue<pair<int, int>> q;
            q.push({source, INF});

            while (!q.empty()) {
                int current = q.front().first;
                int flow = q.front().second;
                q.pop();

                for (Edge& edge : graph[current]) {
                    int to = edge.to;
                    if (parent[to] == -1 && edge.capacity - edge.flow > 0) {
                        parent[to] = current;
                        int new_flow = min(flow, edge.capacity - edge.flow);
                        if (to == sink) {
                            maxFlow += new_flow;
                            int v = sink;
                            while (v != source) {
                                int u = parent[v];
                                for (Edge& e : graph[u]) {
                                    if (e.to == v) {
                                        e.flow += new_flow;
                                        break;
                                    }
                                }
                                for (Edge& e : graph[v]) {
                                    if (e.to == u) {
                                        e.flow -= new_flow;
                                        break;
                                    }
                                }
                                v = u;
                            }
                            break;
                        }
                        q.push({to, new_flow});
                    }
                }
            }

            // If there are no more augmenting paths, exit
            if (parent[sink] == -1)
                break;
        }

        return maxFlow;
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    FordFulkerson ff(V);

    for (int i = 0; i < E; ++i) {
        int from, to, capacity;
        cout << "Enter edge " << i + 1 << " (from to capacity): ";
        cin >> from >> to >> capacity;
        ff.addEdge(from, to, capacity);
    }

    int source, sink;
    cout << "Enter the source and sink nodes: ";
    cin >> source >> sink;

    int maxFlow = ff.maxFlow(source, sink);
    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}
