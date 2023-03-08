N = int(input())
prime = 1000000007

def matmul(mata, matb, mod):
    n = len(mata)
    m = len(matb)
    o = len(matb[0])
    result = [[0 for _ in range(n)] for _ in range(o)]
    for i in range(n):
        for j in range(o):
            item = 0
            for k in range(m):
                item += (mata[i][k] * matb[k][j])%mod
            result[i][j] = item % mod
    return result

def matpow(mat, times, mod):
    if times == 1:
        return mat

    mat2 = matpow(matmul(mat, mat, mod), times//2, mod)
    if times & 1 == 0:
        return mat2
    else:
        return matmul(mat, mat2, mod)

print(matpow([[1, 1],[1, 0]], N, prime)[0][1])


