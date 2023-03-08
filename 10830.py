import sys;input=sys.stdin.readline;print=sys.stdout.write;

N, B = map(int, input().split())
matrix = [list(map(lambda x: int(x)%1000, input().split())) for _ in range(N)] # N x N matrix

def matmul(mata, matb):
    result = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            item = 0
            for k in range(N):
                item += (mata[i][k] * matb[k][j])%1000
            result[i][j] = item % 1000
    return result

def matpow(mat, times):
    if times == 1:
        return mat

    mat2 = matpow(matmul(mat, mat), times//2)
    if times & 1 == 0:
        return mat2
    else:
        return matmul(mat, mat2)

for row in matpow(matrix, B):
    for i in row:
        print(str(i)+' ')
    print('\n')
