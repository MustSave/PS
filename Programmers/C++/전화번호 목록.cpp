#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s;
    for (const auto& phone: phone_book) {
        if (s.find(phone) != s.end()) return false;
        
        for (int i = 1; i < phone.size(); i++) {
            s.insert(phone.substr(0, i));
        }
    }
    
    for (const auto& phone: phone_book) {
        if (s.find(phone) != s.end()) return false;
    }
    
    return true;
}