N = int(input()) # N < 500000
card = input().split() # |card| <= 10000000
test = {}
for c in card:
    if test.get(c):
        test[c] += 1
    else:
        test[c] = 1

M = int(input())
to_find = input().split()

for i in to_find:
    ans = test.get(i)
    print(ans if ans else 0, end=' ')