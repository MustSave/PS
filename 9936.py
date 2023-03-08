bomb = input()
key = input()
stack = []
j_stack = []
i = 0
j = 0
while i < len(bomb):
    stack.append(bomb[i])

    if bomb[i] == key[j]:
        j += 1
        if j == len(key):
            for _ in range(len(key)):
                stack.pop()
            if len(j_stack) > 0:
                j = j_stack.pop()
            else:
                j = 0
    else:
        if bomb[i] == key[0]:
            if j > 0: j_stack.append(j)
            j = 1
        else:
            j_stack.clear()
            j = 0
    i += 1

print(''.join(stack) if stack else "FRULA")