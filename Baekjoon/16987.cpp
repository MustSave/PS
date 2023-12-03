#include <iostream>
#include <vector>

using namespace std;
// 상대 계란의 무게만큰 내구도 감소
int n;
int eggs[8][2];
int ans;

void getInput() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> eggs[i][0] >> eggs[i][1];
    }
}

int crash(int egg1[2], int egg2[2]) {
    int cracked = 0;
    egg1[0] -= egg2[1];
    egg2[0] -= egg1[1];
    if (egg1[0] <= 0) cracked++;
    if (egg2[0] <= 0) cracked++;
    return cracked;
}

void rollback(int egg1[2], int egg2[2]) {
    egg1[0] += egg2[1];
    egg2[0] += egg1[1];
}

void dfs(int step, int crackedCount) {
    if (step == n) {
        ans = max(ans, crackedCount);
        // cout << "crackedCount: " << crackedCount << "\n";
        return;
    }

    if (eggs[step][0] <= 0) {
        // cout << "cracked egg at step " << step << endl;
        dfs(step + 1, crackedCount);
    }

    else {
        for (int i = 0; i < n; i++) {
            if (i == step || eggs[i][0] <= 0) continue;

            int cracked = crash(eggs[step], eggs[i]);
            // cout << "egg" << step << " vs egg" << i << " : " << cracked << "cracked at step " << step << endl; 
            dfs(step + 1, crackedCount + cracked);
            rollback(eggs[step], eggs[i]);
        }
    }

    ans = max(ans, crackedCount);
}

int main() {
    getInput();
    dfs(0, 0);
    cout << ans;
}