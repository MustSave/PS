import sys;input=lambda: sys.stdin.readline().rstrip();

N, M, K = map(int, input().split())
supply = set(map(int, input().split()))
graph = [list(map(int, input().split())) for _ in range(M)]
graph.sort(key=lambda x: x[2])

root = [i for i in range(N+1)]

def find_root(i):
    if root[i] != i:
        root[i] = find_root(root[i])
    return root[i]

def union(a, b):
    root_a, root_b = find_root(a), find_root(b)
    if root_a != root_b and not (root_a in supply and root_b in supply):
        if root_a in supply:
            root[root_b] = root_a
        elif root_b in supply:
            root[root_a] = root_b
        elif root_a > root_b:
            root[root_a] = root_b
        else:
            root[root_b] = root_a
        return True
    return False

ans = 0
for u, v, w in graph:
    if union(u, v):
        ans += w

print(ans)