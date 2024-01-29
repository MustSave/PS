// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <iostream>

// using namespace std;

// unordered_map<int, pair<unordered_set<int>, unordered_set<int>>> map;

// void test(vector<int>& order, int knownPlayer) {
//     auto& [win, lose] = map[knownPlayer];
//     for (auto& player: win) {
//         unordered_set<int> winDiffSet;
//         set_difference(map[player].first.begin(), map[player].first.end(), lose.begin(), lose.end(), inserter(winDiffSet, winDiffSet.begin()));
//         unordered_set<int> loseDiffSet;
//         set_difference(map[player].second.begin(), map[player].second.end(), lose.begin(), lose.end(), inserter(loseDiffSet, loseDiffSet.begin()));

        
//     }
// }

// int solution(int n, vector<vector<int>> results) {
//     int answer = 0;
//     vector<int> order(n+1, 0);

//     for (const auto& result: results) {
//         map[result[0]].first.insert(result[1]);
//         map[result[1]].second.insert(result[0]);
//     }

//     for (const auto& m: map) {
//         if (m.second.first.size() + m.second.second.size() == n - 1) {
//             order[m.first] = m.second.second.size() + 1;
//             cout << "ORDER OF PLAYER " << m.first << " IS " << order[m.first] << endl;
//         }
//     }

//     return answer;
// }
