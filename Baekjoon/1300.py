N = int(input())
K = int(input())

def order(num):
    # maximum = 0
    minimum = 0
    for i in range(1, N+1):
        # maximum += min(N, num//i)
        minimum += min(N, (num-1)//i)
    return minimum+1

def bin_search(s, e):
    while s <= e:
        m = (s+e)//2

        minimum  = order(m)

        if minimum > K:
            e = m - 1
        else:
            s = m + 1

    return e

print(bin_search(1, N*N))