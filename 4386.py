import sys;input=sys.stdin.readline;
import math;
N = int(input())

coord = [tuple(map(float, input().split())) for _ in range(N)]
cost = []

for i in range(N-1):
    for j in range(i+1, N):
        # cost.append((i, j, math.sqrt((coord[i][0]-coord[j][0])**2 + (coord[i][1]-coord[j][1])**2)))
        cost.append((i, j, math.dist(coord[i], coord[j])))

cost.sort(key=lambda x: x[2])

visited = 0
ans = 0
root = [i for i in range(N)]

def find(node):
    tmp = node
    while root[tmp] != tmp:
        tmp = root[tmp]
    root[node] = tmp
    return tmp

for u, v, c in cost:
    root_u, root_v = find(u), find(v)

    if root_u == root_v: continue

    if root_u > root_v:
        root[root_u] = root_v
    else:
        root[root_v] = root_u

    ans += c
    visited += 1

    if visited == N-1: break

print(round(ans, 2))