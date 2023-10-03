#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

class BellmanFord {
public:
    int numVertices, numEdges;
    vector<Edge> edges;

    BellmanFord(int V, int E) {
        numVertices = V;
        numEdges = E;
        edges.resize(numEdges);
    }

    void addEdge(int src, int dest, int weight, int index) {
        edges[index].source = src;
        edges[index].destination = dest;
        edges[index].weight = weight;
    }

    void findShortestPath(int source) {
        vector<int> distance(numVertices, INT_MAX);
        distance[source] = 0;

        for (int i = 0; i < numVertices - 1; ++i) {
            for (int j = 0; j < numEdges; ++j) {
                int u = edges[j].source;
                int v = edges[j].destination;
                int w = edges[j].weight;

                if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        // Check for negative weight cycles
        for (int j = 0; j < numEdges; ++j) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                cout << "Graph contains a negative weight cycle!" << endl;
                return;
            }
        }

        // Print shortest distances
        cout << "Shortest distances from node " << source << ":" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Node " << i << ": " << distance[i] << endl;
        }
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    BellmanFord bf(V, E);

    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;
        bf.addEdge(src, dest, weight, i);
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    bf.findShortestPath(source);

    return 0;
}
