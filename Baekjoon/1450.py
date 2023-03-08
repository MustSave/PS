N, C = map(int, input().split()) # 0 < N <= 30, 0 <= C <=1e9
weight = list(map(int, input().split()))

def calc(arr:list):
    ret = []
    for i in range(1 << len(arr)): # N/2==15일 떄 0b000000000000000 ~ 0b111111111111111 까지 순회
        sum = 0
        for j in range(len(arr)):
            if i & 1:
                sum += arr[j]
            i = i>>1
        if sum <= C:
            ret.append(sum)
    return ret

def upper_bound(arr, target):
    s, e = 0, len(arr)
    while s < e:
        m = (s+e)//2
        if arr[m] > target:
            e = m
        else:
            s = m +1
    return e

def mitm(arr:list):
    mid = len(arr)//2
    left = calc(arr[:mid])
    right = calc(arr[mid:])
    right.sort()
    ans = 0

    for i in left:
        # C-i보다 큰 숫자가 처음으로 위치하는 인덱스 찾기 => 이전까지의 수는 C-i보다 작거나 같으므로 인덱스 번호 = 작거나 같은 수의 개수
        ans += upper_bound(right, C-i) 

    return ans

print(mitm(weight))