N, K = map(int, input().split()) # <= 100000
visited = [False for _ in range(100001)]
visited[N] = True
# +1, -1, *2
if N==K: exit(print(0, 1, sep='\n'))
def bfs():
    que = [N]
    time = 0
    method = 0
    fin = False
    while que and not fin:
        tmp = []
        time += 1
        for item in que:
            visited[item] = True
            if item-1==K:
                method+=1
                fin=True
            if item+1==K:
                method+=1
                fin=True
            if item*2==K:
                method+=1
                fin=True
            # if abs(K-item) == 1 or item*2==K:
            #     method += 1
            #     fin = True

            if  item+1 <= 100000 and not visited[item+1]:
                # visited[item+1] = True
                tmp.append(item+1)
            if item-1 >= 0 and not visited[item-1]:
                # visited[item-1] = True
                tmp.append(item-1)
            if  item*2 <= 100000 and not visited[item*2]:
                # visited[item*2] = True
                tmp.append(item*2)
        que = tmp
    return (time, method)

print(*bfs(), sep='\n')