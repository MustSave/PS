import sys;input=sys.stdin.readline;print=sys.stdout.write;
N = int(input())
times = sorted(list(map(int, input().split())))
for i in range(1, N):
    times[i] += times[i-1]
print(str(sum(times)))