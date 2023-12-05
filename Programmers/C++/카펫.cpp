#include <string>
#include <vector>

using namespace std;

int getYellowCollor(int w, int h) {
    return (w - 2) * (h - 2);
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int maxHeight = max(3, brown / 2);
    for (int h = 3; h <= maxHeight; ++h) {
        int w = brown / 2 - h + 2;
        if (h <= w && getYellowCollor(w, h) == yellow) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    
    return answer;
}