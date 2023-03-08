import sys;input=sys.stdin.readline;
N = int(input())
M = 2**21
segment_tree = [0] * (M<<1)
def update(n, diff):
    index = M+n-1
    segment_tree[index] += diff
    index //= 2
    while index:
        segment_tree[index] += diff
        index //= 2

def remove(n):
    idx = 1
    while idx < M:
        if segment_tree[idx<<1] >= n:
            idx <<= 1
        else:
            n -= segment_tree[idx<<1]
            idx = (idx<<1) + 1
    idx = idx - M + 1
    print(idx)
    update(idx, -1)
    

for _ in range(N):
    T, X = map(int, input().split())

    if T == 1: # X 추가
        update(X, 1)
    else: # X번째로 작은 수 삭제
        remove(X)