def solution(number, k):
    n = len(number)
    ans = []
    
    for i in range(n):
        while k and ans and ans[-1] < number[i]:
            ans.pop()
            k-=1
        ans.append(number[i])
    
    while k:
        ans.pop()
        k-= 1
    return ''.join(ans)