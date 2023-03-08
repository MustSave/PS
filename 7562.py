TC = int(input())

KNIGHT = ((1, 2), (2, 1), (-1, 2), (2, -1), (-1, -2), (-2, -1), (1, -2), (-2, 1))

def f(x, y):
    que = [(x, y)]
    step = 0
    while que:
        tmp = []
        for cx, cy in que:
            if cx == target_x and cy == target_y: return step
            if board[cx][cy]: continue
            board[cx][cy] = True

            for dx, dy in KNIGHT:
                if 0<=cx+dx<I and 0<=cy+dy<I and not board[cx+dx][cy+dy]:
                    tmp.append((cx+dx, cy+dy))
        step += 1
        que = tmp

for _ in range(TC):
    I = int(input())
    cur_x, cur_y = map(int, input().split())
    target_x, target_y = map(int, input().split())
    board = [[0 for _ in range(I)] for _ in range(I)]
    print(f(cur_x, cur_y))
