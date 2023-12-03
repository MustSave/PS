#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0;

void dfs(vector<int>& numbers, int target, int start, int current) {
    if (start == numbers.size()) {
        if (current == target) ans++;
        return;
    }
    
    dfs(numbers, target, start + 1, current + numbers[start]);
    dfs(numbers, target, start + 1, current - numbers[start]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return ans;
}