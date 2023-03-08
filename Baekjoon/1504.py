import sys;input=sys.stdin.readline;
import heapq

N, E = map(int, input().split())
graph = [[] for _ in range(N+1)]
for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))
v1, v2 = map(int, input().split())

def dijkstra(s, e):
    pq = []
    heapq.heappush(pq, (0, s))
    dist = [10000000 for _ in range(N+1)]
    dist[s] = 0
    
    while pq:
        min_cost, vertex = heapq.heappop(pq)

        for adj, cost in graph[vertex]:
            new_cost = min_cost + cost
            if dist[adj] > new_cost:
                dist[adj] = new_cost
                heapq.heappush(pq, (new_cost, adj))
    ret = [dist[i] for i in e]
    return ret

res_v1 = dijkstra(v1, [v2, N])
if res_v1[0] == 10000000:
    exit(print(-1))
one = dijkstra(1, [v1, v2])
res_v2 = dijkstra(v2, [N])
ans = min(one[0] + res_v2[0], one[1] + res_v1[1]) + res_v1[0]
if ans >= 10000000:
    exit(print(-1))
else:
    exit(print(ans))