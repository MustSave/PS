import sys;input=sys.stdin.readline;
N = int(input())
apart = [[] for _ in range(N)]

def bfs(x, y, idx):
    que = [(x, y)]
    count = 0

    while que:
        i, j = que.pop(0)
        if apart[i][j] != 1: continue

        apart[i][j] = idx
        count += 1

        for p, q in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
                if 0 <= i+p < N and 0 <= j+q < N and apart[i+p][j+q] == 1:
                    apart[i][j] = idx
                    que.append((i+p, j+q))
    return count

for i in range(N):
    row = input().rstrip()

    for j in range(N):
        apart[i].append(0 if row[j]=='0' else 1)

idx = 2
ans = []
for i in range(N):
    for j in range(N):
        if apart[i][j] == 1:
            ans.append(bfs(i, j, idx))
            idx += 1

print(idx-2)
ans.sort()
print(*ans, sep='\n')