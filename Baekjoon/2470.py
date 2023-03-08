N = int(input())
liquid = list(map(int, input().split()))
liquid.sort()
i = 0
j = N-1
near_zero = 2000000000
while i < j:
    tmp = liquid[i] + liquid[j]
    abs_tmp = abs(tmp)
    
    if near_zero > abs_tmp:
        near_zero = abs_tmp
        ans = (i, j)

    if tmp == 0: break
    elif tmp > 0: j -= 1
    else: i += 1

print(liquid[ans[0]], liquid[ans[1]])