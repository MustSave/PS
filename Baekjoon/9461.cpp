#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int max = 0;
    unsigned long long res[101] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
    
    scanf("%d", &N);
    int* input = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
        if (input[i] > max) max = input[i];
    }

    for (int i = 10; i < max; i++) {
        res[i] = res[i-1] + res[i-5];
    }

    for (int i = 0; i < N; i++) {
        printf(i != N-1? "%llu\n" : "%llu", res[input[i]-1]);
    }

    free(input);
}