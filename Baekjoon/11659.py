import sys

N = list(map(int, sys.stdin.readline().split()))
nums = [0]+list(map(int, sys.stdin.readline().split()))

for i in range(1, N[0]+1):
    nums[i] += nums[i-1]

for i in range(N[1]):
    [start, end] = list(map(int, sys.stdin.readline().split()))
    print(nums[end] - nums[start-1])