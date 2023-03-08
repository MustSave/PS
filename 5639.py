# preorder : root, left, right (input)
# postorder : left, right, root (output)

# 50 30 24 5 28 45 98 52 60
# 5 28 24 45 30 60 52 98 50

import sys;input=sys.stdin.readline;
sys.setrecursionlimit(100000)
preorder = []
while True:
	try:
		preorder.append(int(input()))
	except:
		break

def divide(root_index, pre_start, pre_end):
	if pre_start > pre_end: return

	left_end = pre_start +1
	root = preorder[root_index]
	while left_end <= pre_end and preorder[left_end] < root:
		left_end += 1

	divide(root_index+1, pre_start +1, left_end-1)
	divide(left_end, left_end, pre_end)
	print(root)

divide(0, 0, len(preorder)-1)