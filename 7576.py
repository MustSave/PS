M, N = map(int, input().split())
tomatos = [list(map(int, input().split())) for _ in range(N)]
near = ((1, 0), (0, 1), (0, -1), (-1, 0))
# 1: 익 0: 안익 -1: 없
deq = []
count = 0
for i in range(N):
    for j in range(M):
        if tomatos[i][j] == 1:
            deq.append((i, j))
        elif tomatos[i][j] == 0:
            count += 1
ans = 0
while deq and count:
    tmp = []
    for x, y in deq:
        for dx, dy in near:
            nx = x+dx
            ny = y+dy
            if 0<=nx<N and 0<=ny<M and tomatos[nx][ny] == 0:
                tmp.append((nx, ny))
                tomatos[nx][ny] = 1
                count -= 1
    deq = tmp
    ans += 1
print(ans if count == 0 else -1)