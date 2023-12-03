#include <string>
#include <vector>
#include <queue>

using namespace std;

int map[101][101] = {0, };
bool visited[101][101] = {false, };
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct item {
    int x;
    int y;
    int step;
};

bool isPointInSquare(vector<vector<int>> &rectangle, int x, int y) {
    for (const auto &rect : rectangle) {
        if ((rect[0] << 1) < x && x < (rect[2] << 1) && (rect[1] << 1) < y && y < (rect[3] << 1))
            return true;
    }
    return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (int i = 1; i <= rectangle.size(); i++) {
        auto rect = rectangle[i - 1];
        for (int x = (rect[0] << 1); x <= (rect[2] << 1); x++) {
            map[rect[1] << 1][x] = 1;
            map[rect[3] << 1][x] = 1;
        }

        for (int y = (rect[1] << 1) + 1; y < (rect[3] << 1); y++) {
            map[y][rect[0] << 1] = 1;
            map[y][rect[2] << 1] = 1;
        }
    }

    queue<item> q({{characterX << 1, characterY << 1, 0}});

    while (!q.empty()) {
        auto [x, y, step] = q.front();
        q.pop();

        if (visited[y][x]) continue;
        if (x == itemX << 1 && y == itemY << 1) return step;

        visited[y][x] = true;

        for (const auto& [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx > 100 || ny > 100 || map[ny][nx] == 0 || visited[ny][nx]) continue;
            if (isPointInSquare(rectangle, nx, ny)) continue;
            q.push({nx + dx, ny + dy, step + 1});
        }
    }

    return 0;
}