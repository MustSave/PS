def find(root_list, node):
    if root_list[node] == node:
        return node
    
    root_list[node] = find(root_list, root_list[node])
    return root_list[node]

def solution(n, computers):
    answer = 0
    parent = [i for i in range(n)]
    
    for i in range(n):
        if parent[i] != i: continue
        answer += 1
        stack = [i]
        while stack:
            node = stack.pop()
            root_a = find(parent, node)
            
            for j in range(n):
                if computers[node][j] == 1:
                    root_b = find(parent, j)
                    if root_a != root_b:
                        parent[root_b] = root_a
                        stack.append(j)
        
    return answer