#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isTargetInWords(string target, vector<string> words) {
    for (const auto& word: words) {
        if (word == target) return true;
    }
    return false;
}

int getDiffCharCount(string a, string b) {
    if (a.size() != b.size()) return -1;
    int count = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) count++;
    }
    
    return count;
}

int solution(string begin, string target, vector<string> words) {
    if (isTargetInWords(target, words) == false) return 0;
    bool checked[50] = {false, };
    queue<string> q;
    q.push(begin);
    int step = 0;
    while(!q.empty()) {
        step++;
        int queueSize = q.size();
        
        for (int i = 0; i < queueSize; i++) {
            auto& str = q.front();
            q.pop();

            for (int i = 0; i < words.size(); i++) {
                auto word = words[i];
                if (checked[i]) continue;
                if (getDiffCharCount(str, word) == 1) {
                    if (word == target) return step;
                    q.push(word);
                    checked[i] = true;
                }
            }
        }
    }
    
    return 0;
}