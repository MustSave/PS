#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> s;
    s.reserve(numbers.size());
    for (auto& number: numbers) {
        s.push_back(to_string(number));
    }
    
    sort(s.begin(), s.end(), [](string& a, string& b) {
        auto ita = a.begin();
        auto itb = b.begin();
        
        for (int i = 0; i < a.size() + b.size(); i++) {
            if (ita == a.end()) ita = b.begin();
            if (itb == b.end()) itb = a.begin();
            
            if (*ita != *itb) {
                return *ita > *itb;
            }
            ita++; itb++;
        }
        return false;
    });
    
    if (s[0] == "0") return "0";

    string result;
    for (auto& n: s) {
        result.append(n);
    }
    return result;
}