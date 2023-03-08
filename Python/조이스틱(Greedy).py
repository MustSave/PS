def solution(name):
    ans = 0
    for c in name:
        i = ord(c) - ord('A')
        ans += min(i, 26-i)
    
    move = len(name)-1
    for i in range(1, len(name)//2+1):
        if name[i] == 'A':
            tmp = i
            while tmp < len(name) and name[tmp] == 'A':
                tmp += 1
            if tmp == len(name):
                move = min(move, i-1)
                break
            else:
                move = min(move, (i-1)*2+len(name)-tmp)
        if name[-i] == 'A':
            tmp = len(name)-i
            while tmp >= 0 and name[tmp] == 'A':
                tmp -= 1
            if tmp == -1:
                move = min(move, i-1)
                break
            else:
                move = min(move, (i-1)*2+tmp)
                
    return move+ans