#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    ll liquid[100000];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }

    int s = 0;
    int e = N-1;

    ll nearZero = 1e10;
    pair<int,int> ans = {s, e};
    while (s < e) {
        ll comb = liquid[s] + liquid[e];
        ll absComb = abs(comb);
        if (absComb < nearZero) {
            nearZero = absComb;
            ans = {s, e};
            if (comb == 0) break;
        }

        if (comb < 0) {
            s++;
        } else {
            e--;
        }
    }

    cout << liquid[ans.first] << " " << liquid[ans.second];
}