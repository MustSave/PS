import sys;input=lambda:sys.stdin.readline().rstrip()
class Node:
    def __init__(self, left, right):
        self.left = left if left != '.' else ''
        self.right = right if right != '.' else ''

N = int(input())
node_dict:dict[Node] = {}

for _ in range(N):
    parent, left, right = input().split()
    node_dict[parent] = Node(left, right)

def 전위(node):
    if node == '': return

    obj:Node = node_dict[node]
    print(node, end='')
    전위(obj.left)
    전위(obj.right)

def 중위(node):
    if node == '': return
    obj:Node = node_dict[node]
    중위(obj.left)
    print(node, end='')
    중위(obj.right)

def 후위(node):
    if node == '': return
    obj:Node = node_dict[node]
    후위(obj.left)
    후위(obj.right)
    print(node, end='')
전위('A')
print()
중위('A')
print()
후위('A')
