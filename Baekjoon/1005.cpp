#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, k, w;

int getDp(vector<vector<int>>& edges, vector<int>& dp, vector<int>& ctime, int n) {
    int maxTime = 0;
    for (const auto node: edges[n]) {
        if (dp[node] == -1) {
            dp[node] = getDp(edges, dp, ctime, node);
        }
        maxTime = max(maxTime, dp[node]);
    }

    return maxTime + ctime[n];
}

void topologySort() {
    cin >> n >> k;
    vector<int> constructTime(n + 1, 0);

    for (int j = 0; j < n; j++) {
        cin >> constructTime[j + 1];
    }

    int x, y;
    vector<vector<int>> reverseEdges(n + 1);
    vector<int> inDegree(n + 1, 0);
    for (int j = 0; j < k; j++) {
        cin >> x >> y;
        inDegree[y]++;
        reverseEdges[y].push_back(x);
    }

    cin >> w;
    vector<int> dp(n+1, -1);
    for (int j = 1; j <= n; j++) {
        if (inDegree[j] == 0) dp[j] = constructTime[j];
    }

    cout << getDp(reverseEdges,  dp, constructTime, w) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        topologySort();
    }
}