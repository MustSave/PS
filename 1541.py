ans = 0
for i, s in enumerate(input().split('-')):
    ans += sum(list(map(int, s.split('+')))) * (-1 if i else 1)
print(ans)