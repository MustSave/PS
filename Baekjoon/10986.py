import sys;input = sys.stdin.readline
from math import comb
[N, M] = list(map(int, input().split()))
nums = list(map(lambda x: int(x) % M, input().split()))
mod = [0 for _ in range(M)]
mod[0] = 1
mod[nums[0]] += 1
ans = 0

for i in range(1,N):
    nums[i] = (nums[i] + nums[i-1]) % M
    mod[nums[i]] += 1

for i in range(M):
    ans += comb(mod[i], 2)

print(ans)