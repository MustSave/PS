import sys;input=sys.stdin.readline;
sys.setrecursionlimit(1000000)
N, M = map(int, input().split())

root = [i for i in range(N)]

def find(node):
    tmp = node
    while root[tmp] != tmp:
        tmp = root[tmp]
    root[node] = tmp
    return tmp

# def find(node):
#     if root[node] == node:
#         return node
    
#     root[node] = find(root[node])
#     return root[node]

for i in range(1, M+1):
    u, v = map(int, input().split())

    root_u, root_v = find(u), find(v)
    
    if root_u == root_v:
        exit(print(i))
    elif root_u > root_v:
        root[root_u] = root_v
    else:
        root[root_v] = root_u

print(0)