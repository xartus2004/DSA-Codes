// Write a program to implement A* Algorithm

#include <bits/stdc++.h>
using namespace std;

int heuristic(int i, int j, int k, int l)
{
    // Manhattan Distance
    return abs(i - k) + abs(j - l);
}

void aStarSearch(vector<vector<int>> &matrix, vector<pair<int, int>> &path, int i, int j, int k, int l, int cost=0, vector<pair<int, int>> trav={})
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix.front().size() || matrix[i][j] == 1)
        return;

    if (!path.empty() && cost > path.size())
        return;

    trav.push_back({i, j});
    
    if (matrix[i][j] == 2)
    {
        path = trav;
        return;
    }

    vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    sort(dir.begin(), dir.end(), [i,j,k,l](auto a, auto b) { return heuristic(i+a.first, j+a.second, k, l) < heuristic(i+b.first, j+b.second, k, l); });
    
    for (const auto &e : dir)
        aStarSearch(matrix, path, i+e.first, j+e.second, k, l, cost+1, trav);
}

int main()
{
    int m, n, i, j, k, l;
    cin >> m >> n;
    cin >> i >> j;
    cin >> k >> l;

    vector<vector<int>> grid(m, vector<int>(n));

    for (auto &r : grid)
        for (auto &e : r)
            cin >> e;
    vector<pair<int, int>> path;

    aStarSearch(grid, path, i, j, k, l);

    for (const auto &e : path)
        cout << '(' << e.first << ',' << e.second << ')' << ' ';
    cout << endl;
}