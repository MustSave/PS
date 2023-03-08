import sys;input=lambda:sys.stdin.readline().rstrip();
from collections import defaultdict;

TC = int(input())

def union_find(obj, node):
    tmp = node
    if node not in obj:
        obj[node] = [node, 1]
    while obj[tmp][0] != tmp:
        tmp = obj[tmp][0]
    obj[node][0] = tmp
    return tmp

def solve():
    F = int(input())

    friend_dict = {}
    for _ in range(F):
        A, B = map(hash, input().split())
        root_A, root_B = union_find(friend_dict, A), union_find(friend_dict, B)
        if root_A == root_B:
            print(friend_dict[root_A][1])
        else:
            pool = friend_dict[root_B][1] + friend_dict[root_A][1]
            friend_dict[root_B][0] = root_A
            friend_dict[root_A][1] = pool
            print(pool)

for _ in range(TC):
    solve()