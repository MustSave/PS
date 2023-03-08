import sys;input=sys.stdin.readline;

def find(node):
    tmp = node
    while root[tmp] != tmp:
        tmp = root[tmp]
    root[node] = tmp
    return tmp

def solve():
    pq = []
    ans = 0
    for _ in range(M):
        u, v = map(int, input().split())
        pq.append((u, v))

    for u, v in pq:
        root_u, root_v = find(u), find(v)

        if root_u == root_v:
            continue
        elif root_u > root_v:
            root[root_u] = root_v
        else:
            root[root_v] = root_u
        ans += 1

    print(ans)


if __name__=='__main__':
    for _ in range(int(input())):
        N, M = map(int, input().split())
        root = [i for i in range(N+1)]
        solve()