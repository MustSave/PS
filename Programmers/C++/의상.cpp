#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    for (const auto& cloth: clothes) {
        map[cloth[1]]++;
    }
    
    for (const auto& m: map) {
        answer *= m.second + 1;
    }
    return answer - 1; // 모든 경우의 수 - 하나도 안입은 경우
}