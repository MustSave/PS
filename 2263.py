import sys;input=sys.stdin.readline;print=sys.stdout.write;
sys.setrecursionlimit(int(1e6))
N = int(input())
inorder = list(map(int, input().split())) # 좌 중 우
postorder = list(map(int, input().split())) # 좌 우 중
reverse = [0 for _ in range(N+1)]
for idx, val in enumerate(inorder):
    reverse[val] = idx
    
def divide(in_left, in_right, post_left, post_right):
    if in_left > in_right or post_left > post_right: return

    root_node = postorder[post_right]
    # root_index = inorder.index(root_node, in_left, in_right+1)
    root_index = reverse[root_node]
    l_size = root_index - in_left

    print(str(root_node)+" ")
    divide(in_left, root_index-1, post_left, post_left+l_size-1)
    divide(root_index+1, in_right, post_left+l_size, post_right-1)

divide(0, N-1, 0, N-1)
