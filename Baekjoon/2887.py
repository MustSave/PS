import sys;input=sys.stdin.readline;

N = int(input())
coord = [list(map(int, input().rstrip().split()))+[i] for i in range(N)]
total_cost = 0

def get_cost(a, b):
    return min(abs(a[0]-b[0]), abs(a[1]-b[1]), abs(a[2]-b[2]))

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if self.rank[px] < self.rank[py]:
            self.parent[px] = py
        else:
            self.parent[py] = px
            if self.rank[px] == self.rank[py]:
                self.rank[px] += 1

dsu = DSU(N)
pq = []

for i in range(3):
    coord.sort(key=lambda x: x[i])
    for j in range(1, N):
        pq.append((get_cost(coord[j], coord[j-1]), coord[j-1][-1], coord[j][-1]))

pq.sort(key=lambda x: x[0], reverse=True)
while pq:
    c, i, j = pq.pop()
    if dsu.find(i) != dsu.find(j):
        dsu.union(i, j)
        total_cost += c

print(total_cost)