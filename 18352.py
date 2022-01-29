import collections
import sys

q = collections.deque()
res = []
dict = {}
l = 0

N, M, K, X = map(int, sys.stdin.readline().rstrip().split(' '))
isvisited = [False]*N


for _ in range(M):
    a, b = map(lambda x: int(x)-1, sys.stdin.readline().rstrip().split(' '))
    
    
    if a not in dict: dict[a] = []
    dict[a].append(b)


q.append([X-1,0])

isvisited[X-1] = True


while q:
    
    if l >= K:
        break
    
    r, l = q.popleft()
    if r in dict:
        for i in dict[r]:
            if isvisited[i] == False:
                isvisited[i] = True
                if l == K-1:
                    res.append(i)
                    continue
                q.append([i, l+1])

        
if res:
    for i in sorted(res):
        print(i+1)
else:
    print(-1) 
        
