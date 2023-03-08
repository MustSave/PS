#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int N, K;
int sum = 0;
int newN;

int solve(int* segmentTree, int startIdx) {
    int node = newN+startIdx;
    int target = K % sum;
    if (target==0) target = sum;

    int count = 0;
    while (node && count + segmentTree[node] < target) {
        if ((node&1)) {
            count += segmentTree[node];
            node++;
        }
        node >>= 1;
    }
    target -= count;
    while (node < newN) {
        node = node << 1;
        if (segmentTree[node] < target) {
            target -= segmentTree[node];
            node++;
        }
    }

    int ret = node - newN +1;
    while (node) {
        segmentTree[node]--;
        node >>= 1;
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    newN = (int)pow(2, (int)ceil(log2(N)));
    int* segmentTree = (int*)calloc(sizeof(int), newN<<1);
    for (int i = 0; i < N; i++) 
        segmentTree[newN+i] = 1;
    for (int i = newN-1; i > 0; i--){
        int tmp = i << 1;
        segmentTree[i] = segmentTree[tmp] + segmentTree[tmp+1];
    }
    
    int start = 0;
    printf("<");
    for (sum=N;sum > 0; sum--){
        start = solve(segmentTree, start);
        printf("%d", start);
        start %= N;
        if (sum > 1)
            printf(", ");
    }
    printf(">");
}