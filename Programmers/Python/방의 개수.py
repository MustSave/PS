from collections import defaultdict

class Visited:
    def __init__(self):
        self.visited = [False] * 8

    def visit(self, n):
        self.visited[n] = True

    def is_visited(self, arrow):
        return self.visited[arrow]

coords = defaultdict(Visited)
answer = 0

dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

def check(coord, arrow):
    return not coords[coord].is_visited((arrow + 4) % 8)

def solution(arrows):
    prev_coord = (0, 0)
    coords[prev_coord]
    for arrow in arrows:
        dx, dy = dir[arrow]
        nx, ny = prev_coord[0] + dx, prev_coord[1] + dy
        
        do_visit(prev_coord, arrow, nx, ny)
        prev_coord = (nx, ny)
        nx += dx
        ny += dy
        do_visit(prev_coord, arrow, nx, ny)
        prev_coord = (nx, ny)

    return answer

def do_visit(prev_coord, arrow, nx, ny):
    global answer
    next_coord = (nx, ny)
    if next_coord in coords and check(next_coord, arrow):
        answer += 1
    coords[next_coord].visit((arrow + 4) % 8)
    coords[prev_coord].visit(arrow)