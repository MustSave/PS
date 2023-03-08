import sys;input=sys.stdin.readline;
M = 2000001
N = int(input())
tree_length = 1
while tree_length < M:
    tree_length <<= 1
tree_length<<=1
segment_tree = [0 for _ in range(tree_length)]
def update(tree_idx, query_start, query_end, array_idx):
    if query_start==query_end:
        segment_tree[tree_idx] += 1
        return 

    mid = (query_start+query_end)//2
    segment_tree[tree_idx] += 1
    if mid >= array_idx:
        update(tree_idx<<1, query_start, mid, array_idx)
    else:
        update((tree_idx<<1)+1, mid+1, query_end, array_idx)

def remove(tree_idx, query_start, query_end, n):
    global number
    if query_start==query_end:
        segment_tree[tree_idx] -= 1
        number = query_start
        return

    mid = (query_start+query_end)//2
    segment_tree[tree_idx] -= 1
    left = tree_idx<<1
    if segment_tree[left] >= n:
        remove(left, query_start, mid, n)
    else:
        remove(left+1, mid+1, query_end, n-segment_tree[left])
    return

for _ in range(N):
    T, X = map(int, input().split())

    if T == 1: # X 추가
        update(1, 0, M-1, X)
    else: # X번째로 작은 수 삭제
        number = 0
        remove(1, 0, M-1, X)
        print(number)