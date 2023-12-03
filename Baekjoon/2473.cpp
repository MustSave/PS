#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> liquid;

void getInput() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        liquid.push_back(tmp);
    }
}

vector<int> solve () {
    long nearZero = 9999999999;
    vector<int> answer(3, 0);

    for (int i = 0; i < liquid.size(); i++) {
        int l = i + 1;
        int r = liquid.size() - 1;

        while (l < r) {
            long sum = (long)liquid[i] + (long)liquid[l] + (long)liquid[r];
            long absSum = abs(sum);
            if (absSum < nearZero) {
                nearZero = absSum;
                answer[0] = liquid[i]; answer[1] = liquid[l]; answer[2] = liquid[r];
                if (absSum == 0) return answer;
            }

            if (sum > 0) {
                r -= 1;
            } else if (sum < 0) {
                l += 1;
            }
        }
    }

    return answer;
}

int main() {
    getInput();
    sort(liquid.begin(), liquid.end());
    
    auto answer = solve();

    cout << answer[0] << " " << answer[1] << " " << answer[2];
}