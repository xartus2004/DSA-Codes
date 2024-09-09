#include <bits/stdc++.h>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int x, y; // Coordinates of the node
    int g, h; // Cost values for path and heuristic
    Node* parent; // Parent node in the path

    Node(int x, int y, int g, int h, Node* parent) : x(x), y(y), g(g), h(h), parent(parent) {}

    // Calculate the total cost f = g + h
    int f() const {
        return g + h;
    }
};

// Custom comparator for the priority queue
struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->f() > b->f();
    }
};

// Function to calculate the heuristic value (Manhattan distance)
int calculateHeuristic(int x, int y, int targetX, int targetY) {
    return abs(targetX - x) + abs(targetY - y);
}

// Function to check if a given position is valid
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Function to reconstruct the path from the goal node to the start node
vector<pair<int, int>> reconstructPath(Node* goal) {
    vector<pair<int, int>> path;
    Node* current = goal;
    while (current != nullptr) {
        path.push_back({current->x, current->y});
        current = current->parent;
    }
    reverse(path.begin(), path.end());
    return path;
}

// A* algorithm implementation
vector<pair<int, int>> aStar(vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Priority queue to store the open nodes
    priority_queue<Node*, vector<Node*>, CompareNodes> open;

    // Map to store the cost values for each node
    unordered_map<Node*, int> gValues;

    // Create the start node
    Node* start = new Node(startX, startY, 0, calculateHeuristic(startX, startY, targetX, targetY), nullptr);
    open.push(start);
    gValues[start] = 0;

    // Map to store the visited nodes
    unordered_map<Node*, bool> visited;

    while (!open.empty()) {
        // Get the node with the lowest f value from the open list
        Node* current = open.top();
        open.pop();

        // Check if the current node is the goal node
        if (current->x == targetX && current->y == targetY) {
            return reconstructPath(current);
        }

        // Mark the current node as visited
        visited[current] = true;

        // Generate the neighbors of the current node
        vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& neighbor : neighbors) {
            int newX = current->x + neighbor.first;
            int newY = current->y + neighbor.second;

            // Check if the neighbor is a valid position
            if (isValid(newX, newY, rows, cols)) {
                // Calculate the new g value for the neighbor
                int newG = current->g + 1;

                // Create the neighbor node
                Node* neighborNode = new Node(newX, newY, newG, calculateHeuristic(newX, newY, targetX, targetY), current);

                // Check if the neighbor has not been visited or the new g value is lower
                if (!visited[neighborNode] || newG < gValues[neighborNode]) {
                    // Update the g value for the neighbor
                    gValues[neighborNode] = newG;

                    // Add the neighbor to the open list
                    open.push(neighborNode);

                    // Mark the neighbor as visited
                    visited[neighborNode] = true;
                }
            }
        }
    }

    // No path found
    return {};
}

int main() {
    // Example usage
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    int startX = 0;
    int startY = 0;
    int targetX = 3;
    int targetY = 3;

    vector<pair<int, int>> path = aStar(grid, startX, startY, targetX, targetY);

    if (!path.empty()) {
        cout << "Path found:" << endl;
        for (const auto& point : path) {
            cout << "(" << point.first << ", " << point.second << ")" << endl;
        }
    } else {
        cout << "No path found" << endl;
    }

    return 0;
}
