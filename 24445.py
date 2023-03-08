import sys;input=sys.stdin.readline;print=sys.stdout.write;
from collections import deque;

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1,N+1):
    graph[i].sort(reverse=True)


def bfs(vertex):
    deq = deque([vertex])
    index = 1
    
    while deq:
        v = deq.popleft()
        if visited[v] > 0: continue

        visited[v] = index
        index += 1

        for _v in graph[v]:
            if visited[_v] == 0:
                deq.append(_v)

bfs(R)
for v in visited[1:]:
    print(str(v)+'\n')