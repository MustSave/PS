#include <stdio.h>

void swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    int B[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (A[j] < A[j+1]) swap(A[j], A[j+1]);

            if (B[j] > B[j+1]) swap(B[j], B[j+1]);
        }
    }

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += A[i]*B[i];
    }
    printf("%d", tmp);
}