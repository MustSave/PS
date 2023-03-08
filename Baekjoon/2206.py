import sys;input=lambda:sys.stdin.readline().rstrip()
N, M = map(int, input().split())
wall = [list(input()) for _ in range(N)]
visited = [[[False, False] for _ in range(M)] for _ in range(N)]
# 0: 길 1: 벽
direct = [(0, 1), (1, 0), (0, -1), (-1, 0)]
que = [(0, 0, 0)]
if N*M == 1:
    exit(print(1))
step = 1
visited[0][0] = [True, True]
while que:
    tmp = []
    for x, y, destroied in que:
        for dx, dy in direct:
            nx, ny = x+dx, y+dy
            if 0<=nx<N and 0<=ny<M:
                if nx == N-1 and ny == M-1:
                    exit(print(step+1))
                if visited[nx][ny][destroied] == False and wall[nx][ny] == '0':
                    tmp.append((nx, ny, destroied))
                    visited[nx][ny][destroied] = True
                elif wall[nx][ny] == '1' and not destroied:
                    tmp.append((nx, ny, 1))

    step += 1
    que = tmp

print(-1)