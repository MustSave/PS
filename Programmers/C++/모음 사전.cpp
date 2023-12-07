#include <string>

using namespace std;

string dict = "AEIOU";
int acc[] = {1, 6, 31, 156, 781};

int solution(string word) {
    int answer = 0;
    for (int i = 0; i < word.size(); ++i) 
        answer += acc[4-i] * dict.find(word[i]) + 1;
    return answer;
}