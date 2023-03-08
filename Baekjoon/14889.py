N = int(input())
mat = []
score = [0, 0]
tma = []
tmb = []
minn = 1000000

for _ in range(N):
    mat.append(list(map(int, input().split())))

def calc(val, tm)->int:
    t = tma if tm == 0 else tmb
    add=0
    for i in t:
        add += mat[val][i] + mat[i][val]
    return add

def solve(step:int, prev:int):
    global minn
    if step == N//2:
        for i in range(N):
            if i not in tma:
                score[1] += calc(i, 1)
                tmb.append(i)
        tmb.clear()
        minn = min(minn, abs(score[0]-score[1]))
        score[1] = 0
        return
    
    for i in range(prev+1, N//2+step+1):
        add = calc(i, 0)
        score[0] += add
        tma.append(i)
        solve(step+1, i)
        score[0] -= add
        tma.remove(i)

solve(0, -1)
print(minn)