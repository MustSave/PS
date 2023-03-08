import sys;input=sys.stdin.readline;
N = int(input())
stack = []
ans = 0

for i in range(N):
    height = int(input())
    dup = 0
    while stack and stack[-1][0] <= height:
        h, c = stack.pop()
        ans += c
        if h == height:
            dup = c
            break
    if stack:
        ans += 1
    stack.append([height, dup+1])

print(ans)