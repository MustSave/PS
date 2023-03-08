import sys;input=sys.stdin.readline;print=sys.stdout.write;
N = int(input())
nums=sorted([int(input()) for _ in range(N)])
for n in nums:
    print(str(n)+'\n')