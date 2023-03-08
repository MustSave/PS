import sys;input=sys.stdin.readline;print=sys.stdout.write;
N, M = map(int, input().split())
mat_A = [list(map(int, input().split())) for _ in range(N)]

M, K = map(int, input().split())
mat_B = [list(map(int, input().split())) for _ in range(M)]

ans = [[0 for _ in range(K)] for _ in range(N)]

for i in range(N):
    for j in range(K):
        tmp = 0
        for k in range(M):
            tmp += mat_A[i][k] * mat_B[k][j]
        ans[i][j] = str(tmp)

for row in ans:
    print(' '.join(row) + '\n')
        