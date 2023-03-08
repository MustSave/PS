import sys;input=sys.stdin.readline;print=sys.stdout.write;
N, K = map(int, input().split())
K = min(K, N-K)
M = 1000000007
n=k=1

for i in range(K):
    n = (n*(N-i))%M
    k = (k*(i+1))%M

print(str((n*pow(k, M-2, M))%M))