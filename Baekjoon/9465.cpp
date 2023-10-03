#include <stdio.h>
#include <vector>
using namespace std;

int T;
int stickers[2][100000];
int dp[2][100000] = {0, };

int main() {
    scanf("%d", &T);
    int l;
    
    for (int i = 0; i < T; i++) {
        scanf("%d", &l);
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < l; k++) {
                scanf("%d", &stickers[j][k]);
            }
        }

        dp[0][0] = stickers[0][0];
        dp[1][0] = stickers[1][0];

        for (int n = 1; n < l; n++) {
            dp[0][n] = max(dp[1][n-1], n > 1 ? dp[1][n-2] : 0) + stickers[0][n];
            dp[1][n] = max(dp[0][n-1], n > 1 ? dp[0][n-2] : 0) + stickers[1][n];
            // dp[2][n] = max(dp[0][n-1], dp[1][n-1]);
        }

        int mx = max(dp[0][l-1], dp[1][l-1]);
        // mx = max(mx, dp[2][l-1]);

        printf("%d\n", mx);
    }
}