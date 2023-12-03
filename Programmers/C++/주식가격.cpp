#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<pair<int,int>> stack;
    int len = prices.size() - 1;
    
    for (int i = 0; i < prices.size(); i++) {
        while (!stack.empty() && stack.back().second > prices[i]) {
            auto tmp = stack.back();
            stack.pop_back();
            answer[tmp.first] = i - tmp.first;
        }
        stack.push_back({i, prices[i]});
    }

    while (!stack.empty()) {
        auto tmp = stack.back();
        answer[tmp.first] = len - tmp.first;
        stack.pop_back();
    }
    
    return answer;
}