import sys;input=sys.stdin.readline;
N = int(input())
M = int(input())
INF = int(1e10)
dist = [[INF for _ in range(N+1)] for _ in range(N+1)]
for _ in range(M):
    S, D, C = map(int, input().split()) # 0 < cost <=100000
    dist[S][D] = min(dist[S][D], C)
for i in range(1, N+1):
    dist[i][i] = 0
for m in range(1, N+1):
    for s in range(1, N+1):
        for d in range(1, N+1):
            tmp = dist[s][m] + dist[m][d]
            if dist[s][d] > tmp:
                dist[s][d] = tmp

for i in range(1, N+1):
    for j in range(1, N+1):
        if dist[i][j] == INF:
            dist[i][j] = 0

for r in dist[1:]:
    print(*r[1:])