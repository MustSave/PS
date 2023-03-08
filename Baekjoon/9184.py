# 0 0 0 ~ 20 20 20 

def idx(a, b, c):
    return a*400 + b*20 + c

W = []

tmp = list(map(int, input().split()))
W.append(tmp)

while tmp != [-1, -1, -1]:
    tmp = list(map(int, input().split()))
    W.append(tmp)    


dp = [[[1 for _ in range(21)] for _ in range(21)] for _ in range(21)]

for i in range(1, 21):
    for j in range(1, 21):
        for k in range(1, 21):
            dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k] if i < j and j < k else dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1]

for a, b, c in W[:-1]:
    print("w(" + str(a) + ", " + str(b) + ", " + str(c) + ") = ", end='')
    if a <= 0 or b <= 0 or c <= 0:
        print(1)
    elif a > 20 or b > 20 or c > 20:
        print(dp[20][20][20])
    else:
        print(dp[a][b][c])