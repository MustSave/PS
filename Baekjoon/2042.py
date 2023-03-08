import sys;input=sys.stdin.readline;
from math import ceil, log2
def last_one_bit(n):
    return n & -n
def update(index, diff):
    while index < len(BIT):
        BIT[index] += diff
        index += last_one_bit(index)
def prefix_sum(index):
    ret = 0
    while index > 0:
        ret += BIT[index]
        index -= last_one_bit(index)
    return ret

N, M, K = map(int, input().split())

arr = [0] * (N+1)
for i in range(1, N+1):
    arr[i] = int(input())

BIT = [0] * (2**ceil(log2(N))+1)
for i in range(1, N+1):
    update(i, arr[i])

for _ in range(M+K):
    a, b, c = map(int, input().split())
    if a == 1: # 변경
        diff = c - arr[b]
        arr[b] = c
        update(b, diff)
    else: # 구간합
        print(prefix_sum(c) - prefix_sum(b-1))