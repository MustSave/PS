import sys;import heapq;input=sys.stdin.readline;from collections import deque;
V, E = map(int, input().split())
INF = 1 << 31
graph = [[] for _ in range(V+1)]

for _ in range(E):
    u, v, c = map(int, input().split()) # 0 < c <= 10000
    graph[u].append((v, c))


def floyd_warshall():
    dist = [[INF for _ in range(V+1)] for _ in range(V+1)]
    for i in range(1, V+1):
        for adj, cost in graph[i]:
            dist[i][adj] = cost
    
    for m in range(1, V+1):
        for s in range(1, V+1):
            if dist[s][m] == INF: continue
            for e in range(1, V+1):
                tmp = dist[s][m] + dist[m][e]
                if dist[s][e] > tmp:
                    dist[s][e] = tmp
    ans = INF
    for i in range(1, V+1):
        ans = min(ans, dist[i][i])
    return -1 if ans == INF else ans
print(floyd_warshall())

# def dijkstra2():
#     pq = []
#     dist = [[INF for _ in range(V+1)] for _ in range(V+1)]
#     for source in range(1, V+1):
#         for adj, cost in graph[source]:
#             dist[source][adj] = cost
#             heapq.heappush(pq, (cost, source, adj))
#     while pq:
#         shortest, source, current = heapq.heappop(pq)
#         if source == current: return  shortest
#         if shortest > dist[source][current]: continue

#         for adj, cost in graph[current]:
#             new_cost = shortest+cost
#             if dist[source][adj] > new_cost:
#                 dist[source][adj] = new_cost
#                 heapq.heappush(pq, (new_cost, source, adj))
#     return -1
# print(dijkstra2())

# def dijkstra(source):
#     queue = [(0, source)]
#     dist = [INF] * (V+1)
#     while queue:
#         shortest, vertex = heapq.heappop(queue)
#         if dist[vertex] < shortest: continue
#         for adj, cost in graph[vertex]:
#             new_cost = shortest + cost
#             if dist[adj] > new_cost:
#                 dist[adj] = new_cost
#                 heapq.heappush(queue, (new_cost, adj))
#     return dist

# a = [None] + [dijkstra(i) for i in range(1, V+1)]
# ans = INF
# for i in range(1, V+1):
#     for j in range(1, V+1):
#         if i == j: continue
#         ans = min(ans, a[i][j] + a[j][i])

# print(-1 if ans == INF else ans)

# def bfs():
#     queue = deque([(0, s, s) for s in range(1, V+1) if len(graph[s])])
#     ans = INF
#     while queue:
#         shortest, cur, dst = queue.popleft()

#         for vertex, cost in graph[cur]:
#             new_cost = shortest+cost
#             if new_cost >= ans: continue
#             if vertex == dst:
#                 ans = min(ans, new_cost)
#             else:
#                 queue.append((new_cost, vertex, dst))
#     return ans if ans != INF else -1
# print(bfs())
