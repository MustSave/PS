#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });
    int time = jobs[0][0];
    int opTime = 0;
    int reqTime = 0;
    int i = 0;
    while (i < jobs.size() || !pq.empty()) {
        while (i < jobs.size() && jobs[i][0] <= time) {
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
        }

        if (pq.empty() && i < jobs.size()) {
            opTime = jobs[i][1];
            reqTime = jobs[i][0];
            time = reqTime;
        } else if (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            opTime = tmp.first;
            reqTime = tmp.second;
            i--;
        }

        time += opTime;
        answer += time - reqTime;
        if (i < jobs.size()) i++;
    }

    return answer / jobs.size();
}