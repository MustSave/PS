N = int(input())

G = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]

for _ in range(int(input())):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)

def dfs():
    global visited, G
    stack = [1]

    while stack:
        v = stack.pop()
        if visited[v]: continue

        visited[v] += 1

        for e in G[v]:
            if visited[e] == 0:
                stack.append(e)

dfs()
print(sum(visited)-1)