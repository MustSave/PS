from collections import deque

direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def printer():
    for i in range(R):
        for j in range(C):
            print(arr[i][j], end='')
        print()
    print()

def bounderycheck(arr, R, C, i, j):
    if i+1 < R and (arr[i+1][j]  == '.' or arr[i+1][j] == 'L'):
        return True;
    elif i-1 >= 0 and (arr[i-1][j] == '.' or arr[i-1][j] == 'L'):
        return True;
    elif j+1 < C and (arr[i][j+1] == '.' or arr[i][j+1] == 'L'):
        return True;
    elif j-1 >= 0 and (arr[i][j-1] == '.' or arr[i][j-1] == 'L'):
        return True;
    return False;


def melt(arr, R, C, i, j, t, q):
    arr[i][j] = '.'
    for a in direction:
        if 0 <= (i+a[0]) < R and 0 <= (j+a[1]) < C and arr[i+a[0]][j+a[1]] == 'X':
            arr[i+a[0]][j+a[1]] = '1'
            q.append((i+a[0], j+a[1], t+1))

def ismeet(arr, R, C, m):
    next = False
    t = deque()
    
    while(m):
        next = False
        x, y = m.popleft()
        for dx, dy in direction:
            if (0 <= x+dx < R and 0 <= y+dy < C):
                c = arr[x+dx][y+dy]
                if c == '1':
                    next = True
                elif c == '.':
                    if x+dx == ori[1][0] and y+dy == ori[1][1]:
                        return True
                    arr[x+dx][y+dy] = 'O'
                    m.append((x+dx, y+dy))
        if next:
            t.append((x, y))

    while t:
        m.append(t.pop())
    return False
                

R, C = map(int, input().split())
ori = []
q = deque()
m = deque()

arr = []
for i in range(R):
    arr.append(list(input()))

for i in range(R):
    for j in range(C):
        if arr[i][j] == 'X' and bounderycheck(arr, R, C, i, j):
            q.append((i, j, 1))
            arr[i][j] = '1'
        elif arr[i][j] == 'L':
            arr[i][j] = '.'
            ori.append((i, j))

m.append(ori[0])
arr[ori[0][0]][ori[0][1]] = 'O'

time = 0
while q:
    pop = q.popleft()

    if pop[2] == time:
        melt(arr, R, C, pop[0], pop[1], time, q)
    else:
        q.appendleft(pop)
        if ismeet(arr, R, C, m): break
        time += 1

print(time)