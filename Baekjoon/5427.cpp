#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, w, h;
char map[1001][1001];
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

void bfs() {
    cin >> w >> h;
    queue<pair<int,int>> fireCoord, humanCoord;

    for (int i = 0; i < h; i++) {
        cin >> map[i];
        for (int j = 0; j < w; j++) {
            if (map[i][j] == '*') {
                fireCoord.push({i, j});
            } else if (map[i][j] == '@') {
                humanCoord.push({i, j});
            }
        }
    }

    int time = 0;
    while (!fireCoord.empty() || !humanCoord.empty()) {
        time++;
        int fireSize = fireCoord.size();
        for (int i = 0; i < fireSize; i++) {
            const auto [fx, fy] = fireCoord.front();
            fireCoord.pop();

            for (const auto [dx, dy]: dir) {
                int nx = fx + dx;
                int ny = fy + dy;

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

                if (map[nx][ny] == '.' || map[nx][ny] == '@') {
                    fireCoord.push({nx, ny});
                    map[nx][ny] = '*';
                }
            }
        }

        int humanSize = humanCoord.size();
        for (int i = 0; i < humanSize; i++) {
            const auto [hx, hy] = humanCoord.front();
            humanCoord.pop();

            if (hx == 0 || hy == 0 || hx == h - 1 || hy == w - 1) {
                cout << time << "\n";
                return;
            }

            for (const auto [dx, dy]: dir) {
                int nx = hx + dx;
                int ny = hy + dy;

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

                if (map[nx][ny] == '.') {
                    if (nx == 0 || ny == 0 || nx == h -1 || ny == w -1) {
                        cout << time + 1 << "\n";
                        return;
                    }
                    humanCoord.push({nx, ny});
                    map[nx][ny] = '@';
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        bfs();
    }
}