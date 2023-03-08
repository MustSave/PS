#include <stdio.h>

int main()
{
    int N;
    int a[10001] = {0, };
    scanf("%d", &N);

    int num;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        a[num]++;
    }

    for (int i = 0; i < 10001; i++) {
        while(a[i]--) printf("%d\n", i);
    }

    return 0;
}