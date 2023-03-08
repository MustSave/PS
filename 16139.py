import sys; input = sys.stdin.readline

S = input().rstrip()
N = int(input())

alphabet = [[0 for _ in range(len(S)+1)] for _ in range(26)]
a = ord('a')
for idx in range(1, len(S)+1):
    for i in range(26):
        if i == ord(S[idx-1]) - a:
            alphabet[i][idx] = alphabet[i][idx-1] + 1
        else:
            alphabet[i][idx] = alphabet[i][idx-1]

for i in range(N):
    [char, start, end] = input().split()
    sys.stdout.write(str(alphabet[ord(char)-a][int(end)+1] - alphabet[ord(char)-a][int(start)])+'\n')