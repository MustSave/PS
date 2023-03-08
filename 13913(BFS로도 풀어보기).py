import heapq
subin, brother = map(int, input().split())
if subin == brother: exit(print(0, subin, sep='\n'))
q = [(0, subin)]
dist = [1000000] * (100001)
parent = [-1 for _ in range(100001)]
while q:
    cost, x = heapq.heappop(q)

    for nx, add in [(x-1, 1), (x+1, 1), (x*2, 1)]:
        if nx < 0 or nx > 100000: continue

        if dist[nx] > cost + add:
            dist[nx] = cost+add
            parent[nx] = x
            heapq.heappush(q, (cost+add, nx))

print(dist[brother])
path = [brother]
while brother != subin:
    path.append(parent[brother])
    brother = parent[brother]
print(*path[::-1])