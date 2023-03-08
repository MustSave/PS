N, K = map(int, input().split()) # <= 100000
visited = [False for _ in range(100001)]
visited[N] = True
# +1, -1, *2

def bfs():
    que = [N]
    time = 0
    while que:
        tmp = []
        time += 1
        for item in que:
            if abs(K-item) == 1 or item*2==K:
                return time

            if  item+1 <= 100000 and not visited[item+1]:
                visited[item+1] = True
                tmp.append(item+1)
            if item-1 >= 0 and not visited[item-1]:
                visited[item-1] = True
                tmp.append(item-1)
            if  item*2 <= 100000 and not visited[item*2]:
                visited[item*2] = True
                tmp.append(item*2)
        que = tmp

print(bfs() if K > N else (N-K))