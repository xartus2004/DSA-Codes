#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Define the states as a vector of integers
vector<int> state = {0, 0};

// Function to print the state
void printState() {
    cout << state[0] << " " << state[1] << endl;
}

// Function to check if the goal state is reached
bool isGoal() {
    return state[0] == 4 && state[1] == 0;
}

// Function to perform a move
void move(int from, int to) {
    int temp = state[from];
    state[from] = 0;
    state[to] = min(temp, 3);
}

// Function to generate the neighbor states
vector<vector<int>> generateNeighbors(vector<vector<int>>& visited) {
    vector<vector<int>> neighbors;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                vector<int> newState = state;
                move(i, j);
                if (!visited[newState[0]][newState[1]]) {
                    neighbors.push_back(newState);
                    visited[newState[0]][newState[1]] = true;
                }
            }
        }
    }
    return neighbors;
}

// Function to solve the water jug problem using BFS
bool solveWaterJug() {
    queue<vector<int>> q;
    q.push(state);
    vector<vector<int>> visited(4, vector<int>(3, false));
    visited[0][0] = true;

    while (!q.empty()) {
        vector<int> current = q.front();
        q.pop();

        if (isGoal()) {
            state = current;
            return true;
        }

        vector<vector<int>> neighbors = generateNeighbors(visited);
        for (auto neighbor : neighbors) {
            q.push(neighbor);
        }
    }

    return false;
}

int main() {
    // Uncomment the following lines to test the water jug solver
    if (solveWaterJug()) {
        cout << "Solution found:" << endl;
        printState();
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}