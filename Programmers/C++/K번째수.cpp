#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (const auto& command: commands) {
        auto start = array.begin() + command[0] - 1;
        auto end = array.begin() + command[1];
        vector<int> subarr(start, end);
        sort(subarr.begin(), subarr.end());
        answer.push_back(subarr[command[2] - 1]);
    }
    return answer;
}