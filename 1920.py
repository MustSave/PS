N = int(input())
numbers = list(map(int, input().split()))
numbers.sort()
M = int(input())
find_list = list(map(int, input().split()))

def bin_search(start, end, target):
    mid = (start+end)//2
    if start > end:
        return 0

    if numbers[mid] == target:
        return 1
    if numbers[mid] > target:
        return bin_search(start, mid-1, target)
    else:
        return bin_search(mid+1, end, target)

for i in find_list:
    print(bin_search(0, N-1, i))