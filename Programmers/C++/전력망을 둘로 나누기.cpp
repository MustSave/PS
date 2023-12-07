#include <string>
#include <vector>

using namespace std;

int answer = 987654321;

struct node {
    vector<int> nodes;
};

int dfs(int n, vector<vector<int>>& nodes, vector<bool>& visited, int node) {
    int allChildCount = 1;

    for (const auto& nd: nodes[node]) {
        if (visited[nd]) continue;

        visited[nd] = true;
        int childCount = dfs(n, nodes, visited, nd);
        allChildCount += childCount;
        answer = min(answer, abs(n - childCount * 2));
    }

    return allChildCount;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> nodes(n+1);
    vector<bool> visited(n+1, false);

    for (const auto& wire: wires) {
        nodes[wire[0]].push_back(wire[1]);
        nodes[wire[1]].push_back(wire[0]);
    }

    dfs(n, nodes, visited, wires[0][0]);
    return answer;
}