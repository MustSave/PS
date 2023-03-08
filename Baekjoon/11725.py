import sys;input=sys.stdin.readline;
N = int(input())
parent = [-1 for i in range(N+1)]
graph = [[] for _ in range(N+1)]
def get_root(node):
    if parent[parent[node]] == node:
        return node
    return get_root(parent[node])

for _ in range(N-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

stack = [1]
while stack:
    vertex = stack.pop()
    for node in graph[vertex]:
        if parent[node] == -1:
            parent[node] = vertex
            stack.append(node)

print(*parent[2:], sep='\n')