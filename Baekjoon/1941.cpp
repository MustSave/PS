#include<iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

char classroom[5][6];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int ans = 0;

void getInput() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 5; i++) {
        cin >> classroom[i];
    }
}

pair<int,int> getCoord(int order) {
    return make_pair(order/5, order%5);
}

bool checkAdj(int bitmask) {
    vector<vector<int>> visited(5, vector<int>(5, 0));
    pair<int,int> start;
    for (int i = 0; i < 25; i++) {
        if ((1<<i) & bitmask) {
            start = getCoord(i);
            auto [a, b] = start;
            visited[a][b] = 2;
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (visited[x][y] & 1) continue;
        visited[x][y] |= 1;
        if (++cnt == 7) return true;

        for (const auto [dx, dy]: dir) {
            int nx = x + dx, ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visited[nx][ny] == 2) q.push({nx, ny});
        }
    }

    return false;
}

void dfs(int step, int start, int S, int Y, int bitmask) {
    if (step == 7) {
        if (checkAdj(bitmask)) ans++;
        return;
    }

    for (int i = start; i < 19 + step; i++) {
        int newBitmask = bitmask | (1 << i);
        auto [x, y] = getCoord(i);
        if (classroom[x][y] == 'S') {
            dfs(step+1, i+1, S + 1, Y, newBitmask);
        } else if (Y < 3) {
            dfs(step+1, i+1, S, Y + 1, newBitmask);
        }
    }
}

int main() {
    getInput();

    dfs(0, 0, 0, 0, 0);

    cout << ans;
}