N = int(input())
nums = list(map(int, input().split()))

stack = []
ans = []
for n in nums[::-1]:
    while stack and stack[-1] <= n:
        stack.pop()
    ans.append(stack[-1] if stack else -1)
    stack.append(n)

print(*ans[::-1])