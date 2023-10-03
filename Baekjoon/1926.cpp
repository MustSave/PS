// #include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs(vector<vector<int>>& row, pair<int, int> start)
{
    deque<pair<int, int>> queue;
    queue.push_back(start);
    int size = 0;

    while (!queue.empty())
    {
        auto [x, y] = queue.front();
        queue.pop_front();

        if (row[x][y] != 1) continue;
        row[x][y] = -1;
        size++;

        for (auto [dx, dy] : dir)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= row.size() || ny < 0 || ny >= row[0].size() || row[nx][ny] != 1)
                continue;

            queue.push_back(make_pair(nx, ny));
        }
    }

    return size;
}

int main()
{
    int n, m, totalNum = 0, maxSize = 0;
    // scanf("%d %d", &n, &m);
    cin >> n >> m;
    vector<vector<int>> row(n);
    string input;

    getline(cin,input); // 첫 번째 줄 버리기

    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        istringstream iss(input);

        int num;
        while (iss >> num)
        {
            row[i].push_back(num);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i][j] != 1)
                continue;

            maxSize = max(maxSize, bfs(row, make_pair(i, j)));
            totalNum++;
        }
    }

    cout << totalNum << endl << maxSize << endl;
}