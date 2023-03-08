import sys;input=sys.stdin.readline;

[N, M, K] = list(map(int, input().split()))
board = [input().rstrip() for _ in range(N)]
acc = [[0 for _ in range(M+1)] for _ in range(N+1)]
ans = 4000000
for i in range(N):
    for j in range(M):
        tmp = 1 if board[i][j]=='B' else 0
        acc[i+1][j+1] = tmp^((i+j)%2)

        acc[i+1][j+1] = acc[i][j+1] + acc[i+1][j] - acc[i][j] + acc[i+1][j+1]

def gugansum(r_start, c_start):
    s1 = acc[r_start+K-1][c_start+K-1] - acc[r_start+K-1][c_start-1] - acc[r_start-1][c_start+K-1] + acc[r_start-1][c_start-1]
    return min(s1, K*K-s1)

for i in range(1, N-K+2):
    for j in range(1, M-K+2):
        ans = min(ans, gugansum(i, j))
print(ans)
