#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int password[100000];

int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // n의 가장 낮은 비트가 1인지 확인
        n >>= 1; // 오른쪽으로 한 비트 시프트하여 다음 비트 검사 준비
    }
    return count;
}

int dist(int a, int b) {
    return countBits(a^b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> password[i];
    }

    sort(password, password + m);

    int answer = INT_MAX;

    for (int i = 1; i < m; i++) {
        answer = min(answer, dist(password[i-1], password[i]));
    }

    cout << answer;
    return 0;
}