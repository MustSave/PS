#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> counter;
    
    for (auto& part: participant) {
        counter[part]++;
    }

    for (auto& comp: completion) {
        auto& count = counter[comp];
        if (--count == 0) {
            counter.erase(comp);
        }
    }

    return counter.begin()->first;
}