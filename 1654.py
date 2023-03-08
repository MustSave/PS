import sys;input=sys.stdin.readline;
K, N = map(int, input().split())
cable = [int(input()) for _ in range(K)]
ans = 0

def cut_result(length):
    result = 0
    for c in cable:
        result += c//length
    return result

def bin_search(start, end):
    global ans
    if start > end:
        print(start, end)
        return
    mid = (start+end)//2
    cut = cut_result(mid)
    if cut < N:
        bin_search(start, mid-1)
    else:
        ans = mid
        bin_search(mid+1, end)


bin_search(1, max(cable))
print(ans)