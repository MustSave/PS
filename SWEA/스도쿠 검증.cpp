#include <iostream>
#include <string.h>

using namespace std;

int sudoku[9][9];
bool occured[10];

bool validateRow(int r) {
    memset(occured, 0, sizeof(bool) * 10);
    for (int c = 0; c < 9; c++) {
        if (occured[sudoku[r][c]]) return false;
        occured[sudoku[r][c]] = true;
    }
    return true;
}

bool validateAllRow() {
    for (int r = 0; r < 9; r++)
        if (!validateRow(r)) return false;
    return true;
}

bool validateCol(int c) {
    memset(occured, 0, sizeof(bool) * 10);
    for (int r = 0; r < 9; r++) {
        if (occured[sudoku[r][c]]) return false;
        occured[sudoku[r][c]] = true;
    }
    return true;
}

bool validateAllCol() {
    for (int c = 0; c < 9; c++) 
        if (!validateCol(c)) return false;
    return true;
}

bool validate3by3(int r, int c) {
    memset(occured, 0, sizeof(bool) * 10);
    for (int dr = 0; dr < 3; dr++) {
        for (int dc = 0; dc < 3; dc++) {
            int nr = r + dr, nc = c + dc;
            if (occured[sudoku[nr][nc]]) return false;
            occured[sudoku[nr][nc]] = true;
        }
    }
    return true;
}

bool validateAll3by3() {
    for (int r = 0; r < 9; r+=3)
        for (int c = 0; c < 9; c+=3) 
            if (!validate3by3(r, c)) return false;
    return true;
}

void fillSudoku() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> sudoku[i][j];
}

int validateSudoku() {
    if (validateAllRow() && validateAllCol() && validateAll3by3()) return 1;
    return 0;
}

void solve(int t) {
    fillSudoku();
    cout << '#' << t << ' ' << validateSudoku() << '\n';
}

int main() {
    int tc;
    cin >> tc;
    cin.tie(0);cout.tie(0);
    for (int t = 0; t < tc; t++) {
        solve(t+1);
    }
}