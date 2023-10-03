#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최소 한개의 (a, e, i, o, u)
// 최소 두 개의 그 외
// 오름차순

int l, c;
char candidate[15] = {0, };

bool checkValidCandidate(vector<char>& comb) {
    bool a = false, b = false;
    int bCnt = 0;
    for (int i = 0; i < l; i++) {
        if (comb[i] == 'a' || comb[i] == 'e' || comb[i] == 'i' || comb[i] == 'o' || comb[i] == 'u') {
            a = true;
        } else if (++bCnt >= 2) {
            b = true;
        }
        if (a && b) return true;
    }
    return false;
}

void getInput() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> candidate[i];
    }
}

vector<char> ans;

void dfs(int step, int prev) {
    if (step == l) {
        if (checkValidCandidate(ans)) {
            for (int i = 0; i < l; i++) {
                cout << ans[i];
            }
            cout << '\n';
        }
        return;
    }

    int tmp = c - l + step + 1;
    for (int i = prev + 1; i < tmp; i++) {
        ans.push_back(candidate[i]);
        dfs(step + 1, i);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getInput();
    sort(candidate, candidate+c, [](char a, char b) { return a < b; });

    dfs(0, -1);
}