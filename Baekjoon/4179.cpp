#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> map;
queue<pair<int, int>> personCoords, fireCoords;

int dir[4][2] = {{0,1}, {1,0},{0,-1},{-1,0}};

bool fireContinueCondition(int x, int y) {
    return map[x][y] == '#' || map[x][y] == 'F';
}

bool personContinueCondition(int x, int y) {
    return map[x][y] != '.';
}

void fireMove() {
    queue<pair<int, int>> tmp;
    bool start = true;
    while (!fireCoords.empty()) {
        auto [x, y] = fireCoords.front();
        fireCoords.pop();

        map[x][y] = 'F';

        for (auto& [dx, dy] : dir) {
            int nx = x+dx;
            int ny = y+dy;

            if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map[0].size() || fireContinueCondition(nx, ny)) continue;

            map[nx][ny] = 'F';
            tmp.push(make_pair(nx, ny));
        }
    }

    fireCoords = tmp;
}

bool personMove() {
    queue<pair<int, int>> tmp;
    while (!personCoords.empty()) {
        auto [x, y] = personCoords.front();
        personCoords.pop();

        for (auto& [dx, dy] : dir) {
            int nx = x+dx;
            int ny = y+dy;

            if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map[0].size()) return true;
            if (personContinueCondition(nx, ny)) continue;
            
            map[nx][ny] = 'J';
            tmp.push(make_pair(nx, ny));
        }
    }

    personCoords = tmp;
    return false;
}

string bfs() {
    int time = 0;

    while (!personCoords.empty()) {
        time++;
        fireMove();
        if (personMove()) {
            return to_string(time);
        }
    }

    return "IMPOSSIBLE";
}

int main() {
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < C; j++) {
            if (input[j] == 'J') personCoords.push(make_pair(i, j));
            else if (input[j] == 'F') fireCoords.push(make_pair(i, j));
        }

        map.push_back(input);
    }

    cout << bfs();
}