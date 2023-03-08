import sys;input=sys.stdin.readline;
import heapq
sys.setrecursionlimit(10000)
N = int(input())
graph = [[]for _ in range(N+1)]

for _ in range(N-1):
    parent, child, cost = map(int, input().split())
    graph[parent].append((child, cost))

ans = 0
def solve(node):
    global ans
    if not graph[node]: return 0

    li = []
    for child, cost in graph[node]:
        tmp = solve(child)
        heapq.heappush(li, -(tmp+cost))
    
    a = -heapq.heappop(li)
    b = -heapq.heappop(li) if li else 0

    ans = max(ans, a+b)
    return a
solve(1)
print(ans)