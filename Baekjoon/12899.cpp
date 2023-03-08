#include <stdio.h>
int segment_tree[4194304] = {0, };

void update(int treeIdx, int queryStart, int queryEnd, int arrayIdx) {
    if (queryStart==queryEnd) {
        segment_tree[treeIdx] += 1;
        return;
    }

    int mid = (queryStart+queryEnd)>>1;
    segment_tree[treeIdx] += 1;

    if (mid >= arrayIdx)
        update(treeIdx<<1, queryStart, mid, arrayIdx);
    else
        update((treeIdx<<1)+1, mid+1, queryEnd, arrayIdx);
    return;
}

int remove(int treeIdx, int queryStart, int queryEnd, int n) {
    if (queryStart==queryEnd) {
        segment_tree[treeIdx] -= 1;
        return queryStart;
    }

    int mid = (queryStart+queryEnd)>>1;
    segment_tree[treeIdx] -= 1;
    int left = treeIdx<<1;

    if (segment_tree[left] >= n)
        return remove(left, queryStart, mid, n);
    else
        return remove(left+1, mid+1, queryEnd, n-segment_tree[left]);
}

int main() {
    int M = 2000001;
    int N, T, X;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &T, &X);

        if (T==1) {
            update(1, 0, M-1, X);
        } else {
            printf("%d\n", remove(1, 0, M-1, X));
        }
    }
}