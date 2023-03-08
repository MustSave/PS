import sys;input=lambda:sys.stdin.readline().rstrip();

N = int(input())
M = int(input())

root = [i for i in range(N+1)]

def union_find(node):
    tmp = node
    while root[tmp] != tmp:
        tmp = root[tmp]
    root[node] = tmp
    return tmp


for i in range(1, N+1):
    for j, val in enumerate(map(int, input().split()), start=1):
        if val == 1:
            root_a, root_b = union_find(i), union_find(j)
            if root_a > root_b:
                root[root_a] = root_b
            else:
                root[root_b] = root_a

prev = -1
for node in map(int, input().split()):
    test = union_find(node)
    if prev == -1: prev = test
    if prev != test: exit(print("NO"))
    prev = test
print("YES")