N, M = map(int, input().split())
li = [-1 for _ in range(M)]

def dfs(start:int, step:int):
    if step == 0:
        for l in li:
            print(l, end=' ')
        print()
    else:
        for s in range(start, N-step+2):
            li[M-step] = s
            dfs(s+1, step-1)
            li[M-step] = -1

dfs(1, M)