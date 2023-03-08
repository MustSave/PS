N = int(input())

dp = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]

for i in range(1, N):
    tmp = [0 for _ in range(10)]
    for i in range(10):
        if i == 0:
            tmp[i] = dp[1]
        elif i == 9:
            tmp[i] = dp[8]
        else:
            tmp[i] = (dp[i-1]+dp[i+1]) % 1000000000
    dp = tmp

print(sum(dp) % 1000000000)


    # 10 12
    # 21 23
    # 32 34
    # 43 45
    # 54 56
    # 65 67
    # 76 78
    # 87 89
    # 98

    # 15 * 2 + 2 * 1 = 32
    # (32-4)*2 + 4 = 60