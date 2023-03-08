def solution(n, lost, reserve):
    std = [0] * n
    ans = 0
    for l in lost:
        std[l-1] -= 1
    for r in reserve:
        std[r-1] += 1
    for i in range(n):
        if std[i] < 0:
            if i-1 >= 0 and std[i-1] > 0:
                ans += 1
            elif i+1 < n and std[i+1] > 0:
                ans += 1
                std[i+1] -= 1
        if std[i] >= 0:
            ans += 1
    return ans