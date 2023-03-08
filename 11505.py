import sys;input=sys.stdin.readline;
from math import log2, ceil
MOD = 1000000007
N, M, K = map(int, input().split())
arr = [1] * (N+1)
for i in range(1, N+1):
    arr[i] = int(input())

# leafnode 수 = N개
tree_length = 2**(ceil(log2(N))+1)
segment_tree = [1] * tree_length

def build_tree(tree_idx, query_start, query_end):
    if query_start==query_end:
        segment_tree[tree_idx] = arr[query_start]
        return arr[query_start]
    
    mid = (query_start+query_end)//2
    left = build_tree(tree_idx*2, query_start, mid)
    right = build_tree(tree_idx*2+1, mid+1, query_end)
    val = (left * right) % MOD
    segment_tree[tree_idx] = val
    return val
def update_tree(tree_idx, query_start, query_end, arr_idx, value):
    if query_start==query_end:
        segment_tree[tree_idx] = value
        return value
    
    mid = (query_start+query_end)//2
    if arr_idx <= mid:
        val = segment_tree[tree_idx*2+1] * update_tree(tree_idx*2, query_start, mid, arr_idx, value)
    else:
        val = segment_tree[tree_idx*2] * update_tree(tree_idx*2+1, mid+1, query_end, arr_idx, value)
    segment_tree[tree_idx] = val % MOD
    return segment_tree[tree_idx]
def prefix_mul(tree_idx, query_start, query_end, target_start, target_end):
    if query_start > target_end or query_end < target_start:
        return 1

    if target_start <= query_start and query_end <= target_end:
        return segment_tree[tree_idx]
    else:
        mid = (query_start+query_end)//2
        val = prefix_mul(tree_idx*2, query_start, mid, target_start, target_end) * prefix_mul(tree_idx*2+1, mid+1, query_end, target_start, target_end)
        return val % MOD


build_tree(1, 1, N)
print(segment_tree)
if __name__=='__main__':
    for _ in range(M+K):
        a, b, c = map(int, input().split())
        if a == 1: # 변경
            update_tree(1, 1, N, b, c)
        else: # 구간합
            print(prefix_mul(1, 1, N, b, c))