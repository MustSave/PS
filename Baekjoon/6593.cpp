#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dir[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
char building[31][31][31];
int l, r, c;

struct coord {
    int x;
    int y;
    int z;
};
coord startCoord, endCoord;

void getInput() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
            cin >> building[i][j];
            for (int k = 0; k < c; k++) {
                if (building[i][j][k] == 'S') {
                    startCoord = {i, j, k};
                    building[i][j][k] = '.';
                } else if (building[i][j][k] == 'E') {
                    endCoord = {i, j, k};
                }
            }
        }
    }
}

string solve() {
    getInput();

    queue<coord> q;
    q.push(startCoord);
    int time = 0;

    while (!q.empty()) {
        int queueSize = q.size();
        time++;
        for (int i = 0; i < queueSize; i++) {
            const auto [x, y, z] = q.front();
            q.pop();

            if (building[x][y][z] != '.') continue;
            building[x][y][z] = 'X';

            for (const auto [dx, dy, dz]: dir) {
                int nx = x + dx, ny = y + dy, nz = z + dz;

                if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;

                if (building[nx][ny][nz] == '.') {
                    q.push({nx, ny, nz});
                } else if (building[nx][ny][nz] == 'E') {
                    return "Escaped in " + to_string(time) + " minute(s).";
                }
            }
        }
    }

    return "Trapped!";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bool fin = false;
    while (true) {
        cin >> l >> r >> c;
        if (l == 0) break;
        cout << solve() << "\n";
    }
}