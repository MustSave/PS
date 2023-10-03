import sys

S = sys.stdin.readline().rstrip()
T = sys.stdin.readline().rstrip()

stack = [T]
while stack:
    s = stack.pop()
    if len(s) == len(S):
        if s == S: print(1); exit()
        else: continue

    if s[-1] == "A":
        stack.append(s[:-1])
    else:
        stack.append(s[:-1][::-1])

print(0)