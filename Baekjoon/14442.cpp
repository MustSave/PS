#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool grid[1000][1000] = { false, };
int visited[1000][1000]; // 각 좌표에서 남은 canBreak 최대값을 저장합니다.
int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

struct Element
{
    int x;
    int y;
    int canBreak;
    int step;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numRows, numCols, k;
    cin >> numRows >> numCols >> k;

    // 입력: 각 행의 문자열을 읽어 grid에 저장합니다.
    for (int i = 0; i < numRows; ++i)
    {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < numCols; ++j)
        {
            grid[i][j] = (rowStr[j] == '1');
        }
    }

    // visited 배열을 -1로 초기화합니다.
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            visited[i][j] = -1;
        }
    }

    queue<Element> q;
    // 시작점 (0,0)에서 k번 벽을 부술 수 있고, 초기 step은 0입니다.
    q.push({0, 0, k, 1});
    visited[0][0] = k;

    int answer = -1;
    while (!q.empty())
    {
        Element el = q.front();
        q.pop();

        // 목표 위치: (numRows-1, numCols-1)
        if (el.x == numRows - 1 && el.y == numCols - 1)
        {
            answer = el.step;
            break;
        }

        // 상하좌우 4방향 탐색
        for (int i = 0; i < 4; ++i)
        {
            int nx = el.x + dir[i][0];
            int ny = el.y + dir[i][1];

            if (nx < 0 || nx >= numRows || ny < 0 || ny >= numCols)
                continue;

            int newCanBreak = el.canBreak;
            // 벽인 경우 벽을 부술 수 있으면 canBreak를 감소시킵니다.
            if (grid[nx][ny])
            {
                if (newCanBreak > 0)
                {
                    newCanBreak--;
                }
                else
                {
                    continue;
                }
            }
            // 이미 이 위치를 더 많은 남은 벽 부수기 기회(newCanBreak보다 큰 값)로 방문한 경우 건너뜁니다.
            if (visited[nx][ny] >= newCanBreak)
                continue;

            visited[nx][ny] = newCanBreak;
            q.push({nx, ny, newCanBreak, el.step + 1});
        }
    }

    cout << answer;
    return 0;
}
