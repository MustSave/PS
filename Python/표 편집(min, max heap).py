import heapq

def solution(n, k, cmd):
    max_heap = [-i for i in range(k+1)] # 0 ~ k번째까지
    min_heap = [i for i in range(k+1, n)] # 그 이후
    heapq.heapify(max_heap)
    heapq.heapify(min_heap)
    
    ans = ['O'] * n
    stack = []
    
    for c in cmd:
        if c[0] == 'U':
            move = int(c[2:])
            for _ in range(move):
                tmp = heapq.heappop(max_heap)
                heapq.heappush(min_heap, -tmp)
            
        elif c[0] == 'D':
            move = int(c[2:])
            for _ in range(move):
                tmp = heapq.heappop(min_heap)
                heapq.heappush(max_heap, -tmp)
                
        elif c[0] == 'C':
            tmp = -heapq.heappop(max_heap)
            stack.append(tmp)
            ans[tmp] = 'X'
            
            if len(min_heap) > 0:
                tmp = heapq.heappop(min_heap)
                heapq.heappush(max_heap, -tmp)

        else:
            tmp = stack.pop()
            ans[tmp] = 'O'
            if tmp > -max_heap[0]:
                heapq.heappush(min_heap, tmp)
            else:
                heapq.heappush(max_heap, -tmp)
    
    return ''.join(ans)
            