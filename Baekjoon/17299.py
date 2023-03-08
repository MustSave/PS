from collections import Counter
N = int(input())
A = list(map(int, input().split()))
F = Counter(A)

stack = []
ans = [-1] * N

for n in range(N-1, -1, -1):
    while stack and F[stack[-1]] <= F[A[n]]:
        stack.pop()
    if stack: ans[n] = stack[-1]
    stack.append(A[n])

print(*ans)