import sys;input=sys.stdin.readline;

R, C = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(R)]
dp = [[-1 for _ in range(C)] for _ in range(R)]
direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def dfs(x, y):
    if x==R-1 and y==C-1:
        return 1
    
    method = 0
    for dx, dy in direction:
        nx, ny = x+dx, y+dy
        if 0 <= nx < R and 0 <= ny < C:
            if maps[nx][ny] < maps[x][y]:
                if dp[nx][ny] != -1:
                    method += dp[nx][ny]
                else:
                    method += dfs(nx, ny)
    
    dp[x][y] = method
    return method

for i in range(R-1, -1, -1):
    for j in range(C-1, -1, -1):
        if maps[i][j] < maps[0][0] and dp[i][j] == -1:
            dfs(i, j)
        elif maps[i][j] >= maps[0][0]:
            dp[i][j] = 0
dfs(0, 0)
print(dp[0][0])