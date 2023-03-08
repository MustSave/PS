N = int(input())
seq = list(map(int, input().split()))
lis = [seq[0]]
max_length = [1]

def lower_bound(s, e, target):
    while s < e:
        m = (s+e)//2

        if lis[m] < target:
            s  = m+1
        else:
            e = m
    return e

for i in range(1, N):
    if seq[i] > lis[-1]:
        lis.append(seq[i])
        max_length.append(len(lis))
    else:
        idx = lower_bound(0, len(lis)-1, seq[i])
        lis[idx] = seq[i]
        max_length.append(idx+1)

tmp = len(lis)
ans = []
for i in range(N-1, -1, -1):
    if max_length[i] == tmp:
        ans.append(seq[i])
        tmp -= 1
        if tmp == 0:
            break

print(len(lis))
print(*ans[::-1])