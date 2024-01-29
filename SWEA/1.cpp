#include <iostream>
#include <vector>

using namespace std;
int mat[15][15];
int n, m;

int getKillCountCrossAt(int x, int y) {
    int sum = mat[x][y];
    for (int i = 1; i < m; i++) {
        if (x - i >= 0) sum += mat[x-i][y];
        if (x + i < n) sum += mat[x+i][y];
        if (y - i >= 0) sum += mat[x][y-i];
        if (y + i < n) sum += mat[x][y+i];
    }

    return sum;
}

int getKillCountXAt(int x, int y) {
    int sum = mat[x][y];
    for (int i = 1; i < m; i++) {
        if (x - i >= 0) {
            if (y - i >= 0) sum += mat[x-i][y-i];
            if (y + i < n) sum += mat[x-i][y+i];
        }
        if (x + i < n) {
            if (y - i >= 0) sum += mat[x+i][y-i];
            if (y + i < n) sum += mat[x+i][y+i];
        }
    }
    return sum;
}

int getMaxKillCountAt(int x, int y) {
    return max(getKillCountCrossAt(x, y), getKillCountXAt(x, y));
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
}

int solve() {
    init();
    int ans = 0;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            ans = max(ans, getMaxKillCountAt(x, y));
    return ans;
}

int main() {
    int tc;
    cin.tie(0); cout.tie(0);
    cin >> tc;
    for (int t = 0; t < tc; t++)
        cout << '#' << t+1 << ' ' << solve() << '\n';
}