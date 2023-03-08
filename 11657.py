import sys;input=sys.stdin.readline;
N, M = map(int, input().split()) # N: 도시 M 길
# INF = 10000 * (N*M+1)
INF = 1<<31
graph = [[] for _ in range(N+1)]
for _ in range(M):
    A, B, C = map(int, input().split()) # |C| <=10000
    graph[A].append((B,C))

def bellman_ford(source):
    dist = [INF] * (N+1)
    dist[source] = 0
    for _ in range(N-1):
        for v in range(1, N+1):
            if dist[v] == INF: continue

            for next, cost in graph[v]:
                new_cost = dist[v]+cost
                if dist[next] > new_cost:
                    dist[next] = new_cost
    
    for v in range(1, N+1):
        if dist[v] == INF: continue
        for next, cost in graph[v]:
            if dist[next] > dist[v]+cost:
                print(-1)
                return
    ans = [0] * (N-1)
    for v in range(2, N+1):
        ans[v-2] = -1 if dist[v] == INF else dist[v]
    print(*ans, sep='\n')

bellman_ford(1)