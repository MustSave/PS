import sys;input=sys.stdin.readline;

N = int(input())
paper = [list(map(int, input().split())) for _ in range(N)]
ans = [0, 0, 0]

def cut(x, y, size):
    global ans;
    flag = paper[x][y]

    for i in range(x, x+size):
        for j in range(y, y+size):
            if paper[i][j] != flag:
                next_size = size//3
                for k in range(3):
                    for l in range(3):
                        cut(x+k*next_size, y+l*next_size, next_size)
                return
    
    ans[flag] += 1

cut(0, 0, N)
print(ans[-1])
print(ans[0])
print(ans[1])