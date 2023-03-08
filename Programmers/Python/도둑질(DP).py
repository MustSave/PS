def solution(money):
    # 1칸 건너뛰거나 2칸 건너뛰거나
    # 0시작 ~ len-1
    # 1시작 ~ len
    # dp[i] = max(dp[i-2], dp[i-3])
    
    # 첫번째 집을 털었을 경우
    a, b, c = money[0], 0, money[0]+money[2]
    # 첫번째 집을 털지 않았을 경우
    d, e, f = 0, money[1], money[2]
    
    for house in money[3:]:
        a, b, c = b, c, max(a, b) + house
        d, e, f = e, f, max(d, e) + house
    
    # 첫번째 집을 털고 마지막 집도 털은 경우(c)는 제외
    return max(a, b, d, e, f)