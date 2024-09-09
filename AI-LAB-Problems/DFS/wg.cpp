#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct State {
    int x, y;
    State(int _x, int _y) : x(_x), y(_y) {}
};

stack<State> stackState;
vector<State> visited;

void generateStates(State s);
void pushState(State s);
bool checkIfVisited(State s);

int main() {
    State startState(0, 0);

    stackState.push(startState);

    while (!stackState.empty()) {
        State s = stackState.top();
        stackState.pop();

        cout << "--> (" << s.x << "," << s.y << ")";

        if (s.x == 2) break;

        generateStates(s);
    }

    return 0;
}

void generateStates(State s) {
    if (s.x < 4) {
        pushState(State(4, s.y));
    }
    if (s.y < 3) {
        pushState(State(s.x, 3));
    }
    if (s.x > 0) {
        pushState(State(0, s.y));
    }
    if (s.y > 0) {
        pushState(State(s.x, 0));
    }
    if (0 < (s.x + s.y) && (s.x + s.y) >= 4 && s.y > 0) {
        pushState(State(4, s.y - (4 - s.x)));
    }
    if (0 < (s.x + s.y) && (s.x + s.y) >= 3 && s.x > 0) {
        pushState(State(s.x - (3 - s.y), 3));
    }
    if (0 < (s.x + s.y) && (s.x + s.y) <= 4 && s.y >= 0) {
        pushState(State(s.x + s.y, 0));
    }
    if (0 < (s.x + s.y) && (s.x + s.y) <= 3 && s.x >= 0) {
        pushState(State(0, s.x + s.y));
    }
}

void pushState(State s) {
    if (!checkIfVisited(s)) {
        stackState.push(s);
        visited.push_back(s);
    }
}

bool checkIfVisited(State s) {
    for (State st : visited) {
        if (st.x == s.x && st.y == s.y)
            return true;
    }
    return false;
}
