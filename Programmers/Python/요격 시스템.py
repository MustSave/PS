def solution(targets):
    answer = 1
    
    targets.sort(key=lambda x: x[0])
    min_e = targets[0][1]
    
    for s, e in targets:
        min_e = min(min_e, e)
        if s >= min_e:
            answer += 1
            min_e = e
    
    return answer
