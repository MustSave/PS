import sys;input=sys.stdin.readline;
M, N, H = map(int, input().split())
tomatos = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]
#tomatos[H][N][M]
near = [(1, 0, 0), (-1, 0, 0), (0, -1, 0), (0, 1, 0), (0, 0, 1), (0, 0, -1)]
# 1: 익 0: 안익 -1: 없
deq = []
count = 0
for i in range(H):
    for j in range(N):
        for k in range(M):
            if tomatos[i][j][k] == 1:
                deq.append((i, j, k))
            elif tomatos[i][j][k] == 0:
                count += 1
ans = 0
while deq and count:
    tmp = []
    for x, y, z in deq:
        for dx, dy, dz in near:
            nx, ny, nz = x+dx, y+dy, z+dz
            if 0<=nx<H and 0<=ny<N and 0<=nz<M and tomatos[nx][ny][nz] == 0:
                tmp.append((nx, ny, nz))
                tomatos[nx][ny][nz] = 1
                count -= 1
    deq = tmp
    ans += 1
print(ans if count == 0 else -1)