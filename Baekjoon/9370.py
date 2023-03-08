import sys;input=sys.stdin.readline;
import heapq

def dijkstra(start):
    dist = [4000000 for _ in range(n+1)]
    dist[start] = 0
    q = [(0, start)]
    while q:
        shortest, vertex = heapq.heappop(q)
        if shortest > dist[vertex]: continue
        for adj, cost in graph[vertex]:
            new_cost = shortest + cost
            if dist[adj] > new_cost:
                dist[adj] = new_cost
                heapq.heappush(q, (new_cost, adj))
    return dist

T = int(input())

for _ in range(T):
    n, m, t = map(int, input().split()) # n: vertex, m: edge, t: predict
    s, g, h = map(int, input().split()) # s: start point, (g, h) passed
    graph = [[] for _ in range(n+1)]
    pred = []
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d*2))
        graph[b].append((a, d*2))
    for _ in range(t):
        pred.append(int(input()))
    for i in range(len(graph[g])):
        if graph[g][i][0] == h:
            graph[g][i] = (h, graph[g][i][1]-1)
    for i in range(len(graph[h])):
        if graph[h][i][0] == g:
            graph[h][i] = (g, graph[h][i][1]-1)

    source = dijkstra(s)
    # dist_g = dijkstra(g)
    # dist_h = dijkstra(h)

    ans = []
    for test in pred:
        # sgh = source[g]+gh+dist_h[test]
        # shg = source[h]+gh+dist_g[test]
        # print(source[test], sgh, shg, gh)
        # if source[test] in [sgh, shg]:
        if source[test] % 2 == 1:
            ans.append(test)
    ans.sort()
    print(*ans)
