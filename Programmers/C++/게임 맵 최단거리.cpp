#include<vector>
#include<queue>
using namespace std;

// 0: 벽, 1: 벽 없음, (0, 0) 시작
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int solve(vector<vector<int>> maps) {
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    q.push({0, 0});

    int step = 0;
    while(!q.empty()) {
        step++;
        int queueSize = q.size();

        for (int i = 0; i < queueSize; i++) {
            const auto& [x, y] = q.front();
            q.pop();

            if (visited[x][y]) continue;
            if (x == maps.size() - 1 && y == maps[0].size() - 1) {
                return step;
            }
            visited[x][y] = true;

            for (const auto& [dx, dy]: dir) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size() || visited[nx][ny] || maps[x][y] == 0) continue;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return solve(maps);
}