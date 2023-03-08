from math import log2, ceil, floor
import sys
sys.setrecursionlimit(10**6)
def inorder(number, mid):
    new_num = number >> (mid-1)
    if mid == 1:
        return new_num&1
    
    left = inorder(new_num>>1, mid//2)
    if left == 2: return 2
    right = inorder(number, mid//2)
    if right == 2: return 2
    
    if new_num&1 == 0:
        if left == 0 and right == 0:
            return 0
        else:
            return 2
    else:
        return 1   

def solution(numbers):
    # 중위순회 left root right
    # 포화 이진트리의 노드수 = number 이상인 2의 지수승 -1
    answer = []
    
    for num in numbers:
        binary_length = floor(log2(num))
        mid = 2
        while mid-1 <= binary_length:
            mid *= 2
        mid //=2
        
        answer.append(1 if inorder(num, mid)==1 else 0)
    
    return answer