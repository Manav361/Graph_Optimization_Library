#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = INT_MAX;

class HungarianAlgorithm {
private:
    int n, m;
    vector<vector<int>> costMatrix;
    vector<int> labelX, labelY;
    vector<int> matchX, matchY;
    vector<bool> visitedX, visitedY;

    bool dfs(int u) {
        visitedX[u] = true;
        for (int v = 0; v < m; ++v) {
            if (!visitedY[v] && labelX[u] + labelY[v] == costMatrix[u][v]) {
                visitedY[v] = true;
                if (matchY[v] == -1 || dfs(matchY[v])) {
                    matchX[u] = v;
                    matchY[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    void updateLabels() {
        int delta = INF;
        for (int i = 0; i < n; ++i) {
            if (visitedX[i]) {
                for (int j = 0; j < m; ++j) {
                    if (!visitedY[j]) {
                        delta = min(delta, labelX[i] + labelY[j] - costMatrix[i][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (visitedX[i]) {
                labelX[i] -= delta;
            }
        }

        for (int j = 0; j < m; ++j) {
            if (visitedY[j]) {
                labelY[j] += delta;
            }
        }
    }

public:
    HungarianAlgorithm(const vector<vector<int>>& matrix) {
        costMatrix = matrix;
        n = matrix.size();
        m = matrix[0].size();
        labelX.assign(n, 0);
        labelY.assign(m, 0);
        matchX.assign(n, -1);
        matchY.assign(m, -1);
    }

    int solve() {
        for (int i = 0; i < n; ++i) {
            labelX[i] = *max_element(costMatrix[i].begin(), costMatrix[i].end());
        }

        for (int i = 0; i < n; ++i) {
            while (true) {
                visitedX.assign(n, false);
                visitedY.assign(m, false);
                if (dfs(i)) {
                    break;
                }
                updateLabels();
            }
        }

        int maxWeight = 0;
        for (int i = 0; i < n; ++i) {
            maxWeight += costMatrix[i][matchX[i]];
        }

        return maxWeight;
    }

    vector<pair<int, int>> getMatching() {
        vector<pair<int, int>> matching;
        for (int i = 0; i < n; ++i) {
            matching.emplace_back(i, matchX[i]);
        }
        return matching;
    }
};

int main() {
    vector<vector<int>> costMatrix = {
        {350, 400, 450},
        {450, 550, 400},
        {300, 600, 350}
    };

    HungarianAlgorithm hungarian(costMatrix);
    int maxWeight = hungarian.solve();

    cout << "Maximum Weight: " << maxWeight << endl;
    vector<pair<int, int>> matching = hungarian.getMatching();
    cout << "Matching: ";
    for (const auto& edge : matching) {
        cout << "(" << edge.first << "," << edge.second << ") ";
    }
    cout << endl;

    return 0;
}
