N = int(input())
mem = []
rec = 0

def recursive(n)->int:
    global rec
    if (n < 2):
        rec += 1
        return 1
    
    return recursive(n-1) + recursive(n-2)

def dp() :
    mem.append(1)
    mem.append(1)

    for i in range(2, N):
        mem.append(mem[i-1] + mem[i-2])
    
    return mem[-1]

dp()
recursive(N-1)

print(rec, N-2)