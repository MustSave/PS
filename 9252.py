s1 = input()
s2 = input()

dp = [[0 for _ in range(len(s2)+1)] for _ in range(len(s1)+1)]

for i in range(1, len(s1)+1):
    for j in range(1, len(s2)+1):
        if s1[i-1] == s2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

ans = []
x = len(s1)
y = len(s2)

while x > 0 and y > 0:
    if dp[x-1][y] == dp[x][y]:
        x -= 1
    elif dp[x][y-1] == dp[x][y]:
        y -= 1
    else:
        ans.append(s1[x-1])
        x -= 1
        y -= 1
print(len(ans))
if len(ans) > 0: print(''.join(ans[::-1]))