#include <string>
#include <vector>

using namespace std;

// W > H
int solution(vector<vector<int>> sizes) {
    int maxW = 0;
    int maxH = 0;
    for (const auto& siz: sizes) {
        maxW = max(maxW, max(siz[0], siz[1]));
        maxH = max(maxH, min(siz[0], siz[1]));
    }

    return maxW * maxH;
}