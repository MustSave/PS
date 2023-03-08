import sys;input=sys.stdin.readline;
N, C = map(int, input().split())
coord = [int(input()) for _ in range(N)]
coord.sort()
max_length = (coord[-1] - coord[0])//(C-1)

def install(length):
    ans = 0
    prev_coord = -length
    for c in coord:
        if c - prev_coord >= length:
            prev_coord = c
            ans += 1
    return ans

def bin_search(s, e):
    while s <= e:
        mid = (s+e)//2

        if install(mid) >= C:
            s = mid+1
        else:
            e = mid-1
    return e

print(bin_search(1, max_length))