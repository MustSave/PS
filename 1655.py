import heapq
import sys
input = sys.stdin.readline

N = int(input())

minheap = []
maxheap = []
mid = 10001

lmin = 0
lmax = 0

for i in range(N):
    tmp = int(input())

    if tmp > mid:
        heapq.heappush(minheap, tmp)
        lmin += 1
        
        if lmin > lmax:
            pop = heapq.heappop(minheap)
            heapq.heappush(maxheap, -pop)
            lmin -= 1
            lmax += 1
            
    else:
        heapq.heappush(maxheap, -tmp)
        lmax += 1
        
        if lmax - 1 > lmin:
            pop = heapq.heappop(maxheap)
            heapq.heappush(minheap, -pop)
            lmax -= 1
            lmin += 1
            
    mid = -maxheap[0]
    print(mid)