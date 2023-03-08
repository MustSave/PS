import sys;input=sys.stdin.readline;

N = int(input())
graph = [0]+[int(input()) for _ in range(N)]+[0]

stack = [0]
maximum = 0
for i in range(1, N+2):
    while len(stack) > 1 and  graph[stack[-1]] >= graph[i]:
        pop = stack.pop()
        height = graph[pop]
        length = i - stack[-1] -1
        maximum = max(maximum, height*length)
    stack.append(i)

print(maximum)