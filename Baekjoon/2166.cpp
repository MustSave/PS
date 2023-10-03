#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    pair<long double,long double> coord[10001];
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%Lf %Lf", &coord[i].first, &coord[i].second);
    }
    coord[N] = {coord[0].first, coord[0].second};

    long double ans = 0;
    for (int i = 0; i < N; i++) {
        ans += coord[i].first * coord[i + 1].second - coord[i].second * coord[i+1].first;
    }

    ans = abs(ans);
    printf("%.1Lf", ans / (double)2);
}