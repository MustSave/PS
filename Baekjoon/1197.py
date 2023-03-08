import sys;input=sys.stdin.readline;
import heapq;

V, E = map(int, input().split())
root = [i for i in range(V+1)]
edges = [tuple(map(int, input().split())) for _ in range(E)]
edges.sort(key=lambda x:x[2])
ans = 0

def find(node):
    tmp = node
    while root[tmp] != tmp:
        tmp = root[tmp]
    root[node] = tmp
    return tmp

for u, v, c in edges:
    root_u, root_v = find(u), find(v)

    if root_u == root_v:
        continue
    elif root_u > root_v:
        root[root_u] = root_v
    else:
        root[root_v] = root_u

    ans += c

print(ans)