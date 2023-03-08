#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int prev[] = {1,2,0};
    for (int i = 2; i < N; i++) {
        prev[2] = (prev[0] + prev[1]) % 15746;
        prev[0] = prev[1];
        prev[1] = prev[2];
    }

    printf("%d", N > 2 ? prev[2] : N == 2 ? 2 : 1);
}