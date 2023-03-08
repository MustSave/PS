import sys;input=sys.stdin.readline;
import heapq;

TC = int(input())

def solve():
    N = int(input())
    numbers = []
    for _ in range(N//10 + 1):
        numbers.extend(map(int, input().split()))

    left_heap = [(-numbers[0])] # max heap
    right_heap = [] # min heap
    ans = [numbers[0]]

    for i in range(1, N):
        if numbers[i] > -left_heap[0]:
            heapq.heappush(right_heap, (numbers[i]))
            if len(right_heap) > len(left_heap):
                tmp = heapq.heappop(right_heap)
                heapq.heappush(left_heap, (-tmp))
        else:
            heapq.heappush(left_heap, (-numbers[i]))
            if len(left_heap) > len(right_heap) +1:
                tmp = heapq.heappop(left_heap)
                heapq.heappush(right_heap, (-tmp))
        if i&1 == 0:
            ans.append(-left_heap[0])

    print(len(ans))
    for i in range(len(ans)//10 + 1):
        print(*ans[i*10:i*10 + 10])

for _ in range(TC):
    solve()