def solution(distance, rocks, n):
    rocks.sort()
    rocks.append(distance)
    
    s = 1
    e = distance
    
    while s <= e:
        count = 0
        prev = 0
        m = (s+e)>>1
        for rock in rocks:
            if rock-prev < m:
                count += 1
            else:
                prev = rock
        if count > n:
            e = m-1
        else:
            s = m+1
    return e