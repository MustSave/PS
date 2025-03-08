#include <vector>
#include <queue>

using namespace std;
vector<int> graph[20001];
int distances[20001];
bool visited[20001];
int ans[2] = {0, };
queue<int> q({1});

int solution(int n, vector<vector<int>> edge) {
    for (auto& vec: edge) {
        graph[vec[0]].push_back(vec[1]);
        graph[vec[1]].push_back(vec[0]);
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto targetNode: graph[node]) {
            if (visited[targetNode] || targetNode == 1) continue;
            q.push(targetNode);
            visited[targetNode] = true;
            distances[targetNode] = distances[node] + 1;
        }
    }
    
    for (int i = 1; i < n+1; i++) {
        if (distances[i] > ans[0]) {
            ans[0] = distances[i];
            ans[1] = 1;
        } else if (distances[i] == ans[0]) {
            ans[1]++;
        }
    }

    return ans[1];
}