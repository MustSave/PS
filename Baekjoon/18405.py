from collections import deque

res = 0
deq = deque()
tmp = []
N, K = map(int, input().split())
cell = [[] for _ in range(N)]

for i in range(N):
    cell[i] = list(map(int, input().split()))
    
    
for i in range(N):
    for j in range(N):
        if cell[i][j] != 0:
            tmp.append([(j, i), cell[i][j], 0])

tmp = sorted(tmp, key=lambda x: x[1])
for i in tmp:
    deq.append(i)

S, X, Y = map(int, input().split())
X -= 1
Y -= 1

# 상하좌우
dxy = [[0, -1], [0, 1], [-1, 0], [1, 0]]

while deq:
    cord, val, time = deq.popleft()
    
    if time == S:
        break
    
    for dx, dy in dxy:
        if cord[0]+dx < 0 or cord[0]+dx > N-1 or cord[1]+dy < 0 or cord[1]+dy > N-1 or cell[cord[1]+dy][cord[0]+dx] != 0:
            continue
        else:
            cell[cord[1]+dy][cord[0]+dx] = val
            deq.append([(cord[0]+dx, cord[1]+dy), val, time+1])
    

print(cell[X][Y])