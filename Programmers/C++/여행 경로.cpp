#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    map<string, multiset<string>> graph;
    for (const auto& ticket: tickets) {
        graph[ticket[0]].insert(ticket[1]);
    }

    vector<string> answer;
    stack<string> dfsStack;
    dfsStack.push("ICN");

    while (!dfsStack.empty()) {
        auto topAirport = dfsStack.top();
        if (graph[topAirport].empty()) {
            // No outgoing edge means we visited all nodes starting from this airport.
            // We should start backtracking.
            answer.push_back(topAirport);
            dfsStack.pop();
        } else {
            // There are still some nodes that we can visit from this airport.
            // Choose the next airport and push it to the stack.
            dfsStack.push(*graph[topAirport].begin());
            graph[topAirport].erase(graph[topAirport].begin());
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}
