from sys import stdin, stdout
input = stdin.readline;

N = int(input())
stack = []
res = []
for i in range(N):
    cmd = input().rstrip()
    if cmd == "pop":
        res.append(stack.pop() if stack else -1)
    elif cmd == "size":
        res.append(len(stack))
    elif cmd == "empty":
        res.append(0 if stack else 1)
    elif cmd == "top":
        res.append(stack[-1] if stack else -1)
    else:
        stack.append(cmd[5:])

print(*res, sep='\n')
