N = int(input())
array = list(map(int, input().split()))
array.sort()
X = int(input())

def lower_bound(s, e, t):
    while s < e:
        m = (s+e)//2

        if array[m] >= t:
            e = m
        else:
            s = m +1
    return array[e] == t

def bin_search(): # O(nlogn)
    count = 0
    for i in range(N):
        if lower_bound(i+1, N-1, X-array[i]):
            count += 1
    print(count)

def two_pointer(): # O(n)
    i, j = 0, N-1
    count = 0
    while i < j:
        tmp = array[i] + array[j]
        if tmp == X:
            count += 1
            i += 1
            j -= 1
        elif tmp > X:
            j -= 1
        else:
            i += 1
    print(count)

two_pointer()