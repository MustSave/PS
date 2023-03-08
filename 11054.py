N = int(input())
arr = list(map(int, input().split()))
left_dp = []
right_dp = []
ans = 0
for i in range(N):
    left_max = 0
    right_max = 0
    for j in range(i):
        if arr[j] < arr[i]:
            left_max = max(left_max, left_dp[j])
        if arr[N-1-j] < arr[N-1-i]:
            right_max = max(right_max, right_dp[j])
    left_dp.append(left_max+1)
    right_dp.append(right_max+1)

for i in range(N):
    ans = max(ans, left_dp[i] + right_dp[N-1-i])
print(ans-1)