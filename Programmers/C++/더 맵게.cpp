#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scovilles, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& scoville: scovilles) {
        pq.push(scoville);
    }

    while (pq.size() > 1 && pq.top() < K) {
        auto scoville = pq.top();
        pq.pop();
        auto scoville2 = pq.top();
        pq.pop();

        auto newScoville = scoville + scoville2 * 2;
        pq.push(newScoville);
        answer++;
    }
    
    return pq.top() >= K ? answer : -1;
}