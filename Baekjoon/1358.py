import heapq
import sys;input=sys.stdin.readline;

N = int(input())
W = [int(input()) for _ in range(N)]
P = [list(map(int, input().rstrip().split())) for _ in range(N)]

visited = [False] * N

min_cost_dig = min(W)
min_idx_dig = W.index(min_cost_dig)

q = []
for i in range(N):
    if i == min_idx_dig: continue

    heapq.heappush(q, (min(W[i], P[min_idx_dig][i]), min_idx_dig, i))

cost = min_cost_dig
visited[min_idx_dig] = True

while q:
    c, i, j = heapq.heappop(q)
    if visited[i] and visited[j]:
        continue

    cost += c
    visited[j] = True
    for n in range(N):
        if not visited[n]:
            heapq.heappush(q, (min(W[n], P[j][n]), j, n))

print(cost)