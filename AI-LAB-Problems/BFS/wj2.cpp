#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

struct State {
    int x, y;
    State(int _x, int _y) : x(_x), y(_y) {}
};

queue<State> queueState;
unordered_set<int> visited;

void generateStates(State s);
bool checkIfVisited(State s);
int hashState(State s);

int main() {
    State startState(0, 0);
    queueState.push(startState);

    while (!queueState.empty()) {
        State s = queueState.front();
        queueState.pop();

        cout << "--> (" << s.x << "," << s.y << ")";

        if (s.x == 2) break;

        generateStates(s);
    }

    return 0;
}

void generateStates(State s) {
    if (s.x < 4) {
        State newState(4, s.y);
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
    if (s.y < 3) {
        State newState(s.x, 3);
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
    if (s.x > 0) {
        State newState(0, s.y);
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
    if (s.y > 0) {
        State newState(s.x, 0);
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
    if (0 < (s.x + s.y) && (s.x + s.y) >= 4 && s.y > 0) {
        State newState(4, s.y - (4 - s.x));
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
    if (0 < (s.x + s.y) && (s.x + s.y) >= 3 && s.x > 0) {
        State newState(s.x - (3 - s.y), 3);
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
    if (0 < (s.x + s.y) && (s.x + s.y) <= 4 && s.y >= 0) {
        State newState(s.x + s.y, 0);
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
    if (0 < (s.x + s.y) && (s.x + s.y) <= 3 && s.x >= 0) {
        State newState(0, s.x + s.y);
        if (!checkIfVisited(newState)) {
            queueState.push(newState);
            visited.insert(hashState(newState));
        }
    }
}

bool checkIfVisited(State s) {
    return visited.find(hashState(s)) != visited.end();
}

int hashState(State s) {
    return s.x * 10 + s.y; // Using a simple hash function for State
}
