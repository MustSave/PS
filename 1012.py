import sys;input=sys.stdin.readline;
T = int(input())

field = [[0 for _ in range(50)] for _ in range(50)]
for t in range(T):
    R, C, K = map(int, input().split())

    for _ in range(K):
        x, y = map(int, input().split())
        field[x][y] = 1
    count = 0
    for i in range(R):
        for j in range(C):
            if field[i][j] == 1:
                count += 1
                que = [(i, j)]

                while que:
                    x, y = que.pop(0)
                    if field[x][y] == 0: continue

                    field[x][y] = 0
                    for _x, _y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                        if (0<=x+_x<R) and (0<=y+_y<C) and field[x+_x][y+_y] == 1:
                            que.append((x+_x,y+_y))
    print(count)