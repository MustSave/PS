def prime_list(max):
    prime = [True for _ in range(max+1)]

    for p in range(2, int(max**0.5)+1):
        if prime[p]:
            for mul in range(2, max//p +1):
                prime[p*mul] = False
    
    return [p for p in range(2, max+1) if prime[p]]

N = int(input())
primes = [0]+prime_list(N)
s, e, ans, max_idx = 0, 1, 0, len(primes)-1
for i in range(1, max_idx+1):
    primes[i] += primes[i-1]

while e <= max_idx and s < e:
    subtotal = primes[e] - primes[s]
    if subtotal == N:
        ans += 1
        s += 1
        e += 1
    elif subtotal > N:
        s += 1
    else:
        e += 1

print(ans)