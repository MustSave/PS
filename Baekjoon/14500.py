N, M = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(N)]

def tet1(x, y):
    ret = 0
    if y+3 < M:
        ret = paper[x][y] + paper[x][y+1] + paper[x][y+2] + paper[x][y+3]
    if x+3 < N:
        ret = max(ret, paper[x][y] + paper[x+1][y] + paper[x+2][y] + paper[x+3][y])
    return ret

def tet2(x, y):
    if x+1 >= N or y+1 >= M:
        return 0
    return paper[x][y] + paper[x][y+1] + paper[x+1][y] + paper[x+1][y+1]

def tet3(x, y):
    ret = 0
    if x+2 < N:
        base = paper[x][y] + paper[x+1][y] + paper[x+2][y]
        if y+1 < M:
            ret = max(ret, base + paper[x+2][y+1])
            ret = max(ret, base + paper[x+1][y+1])
            ret = max(ret, base + paper[x][y+1])
        if y-1 >= 0:
            ret = max(ret, base + paper[x+2][y-1])
            ret = max(ret, base + paper[x+1][y-1])
            ret = max(ret, base + paper[x][y-1])
    
    if y+2 < M:
        base = paper[x][y] + paper[x][y+1] + paper[x][y+2]
        if x-1 >= 0:
            ret = max(ret, base + paper[x-1][y])
            ret = max(ret, base + paper[x-1][y+1])
            ret = max(ret, base + paper[x-1][y+2])
        if x+1 < N:
            ret = max(ret, base + paper[x+1][y])
            ret = max(ret, base + paper[x+1][y+1])
            ret = max(ret, base + paper[x+1][y+2])
    return ret

def tet4(x, y):
    ret = 0
    if x+2 < N and y+1 < M:
        base = paper[x+1][y] + paper[x+1][y+1]
        ret = max(ret, base + paper[x][y] + paper[x+2][y+1])
        ret = max(ret, base + paper[x][y+1] + paper[x+2][y])
    if x+1 < N and y+2 < M:
        base = paper[x][y+1] + paper[x+1][y+1]
        ret = max(ret, base + paper[x+1][y] + paper[x][y+2])
        ret = max(ret, base + paper[x][y] + paper[x+1][y+2])
    return ret
ans = 0
for i in range(N):
    for j in range(M):
        ans = max(ans, tet1(i, j), tet2(i, j), tet3(i, j), tet4(i, j))
print(ans)
