def solution(arr):
    arrs = ''.join(arr).split('-')
    val0 = sum(list(map(int, arrs[0].split('+'))))
    if len(arrs) == 1:
        return val0

    min_val = 0
    max_val = 0
    for arr in arrs[:0:-1]:
        x = list(map(int, arr.split('+')))
        _min_val = -(sum(x))
        _max_val = sum(x[1:]) - x[0]
        min_val, max_val = min(_min_val + min_val, _min_val - max_val), max(_max_val + max_val, _min_val - min_val)

    return val0 + max_val