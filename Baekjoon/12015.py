N = int(input())
arr = list(map(int, input().split()))
dp = [arr[0]]

def lower_bound(s, e, target):
    while s < e:
        m = (s+e)//2

        if dp[m] < target:
            s = m+1
        else:
            e = m
    return e


for i in range(1, N):
    if arr[i] > dp[-1]:
        dp.append(arr[i])
    else:
        dp[lower_bound(0, len(dp)-1, arr[i])] = arr[i]
    # print(dp)




print(len(dp))