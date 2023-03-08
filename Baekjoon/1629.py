A, B, C = list(map(int, input().split()))

def solve(times):
    if times == 1:
        return A % C
    
    if times & 1 == 0:
        return (solve(times//2) ** 2) % C
    else:
        return (solve(times//2) * solve(times//2 + 1)) % C

print(solve(B))