import sys;input=sys.stdin.readline;
N, M = map(int, input().split())
board = [0 for _ in range(101)]
que = [1];dice = 0

for _ in range(N+M):
    x, y = map(int, input().split())
    board[x] = y

while que:
    tmp = []
    for v in que:
        board[v] = 128
        for n in range(v+1, v+7):
            if n < 100 and not board[n] >> 7:
                if board[n] != 0:
                    tmp.append(board[n])
                    board[board[n]] = 128
                else:
                    tmp.append(n)
                board[n] = 128
            elif n == 100: exit(print(dice+1))
    dice += 1
    que = tmp
