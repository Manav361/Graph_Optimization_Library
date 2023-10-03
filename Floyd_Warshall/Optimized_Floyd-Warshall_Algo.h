#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

vector<vector<int>> optimized_floyd_warshall(const vector<vector<int>>& graph) {
    int n = graph.size();
    
    // Initialize the result matrix with the same values as the input graph
    vector<vector<int>> result = graph;
    
    // Apply the Floyd-Warshall algorithm with optimized updates
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (result[i][k] != INF && result[k][j] != INF) {
                    result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
                }
            }
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 4, INF, INF},
        {1, 0, 3, 2, INF},
        {4, 3, 0, 5, 7},
        {INF, 2, 5, 0, 6},
        {INF, INF, 7, 6, 0}
    };

    vector<vector<int>> result = optimized_floyd_warshall(graph);
    
    cout << "Shortest distances:\n";
    for (const auto& row : result) {
        for (int distance : row) {
            cout << (distance == INF ? "INF" : to_string(distance)) << "\t";
        }
        cout << endl;
    }

    return 0;
}
