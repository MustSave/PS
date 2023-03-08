board = []
max = 45

for i in range(9):
    board.append(list(map(int, input().split())))

z=[]
for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            z.append((i,j))

def check(i, j, val)->bool:
    if val in board[i]: return False

    for b in board:
        if val == b[j]: return False
    
    for p in range(i//3*3, i//3*3+3):
        for q in range(j//3*3, j//3*3+3):
            if val == board[p][q]: return False
    
    return True

def solve(step)->bool:
    if len(z) == step:
        for i in range(9):
            for j in range(9):
                print(board[i][j], end=' ')
            print()
        return True
        
    r, c = z[step]
    for i in range(1,10):
        if check(r, c, i):
            board[r][c] = i
            if solve(step+1) : return True
            board[r][c] = 0
    return False

solve(0)