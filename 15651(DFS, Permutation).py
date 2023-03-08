N, M = map(int, input().split())
li = [0 for _ in range(M)]

def dfs(step:int):
    if step == 0:
        for l in range(M):
            print(li[l], end=' ')
        print()
        return
        
    for i in range(1, N+1):
        li[M-step] = i
        dfs(step-1)
        li[M-step] = -1

dfs(M)