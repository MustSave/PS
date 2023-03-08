import sys;input=sys.stdin.readline;print=sys.stdout.write;
N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(N+1):
    graph[i].sort(reverse=True)

visited = [0 for _ in range(N+1)]
visited_seq = 1

def dfs(vertex):
    global visited_seq
    stack = [vertex]

    while stack:
        v = stack.pop()
        if visited[v] > 0: continue

        visited[v] = visited_seq
        visited_seq += 1

        for e in graph[v]:
            if visited[e] == 0:
                stack.append(e)

dfs(R)

for v in visited[1:]:
    print(str(v)+'\n')