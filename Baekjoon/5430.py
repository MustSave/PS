from collections import deque

input = open(0).readline;

T = int(input())
res = []

def ans(p, n, a:deque):
    do_leftpop = True

    for cmd in p:
        if cmd == "R":
            do_leftpop = not do_leftpop
        elif cmd == "D":
            if not a:
                return "error"
            a.popleft() if do_leftpop else a.pop()
        else:
            return "error"
    
    return f"[{','.join(a if do_leftpop else reversed(a))}]"

for _ in range(T):
    p = input().rstrip()
    n = input()
    a = input()[1:-2].split(',')
    if a[0] == '':
        a = []
    a = deque(a)
    res.append(ans(p, n, a))

print(*res, sep='\n')