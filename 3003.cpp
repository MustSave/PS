#include <stdio.h>

int main() {
    int ans[] = {1, 1, 2, 2, 2, 8};
    int input[6];

    for (int i = 0; i < 6; i++) {
        scanf("%d", &input[i]);
        printf("%d ", ans[i] - input[i]);
    }
}