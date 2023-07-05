import math

def solution(r1, r2):
    answer = 0
    
    for r in range(1, r2):
        high = math.floor(math.sqrt(r2 ** 2 - r ** 2))
        temp = math.sqrt(r1 ** 2 - r ** 2) if r1 > r else 0
        
        low = math.floor(temp)
        if (temp != 0 and low == temp):
            low -= 1
        
        answer += 4 * (high - low)
    
    return answer + 4 * (r2 - r1 + 1)
