from math import ceil

def get_bit(check, i):
    return (check[i//32] >> (i%32)) & 1
def flip_bit(check, i):
    check[i//32] ^= 1 << (i%32)
    

    
    
def solution(n, k, cmd):
    check = [0] * ceil(n/32)
    # D : Down
    # U : Up
    # C : Remove
    # Z : Recover
    stack = []
    BIT = [0] * n
    
    last_idx = n-1
    for command in cmd:
        if command[0] == 'D':
            i = 0
            move = int(command[2:])
            while i < move and k < n:
                k += 1
                if get_bit(check, k) == 0:
                    i += 1
        elif command[0] == 'U':
            i = 0
            move = int(command[2:])
            while i < move and k >= 0:
                k -= 1
                if get_bit(check, k) == 0:
                    i += 1
        elif command[0] == 'C':
            flip_bit(check, k)
            stack.append(k)
            if k == last_idx: # 마지막 index 였을 때
                k -= 1
                while get_bit(check, k) == 1:
                    k -= 1
                last_idx = k
            else:
                k += 1
                while get_bit(check, k) == 1:
                    k += 1
        else:
            i = stack.pop()
            flip_bit(check, i)
            if i > last_idx:
                last_idx = i
    
    ans = ''
    for i in range(n):
        ans += 'O' if get_bit(check, i) == 0 else 'X'
    return ans

''.join()