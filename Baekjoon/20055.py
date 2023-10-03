import sys;input=sys.stdin.readline;
from itertools import chain

N, K = map(int, input().rstrip().split())
durability = list(map(int, input().rstrip().split()))
double_N = N<<1

loading_point_idx = 0
zero_durability_count = 0
robots = [False for _ in range(double_N)]
step = 0

def get_index(i):
    return i if 0 <= i < double_N else i % double_N

def decrease_durability(idx):
    global zero_durability_count
    durability[idx] -= 1
    if durability[idx] == 0:
        zero_durability_count += 1
        if zero_durability_count == K:
            print(step)
            exit()

while True:
    step += 1
    loading_point_idx = get_index(loading_point_idx - 1)
    unloading_point_idx = get_index(loading_point_idx + N - 1)

    if unloading_point_idx < loading_point_idx:
        it = chain(range(unloading_point_idx, -1, -1), range(double_N-1, loading_point_idx -1, -1))
    else:
        it = range(unloading_point_idx, loading_point_idx -1, -1)

    for i in it:
        if not robots[i]: continue

        if i == unloading_point_idx:
            robots[i] = False
            continue

        next_idx = i + 1 if i != double_N - 1 else 0
        if durability[next_idx] > 0 and not robots[next_idx]:
            robots[i] = False
            decrease_durability(next_idx)
            if next_idx != unloading_point_idx:
                robots[next_idx] = True

    
    if durability[loading_point_idx] > 0:
        robots[loading_point_idx] = True
        decrease_durability(loading_point_idx)