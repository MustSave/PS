#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// N x N R=G
int N;
char picture[100][101];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int area[2] = {0,0};

void bfs(pair<int,int> coord, int type) {
    queue<pair<int, int>> queue;
    char target = picture[coord.first][coord.second];
    queue.push(coord);

    while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop();

        if (picture[x][y] != target) continue;
        if (type == 0) {
            picture[x][y] = target == 'B' ? 'b' : 'r';
        } else {
            picture[x][y] = target == 'b' ? 'O' : 'X';
        }

        for (auto& [dx, dy] : dir) {
            int nx = x + dx;
            int ny = y + dy;

            // Index out of range, 적녹색약
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || picture[nx][ny] != target) continue;

            queue.push(make_pair(nx, ny));
        }
    }

    area[type]++;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> picture[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (picture[i][j] >= 'a') continue;

            bfs(make_pair(i, j), 0);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (picture[i][j] < 'a') continue;

            bfs(make_pair(i, j), 1);
        }
    }

    cout << area[0] << " " << area[1];
}