def solution(N, number):
    dp = [set() for _ in range(9)]
    tmp = 0
    for i in range(1, 9):
        tmp = tmp * 10 + N
        dp[i].add(tmp)
    
    for i in range(1, 9):
        for j in range(1, 9-i):
            for a in dp[i]:
                for b in dp[j]:
                    if a+b <= 32000: dp[i+j].add(a+b)
                    dp[i+j].add(abs(a-b))
                    if a*b <= 32000: dp[i+j].add(a*b)
                    if b!= 0: dp[i+j].add(a//b)
    i = 1
    while i < 9:
        if number in dp[i]: break
        i+=1
    return i if i <= 8 else -1