import sys;input=lambda:sys.stdin.readline().rstrip()
K = int(input())

def f():
    V, E = map(int, input().split())
    graph = [[] for _ in range(V+1)]
    team = [-1 for _ in range(V+1)]
    for _ in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    
    stack = [*range(1, V+1)]
    while stack:
        v = stack.pop()
        if team[v] == -1:
            team[v] = 0
        
        for i in graph[v]:
            if team[i] == -1:
                team[i] = 1-team[v]
                stack.append(i)
            elif team[i] == team[v]:
                return 'NO'
    return "YES"

for _ in range(K):
    print(f())