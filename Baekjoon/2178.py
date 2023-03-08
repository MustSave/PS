import sys;input=lambda:sys.stdin.readline().rstrip()

N, M = map(int, input().split())
maze = [list(input()) for _ in range(N)]

que = [(0, 0)]
delta = ((0, 1), (0, -1), (1, 0), (-1, 0))
count = 1
while maze[N-1][M-1] == '1':
    count += 1
    tmp = []
    for x, y in que:
        for dx, dy in delta:
            if 0<=x+dx<N and 0<=y+dy<M and maze[x+dx][y+dy] == '1':
                maze[x+dx][y+dy] = '0'
                tmp.append((x+dx, y+dy))
    que = tmp

print(count)