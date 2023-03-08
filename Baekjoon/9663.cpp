#include <stdio.h>
#include <vector>
using namespace std;

vector<int> board(14, 0);
vector<bool> r(14, false);
int N, res = 0;

bool check(int row, int col) {
    int tmp = 1 << row;
    for (int i = 1; i <= col; i++) {
        if (board[col-i]==tmp | board[col-i]==(tmp<<i) | board[col-i]==(tmp>>i)) return false;
    }
    return true;
}

void dfs(int step) {
    if (step == N) {
        res++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (r[i]==false && check(i, step)) {
            board[step] = 1 << i;
            r[i] = true;
            dfs(step+1);
            r[i] = false;
        }
    }
}

int main() {
    scanf("%d", &N);
    dfs(0);
    printf("%d", res);
}