#include <stdio.h>

int main() {
    int N;
    int res=0;

    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        res += getc(stdin) - '0';
    }
    printf("%d", res);
}