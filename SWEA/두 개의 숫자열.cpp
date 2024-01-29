#include <iostream>
#include <vector>
using namespace std;

vector<int>& initVector(vector<int>& v, int n) {
    v.clear();
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    return v;
}

void solve(int t) {
    vector<int> a, b;
    int na, nb, ans = 0;
    cin >> na >> nb;

    auto &va = initVector(a, na);
    auto &vb = initVector(b, nb);

    if (na > nb) {
        swap(va, vb);
        swap(na, nb);
    }

    for (int i = 0; i < nb - na + 1; ++i) {
        int res = 0;
        for (int j = 0; j < na; ++j) {
            res += va[j] * vb[i + j];
        }
        ans = max(ans, res);
    }

    cout << '#' << t + 1 << ' ' << ans << '\n';
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        solve(t);
    }
}