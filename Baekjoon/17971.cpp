#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int N, K;
vector<vector<int>> visitedTime(2, std::vector<int>(500001, (1<<31) - 1));
int brother[500001] = {-1, };

int moveSubin(int pos, int type) {
    switch (type) {
        case 0:
            if (pos == 0) return -1;
            pos -= 1;
            break;
        case 1:
            if (pos == 500000) return -1;
            pos += 1;
            break;
        case 2:
            if (pos > 250000) return -1;
            pos *= 2;
            break;
    }
    return pos;
}

int bfs() {
    queue<pair<int,int>> queue;
    queue.push({N, 0});

    visitedTime[0][N] = 0;
    brother[K] = 0;

    while(!queue.empty()) {
        auto& [x,t] = queue.front(); queue.pop();

        for (int i = 0; i < 3; i++) {
            int nx = moveSubin(x, i);

            if (nx == -1 || visitedTime[(t + 1) % 2][nx] <= t + 1) continue;
            visitedTime[(t+1) % 2][nx] = t + 1;

            queue.push({nx, t + 1});
        }
    }


    // int t = 0;
    // while (K <= 500000) {
    //     if (visitedTime[brother[K] % 2][K] <= brother[K]) return brother[K];
    //     K += ++t;
    //     if (K <= 500000)
    //         brother[K] = t;
    // }


    return -1;
}

int main() {
    cin >> N >> K;
    cout << bfs();
}