import sys;input=sys.stdin.readline;

N, M = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(N)] # N x M

ones = 0
direct = [(0, 1), (1, 0), (0, -1), (-1, 0)]
edges = []
for i in range(N):
    for j in range(M):
        if maps[i][j] == 0: continue

        ones += 1
        for dx, dy in direct:
            nx, ny = i+dx, j+dy
            length = 0
            while 0 <= nx < N and 0 <= ny < M:
                if maps[nx][ny] == 1:
                    if length != 1: edges.append((length, M*i + j, M*nx + ny))
                    break
                nx += dx
                ny += dy
                length += 1
            
edges.sort(key=lambda x:x[0])
ans = 0
visited = 0
root = [i for i in range(N*M)]
# def find(node):
#     tmp = node
#     while root[tmp] != tmp:
#         tmp = root[tmp]
#     root[node] = tmp
#     return tmp
def find(node):
    if root[node] == node: return node

    root[node] = find(root[node])
    return root[node]

for c, u, v in edges:
    if visited == ones -1: break
    root_u, root_v = find(u), find(v)
    if root_u == root_v: continue

    if root_u > root_v:
        root[root_u] = root_v
    else:
        root[root_v] = root_u
    ans += c
    visited += 1
else:
    exit(print(-1))
print(ans)