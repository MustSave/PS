N = int(input())
nums = list(map(int, input().split()))
ops = list(map(int, input().split())) # + - * /

func = [int.__add__, int.__sub__, int.__mul__, lambda x, y: abs(x)//y if x > 0 else abs(x)//y*-1]
minn = 1000000000
maxn = -1000000000

def solve(before:int, step:int):
    global minn, maxn
    if step == N:
        minn = min(minn, before)
        maxn = max(maxn, before)
        return

    for i in range(4):
        if ops[i] > 0:
            ops[i] -= 1
            res = int(func[i](before, nums[step]))
            solve(res, step+1)
            ops[i] += 1

solve(nums[0], 1)
print(maxn)
print(minn)