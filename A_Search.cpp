#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;       // Coordinates
    int g;          // Cost from start to current node
    int h;          // Heuristic (estimated cost to goal)
    
    Node(int x, int y, int g, int h) : x(x), y(y), g(g), h(h) {}
    
    // Custom comparison for priority queue
    bool operator<(const Node& other) const {
        return (g + h) > (other.g + other.h);
    }
};

bool isValid(int x, int y, int maxX, int maxY) {
    return (x >= 0 && x < maxX && y >= 0 && y < maxY);
}

int astar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    int maxX = grid.size();
    int maxY = grid[0].size();
    
    vector<vector<int>> visited(maxX, vector<int>(maxY, 0));
    
    priority_queue<Node> pq;
    pq.push(Node(start.first, start.second, 0, abs(start.first - goal.first) + abs(start.second - goal.second)));
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        int x = current.x;
        int y = current.y;
        
        if (x == goal.first && y == goal.second) {
            return current.g; // Path found
        }
        
        if (visited[x][y]) {
            continue;
        }
        
        visited[x][y] = 1;
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isValid(newX, newY, maxX, maxY) && grid[newX][newY] != 1) {
                int newG = current.g + 1;
                int newH = abs(newX - goal.first) + abs(newY - goal.second);
                pq.push(Node(newX, newY, newG, newH));
            }
        }
    }
    
    return -1; // No path found
}

int main() {
    int maxX, maxY;
    cin >> maxX >> maxY;
    
    vector<vector<int>> grid(maxX, vector<int>(maxY));
    
    for (int i = 0; i < maxX; ++i) {
        for (int j = 0; j < maxY; ++j) {
            cin >> grid[i][j];
        }
    }
    
    pair<int, int> start, goal;
    cin >> start.first >> start.second >> goal.first >> goal.second;
    
    int result = astar(grid, start, goal);
    
    if (result != -1) {
        cout << "Shortest Path Length: " << result << endl;
    } else {
        cout << "No Path Found!" << endl;
    }
    
    return 0;
}
