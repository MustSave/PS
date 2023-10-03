import heapq
import sys;input=sys.stdin.readline;
N = int(input())
cost = [list(map(int, input().rstrip().split())) for _ in range(N)]

visited = [False] * N
memory = [0] + [1e9]*(N-1)
heap = [(0, 0)]
total = 0

while heap:
    c, planet = heapq.heappop(heap)
    if visited[planet]: continue

    total += c
    visited[planet] = True
    for i in range(N):
        if visited[i] == False and memory[i] > cost[planet][i]:
            heapq.heappush(heap, (cost[planet][i], i))
            memory[i] = cost[planet][i]

print(total)