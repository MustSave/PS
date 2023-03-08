from collections import deque
import sys;input=sys.stdin.readline;

N, M ,V = map(int, input().split())
G = [[] for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)

def dfs():
    stack = [V]
    visited = [False for _ in range(N+1)]
    ans = []
    while stack:
        v = stack.pop()
        if visited[v]: continue

        visited[v] = True
        ans.append(str(v))
        G[v].sort(reverse=True)
        for e in G[v]:
            if visited[e] == False:
                stack.append(e)
    print(' '.join(ans))

dfs()

def bfs():
    deq = deque([V])
    visited = [False for _ in range(N+1)]
    ans = []

    while deq:
        v = deq.popleft()
        if visited[v]: continue

        visited[v] = True
        ans.append(str(v))
        G[v].sort()

        for e in G[v]:
            if visited[e] == False:
                deq.append(e)
    print(' '.join(ans))

bfs()