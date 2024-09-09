#include <bits/stdc++.h>
using namespace std;

struct Node {
    int board[3][3];
    int level;
    Node *parent;
};

// Function to print the puzzle
void printPuzzle(Node goal) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << goal.board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the goal state is reached
bool isGoalState(Node goal) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (goal.board[i][j] == 0)
                continue;
            if (goal.board[i][j] != count + 1)
                return false;
            count++;
        }
    }
    return true;
}

// Function to find the blank tile position
pair<int, int> findBlank(Node node) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (node.board[i][j] == 0)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

// Function to generate the child nodes
vector<Node> generateChildren(Node parent) {
    vector<Node> children;
    pair<int, int> pos = findBlank(parent);
    int row = pos.first, col = pos.second;

    // Move up
    if (row > 0) {
        Node child = parent;
        swap(child.board[row][col], child.board[row - 1][col]);
        child.level = parent.level + 1;
        child.parent = &parent;
        children.push_back(child);
    }

    // Move down
    if (row < 2) {
        Node child = parent;
        swap(child.board[row][col], child.board[row + 1][col]);
        child.level = parent.level + 1;
        child.parent = &parent;
        children.push_back(child);
    }

    // Move left
    if (col > 0) {
        Node child = parent;
        swap(child.board[row][col], child.board[row][col - 1]);
        child.level = parent.level + 1;
        child.parent = &parent;
        children.push_back(child);
    }

    // Move right
    if (col < 2) {
        Node child = parent;
        swap(child.board[row][col], child.board[row][col + 1]);
        child.level = parent.level + 1;
        child.parent = &parent;
        children.push_back(child);
    }

    return children;
}

// Function to solve the 8-puzzle problem using BFS
void BFSolution() {
    Node start;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> start.board[i][j];
        }
    }
    start.level = 0;

    queue<Node> q;
    q.push(start);

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (isGoalState(current)) {
            printPuzzle(current);
            return;
        }

        vector<Node> children = generateChildren(current);
        for (Node &child : children) {
            q.push(child);
        }
    }

    cout << "No solution found." << endl;
}

int main() {
    BFSolution();
    return 0;
}