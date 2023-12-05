#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> guess = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    int maxVal = -1;
    for (int i = 0; i < guess.size(); ++i) {
        int n = 0;
        int score = 0;
        auto& people = guess[i];
        for (const auto& ans: answers) {
            if (ans == people[n++ % people.size()]) {
                ++score;
            }
        }
        if (score >= maxVal) {
            if (score > maxVal) {
                maxVal = score;
                answer.clear();
            }
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}