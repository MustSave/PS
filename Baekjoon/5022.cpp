#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int coords[4][2];
bool visited[101][101];
pair<int,int> parent[101][101];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int imax = 1 << 30;

struct Coord {
    int x;
    int y;
    int dist;
};

void getInput() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < 4; i++) {
        cin >> coords[i][0] >> coords[i][1];
    }
}

int bfs(queue<Coord>& a, pair<int,int> dest) {
    while(!a.empty()) {
        auto [x, y, d] = a.front();
        a.pop();

        if (visited[x][y]) continue;
        if (x == dest.first && y == dest.second) {
            return d;
        }
        visited[x][y] = true;

        for (const auto& [dx, dy]: dir) {
            int nx = x + dx, ny = y + dy;

            if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
            if (visited[nx][ny]) continue;

            a.push({nx, ny, d + 1});
            parent[nx][ny] = {x, y};
        }
    }

    return imax;
}

int solve(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    visited[x3][y3] = true;
    visited[x4][y4] = true;

    queue<Coord> a;
    a.push({x1, y1, 0});

    int dist = bfs(a, {x2, y2});

    memset(visited, 0, sizeof(visited));
    int x = x2, y = y2;
    while (x != -1) {
        visited[x][y] = true;
        auto& [a, b] = parent[x][y];
        x = a;
        y = b;
    }

    queue<Coord> b;
    b.push({x3, y3});
    int tmp = bfs(b, {x4, y4});

    return tmp == imax ? imax : dist + tmp;
}

int main() {
    getInput();

    vector<pair<int, int>> a, b;
    int shortestIsA = solve(coords[0][0], coords[0][1], coords[1][0], coords[1][1], coords[2][0], coords[2][1], coords[3][0], coords[3][1]);
    int shortestIsB = solve(coords[2][0], coords[2][1], coords[3][0], coords[3][1], coords[0][0], coords[0][1], coords[1][0], coords[1][1]);

    int ans = min(shortestIsA, shortestIsB);

    cout << (ans == imax ? "IMPOSSIBLE" : to_string(ans));
}