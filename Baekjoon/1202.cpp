#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    pair<int,int> jewelry[300000];
    int backpack[300000];

    
    for (int i = 0; i < n; i++) {
        cin >> jewelry[i].first >> jewelry[i].second;
    }

    for (int i = 0; i < k; i++) {
        cin >> backpack[i];
    }

    sort(jewelry, jewelry + n);
    sort(backpack, backpack + k);


    int jewerlyIdx = 0;
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        int bagWeight = backpack[i];
        while (jewerlyIdx < n && jewelry[jewerlyIdx].first <= bagWeight) {
            pq.push(jewelry[jewerlyIdx++].second);
        }

        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
}