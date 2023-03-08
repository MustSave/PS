import sys;input=sys.stdin.readline;
V = int(input())

graph = [[] for _ in range(V+1)]
visited = [False] * (V+1)
for _ in range(V):
    source, *adj = map(int, input().split())
    for i in range(0, len(adj)-1, 2):
        graph[source].append((adj[i], adj[i+1]))

ans = 0
def dfs(node, length):
    global ans
    tmp = []
    isLeaf = True
    for adj, cost in graph[node]:
        if not visited[adj]:
            isLeaf = False
            visited[adj] = True
            tmp.append(dfs(adj, length+cost))
    if isLeaf:
        return length

    tmp.sort()
    if len(tmp) == 1:
        res =  tmp[-1]
    else:
        res = max(tmp[-1]+tmp[-2]-2*length, tmp[-1])
    ans = max(ans, res)
    return tmp[-1]

visited[1] = True
dfs(1, 0)
print(ans)