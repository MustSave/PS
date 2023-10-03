from collections import deque

N, M = map(int, input().split())
order = list(map(int, input().split()))

a = deque([x+1 for x in range(N)])
ans = 0

for i in order:
    target = a.index(i)
    rot = len(a) - target if target > len(a) // 2 else -target
    ans += abs(rot)
    a.rotate(rot)
    a.popleft()

print(ans)