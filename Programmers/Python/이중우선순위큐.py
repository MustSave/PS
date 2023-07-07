import heapq
from collections import defaultdict

def solution(operations):
    min_heap = []
    max_heap = []
    answer = []
    counter = defaultdict(int)
    size = 0

    for operation in operations:
        op, data = operation.split()
        data = int(data)
        
        if op == 'I':
            heapq.heappush(min_heap, data)
            heapq.heappush(max_heap, data * -1)
            counter[data] += 1
            size += 1
        else:
            target_heap = max_heap if data == 1 else min_heap
            data = data * -1
            
            if target_heap:
                value = heapq.heappop(target_heap) * data
                while counter[value] == 0 and target_heap:
                    value = heapq.heappop(target_heap) * data
                    
                if counter[value] > 0:
                    counter[value] -= 1
                    size -= 1
    
    if size == 0:
        return [0, 0]
    else:
        for target_heap, data in [(max_heap, -1), (min_heap, 1)]:
            value = heapq.heappop(target_heap) * data
            while counter[value] == 0:
                value = heapq.heappop(target_heap) * data
            answer.append(value)
        return answer
        
