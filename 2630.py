import sys;input=sys.stdin.readline;
N = int(input())
board = [input().rstrip().split() for _ in range(N)]

white = 0
blue = 0

def isSquare(left_top, size):
    global white, blue
    l_top = board[left_top[0]][left_top[1]]
    for i in range(size):
        for j in range(size):
            if board[left_top[0]+i][left_top[1]+j] != l_top:
                next_size = size//2
                isSquare(left_top,next_size)
                isSquare((left_top[0], left_top[1]+next_size), next_size)
                isSquare((left_top[0]+next_size, left_top[1]), next_size)
                isSquare((left_top[0]+next_size, left_top[1]+next_size), next_size)
                return

    if l_top == '0': white +=1
    else: blue += 1

isSquare((0, 0), N)
print(white)
print(blue)
