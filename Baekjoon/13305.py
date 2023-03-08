# import sys;input=sys.stdin.readline;print=sys.stdout.write;
N = int(input())
roads = list(map(int, input().split()))
costs = list(map(int, input().split()))
ans = 0
low = costs[0]
for i in range(N-1):
    if costs[i] < low:
        low = costs[i]
    ans += roads[i]*low
print(str(ans))