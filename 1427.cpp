#include <stdio.h>

int main()
{
    char N[11];
    int a[10] = {0, };
    int n = 0;
    scanf("%s", N);

    while(N[n]) {
        a[(int)(N[n]-'0')]++;
        n++;
    }
    
    for (int i = 9; i > -1; i--) {
        while(a[i]--){
            printf("%d",i);
        }
    }
    
    return 0;
}