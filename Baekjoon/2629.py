from collections import Counter

N = int(input())
weight = list(map(int, input().split()))
max_weight = weight[-1] * N
M = int(input())
beads = list(map(int, input().split()))

# 45000
dp = [0] * (max_weight+1)
for w in weight[::-1]:
    tmp = []
    for i in range(1, max_weight+1):
        if dp[i] == 0: continue

        if i-w >= 0: dp[i-w] += 1
        if w-i >= 0: tmp.append(w-i)
        if i+w <= max_weight: tmp.append(i+w)
    for t in tmp:
        dp[t] += 1
    dp[w] += 1
# print(*dp)
for bead in beads:
    if bead > max_weight: print("N", end=' ')
    else: print("Y" if dp[bead] != 0 else "N", end=' ')