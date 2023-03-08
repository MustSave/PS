import sys;input=sys.stdin.readline;

def find(root, node):
    tmp = node
    while root[tmp] != tmp:
        tmp = root[tmp]
    root[node] = tmp
    return tmp

def test():
    M, N = map(int, input().split())
    if M+N == 0: return False

    MAX = 0
    edges = []
    visited = 0
    root = [i for i in range(M)]
    for _ in range(N):
        u, v, c = map(int, input().split())
        edges.append((u, v, c))
        MAX += c
    edges.sort(key=lambda x:x[2])
    cost = 0
    for u, v, c in edges:
        if visited == M-1: break
        root_u, root_v = find(root, u), find(root, v)
        if root_u == root_v: continue

        if root_u > root_v:
            root[root_u] = root_v
        else:
            root[root_v] = root_u
        visited += 1
        cost += c

    print(MAX-cost)
    return True

if __name__ == '__main__':
    while test(): pass