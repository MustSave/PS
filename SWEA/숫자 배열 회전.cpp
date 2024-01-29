#include <iostream>
#include <vector>
using namespace std;
#define vvi vector<vector<int>>

void printRow(vvi& v, int r) {
    int N = v.size();
    for (int i = 0; i < N; ++i) {
        cout << v[r][i];
    }
}

void print(int t, vvi& a, vvi& b, vvi& c) {
    int N = a.size();
    cout << '#' << t << '\n';
    for (int x = 0; x < N; ++x) {
        printRow(a, x);
        cout << ' ';
        printRow(b, x);
        cout << ' ';
        printRow(c, x);
        cout << '\n';
    }
}

vvi& rotate90(vvi& matrix, vvi& res) {
    int N = matrix.size();
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            res[y][N-x-1] = matrix[x][y];
        }
    }
    return res;
}

void _print(vvi& v) {
    cout << "============================================================" << endl;
    for (const auto& x: v) {
        for (const auto& y: x) {
            cout << y << ' ';
        }
        cout << endl;
    }
    cout << "============================================================" << endl;
}

void init(vvi& v, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
}

void solve(int t) {
    int n;
    cin >> n;

    vvi matrix(n, vector<int>(n, 0));
    vvi rot90(n, vector<int>(n, 0));
    vvi rot180(n, vector<int>(n, 0));
    vvi rot270(n, vector<int>(n, 0));
    init(matrix, n);

    // _print(matrix);
    rotate90(matrix, rot90);
    //  _print(rot90);
    rotate90(rot90, rot180);
    //  _print(rot180);
    rotate90(rot180, rot270);
    //  _print(rot270);

    print(t, rot90, rot180, rot270);
}

int main() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        solve(i+1);
    }
}