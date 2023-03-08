def solution(n, costs):
    root = [i for i in range(n)]
    ans = 0
    def find(n):
        tmp = n
        while root[tmp] != tmp:
            tmp = root[tmp]
        root[n] = tmp
        return tmp

    costs.sort(key=lambda x: x[2])
    for u, v, c in costs:
        ru, rv = find(u), find(v)
        
        if ru != rv:
            ans += c
            if ru > rv:
                root[ru] = rv
            else:
                root[rv] = ru
    return ans