from math import ceil, log2
import sys;input=sys.stdin.readline;
N = int(input())
A = [*map(int, input().split())]
M = int(input())

N2 = pow(2, ceil(log2(N)))
segment_tree = [0]*(N2*2)

def update(i, j, val):
    i += N2
    j += N2

    while i <= j:
        if i&1 == 1:
            segment_tree[i] += val
            i += 1
        if j&1 == 0:
            segment_tree[j] += val
            j -= 1
        i>>=1
        j>>=1
    
def query(n):
    n += N2
    add = 0
    while n:
        add += segment_tree[n]
        n>>=1
    return add

ans = []
for _ in range(M):
    q_type, *q_args = map(int, input().split())
    if q_type == 1:
        update(q_args[0]-1, q_args[1]-1, q_args[2])
    else:
        ans.append(A[q_args[0]-1] + query(q_args[0]-1))
print(*ans, sep='\n')