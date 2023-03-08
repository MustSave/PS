from collections import deque

dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]

def bfs(room, x, y):
    queue = deque([])
    queue.append((x, y, 0))
    visited = [0] * 5
    while queue:
        x, y, dist = queue.popleft()
        if (visited[x] >> y) & 1 == 1: continue

        visited[x] |= 1 << y

        if dist == 2: continue
        for dx, dy in dir:
            nx, ny = x+dx, y+dy
            if not (0<=nx<5 and 0<=ny<5): continue
            if (visited[nx] >> ny) & 1 == 0:
                if room[nx][ny] == 'O':
                    queue.append((nx, ny, dist+1))
                elif room[nx][ny] == 'P':
                    return False
    return True

def solve(room):
    for i in range(5):
        for j in range(5):
            if room[i][j] == 'P':
                if not bfs(room, i, j):
                    return 0
    return 1

def solution(places):                    
    answer = [solve(room) for room in places]
    return answer