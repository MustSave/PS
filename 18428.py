# N X N크기 복도 선생 T, 학생 S, 장애물 O 3개
# 선생기준 상하좌우 끝까지, 장애물 뒤 인식 노
from itertools import combinations
def check():
    for y, x in T:
        i = 1
        
        while y-i >= 0:
            if maps[y-i][x] == 'O':
                break
            elif maps[y-i][x] == 'S':
                return False
            i += 1
        i = 1
        while y+i < N:
            if maps[y+i][x] == 'O':
                break
            elif maps[y+i][x] == 'S':
                return False
            i += 1
        i = 1
        while x-i >= 0:
            if maps[y][x-i] == 'O':
                break
            elif maps[y][x-i] == 'S':
                return False
            i += 1
        i = 1
        while x+i < N:
            if maps[y][x+i] == 'O':
                break
            elif maps[y][x+i] == 'S':
                return False
            i += 1
        
        return True
    
maps = []
T = []
X = []


def f():
    O = combinations(X, 3)
    
    for data in O:
        for x, y in data:
            maps[x][y] = 'O'
        
        if check() == True:
            return True
            
        for x, y in data:
            maps[x][y] = 'X'
    
    return False

# (X, Y)
N = int(input()) # [3,6]
for i in range(N):
    tmp = input().split()
    for j, val in enumerate(tmp):
        elif val == 'T':
            T.append((i, j))
        elif val == 'X':
            X.append((i, j))
    maps.append(tmp)

print("YES" if f() else "NO")


