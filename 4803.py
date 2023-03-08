import sys;input=sys.stdin.readline;

def count_tree(case_num):
	N, M = map(int, input().split()) # N <= 500, M <= n(n-1)//2
	if N+M == 0: return False

	count = 0
	graph = [[] for _ in range(N+1)]
	parent = [0 for _ in range(N+1)]
	for _ in range(M):
		u, v = map(int, input().split())
		graph[u].append(v)
		graph[v].append(u)

	for i in range(1, N+1):
		if parent[i]: continue

		parent[i] = i
		isTree = True
		stack = [i]
		while stack:
			node = stack.pop()

			for adj_node in graph[node]:
				if parent[adj_node] == 0:
					stack.append(adj_node)
					parent[adj_node] = node
				elif parent[node] != adj_node:
					isTree = False

		if isTree: count += 1

	msg = "Case {}: {}".format(case_num, "No trees." if count == 0 else "There is one tree." if count == 1 else "A forest of {} trees.".format(count))
	print(msg)

	return True

case = 1
while count_tree(case):
	case += 1