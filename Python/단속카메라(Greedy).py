def solution(routes):
    answer = 0
    
    routes.sort(key=lambda x:x[1], reverse=True)
    tmp = routes[0][0]
    answer = 1
    for s, e in routes:
        if s > tmp:
            tmp = s
            continue
        
        if e < tmp:
            answer += 1
            tmp = s
    
    return answer