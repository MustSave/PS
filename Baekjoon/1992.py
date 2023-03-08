import sys;input=sys.stdin.readline;print=sys.stdout.write;
N = int(input())
image = [input().rstrip() for _ in range(N)]
# ans = ''

def compress(x, y, size):
    global ans
    flag = image[x][y]

    for i in range(x, x+size):
        for j in range(y, y+size):
            if image[i][j] != flag:
                half = size//2
                # ans += "("
                print('(')
                compress(x, y, half)
                compress(x, y+half, half)
                compress(x+half, y, half)
                compress(x+half, y+half, half)
                # ans += ")"
                print(')')
                return
    # ans += flag
    print(flag)

compress(0, 0, N)
# print(ans)