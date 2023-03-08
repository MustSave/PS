import sys;input=lambda:sys.stdin.readline().rstrip();

N, M = map(int, input().split())
parent = [i for i in range(N+1)]

def find_root(node):
    tmp = node
    while parent[tmp] != tmp:
        tmp = parent[tmp]
    parent[node] = tmp
    return tmp

for _ in range(M):
    op, A, B = map(int, input().split())
    if op == 0:
        parent_A, parent_B = find_root(A), find_root(B)
        parent[parent_B] = parent_A
    else:
        parent_A, parent_B = find_root(A), find_root(B)
        print("YES" if parent_A==parent_B else "NO")