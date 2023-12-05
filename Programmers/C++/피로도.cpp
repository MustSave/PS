#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int dfs(vector<vector<int>>& dungeons, unordered_set<int>& order, int fatigue) {
    int result = order.size();
    
    for (int i = 0; i < dungeons.size(); ++i) {
        if (order.find(i) != order.end() || fatigue < dungeons[i][0]) continue;
        
        order.insert(i);
        result = max(result, dfs(dungeons, order, fatigue - dungeons[i][1]));
        order.erase(i);
    }

    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    unordered_set<int> order;
    return dfs(dungeons, order, k);
}