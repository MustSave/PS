from collections import Counter
N, M = map(int, input().split())
trees = Counter(map(int, input().split()))

start=0
end=2000000000
while start<=end:
    mid = (start+end)//2
    get = sum([(tree-mid)*count for tree, count in trees.items() if tree>mid])
    
    if get < M:
        end = mid-1
    else:
        start = mid+1

print(end)