#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N, M;
vector<int> nums;
vector<int> stack;
bool checked[10000] = {false, };

void printStack() {
    stringstream ss;
    for (const auto& n: stack) {
        ss << n << " ";
    }
    printf("%s\n", ss.str().c_str());
}

void dfs(int step) {
    if (step == M) {
        printStack();
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (checked[i] || prev == nums[i]) continue;
        checked[i] = true;
        stack.push_back(nums[i]);
        prev = nums[i];
        dfs(step + 1);
        stack.pop_back();
        checked[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());

    dfs(0);
    return 0;
}