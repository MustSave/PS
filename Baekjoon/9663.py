import copy

N = int(input())
map = [[-1 for _ in range(N)] for _ in range(N)]
res = 0

def compute(col:int, row:int, forward:bool):
    for i in range(N):
        if forward:
            if map[row][i] == -1: map[row][i] = col
            if map[i][col] == -1: map[i][col] = col
        else:
            if map[row][i] == col: map[row][i] = -1
            if map[i][col] == col: map[i][col] = -1

    r = row + min(N-row-1, col)
    c = col - min(N-row-1, col)
    for i in range(min(r+1, N-c)):
        if forward and map[r-i][c+i] == -1: map[r-i][c+i]= col
        elif not forward and map[r-i][c+i] == col : map[r-i][c+i] = -1
    
    r = row - min(row, col)
    c = col - min(row, col)
    for i in range(min(N-r, N-c)):
        if forward and map[r+i][c+i] == -1: map[r+i][c+i]= col
        elif not forward and map[r+i][c+i] == col : map[r+i][c+i] = -1

def dfs(col:int):
    global res, map
    for row in range(N):
        if map[row][col] == -1:
            if col == N-1:
                res += 1
                continue

            compute(col, row, True)
            # for a in chess: print(a)
            # input()
            dfs(col+1)
            compute(col, row, False)
            
dfs(0)
print(res)