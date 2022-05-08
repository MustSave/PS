# 중복 제거 => set 이용
# list.index()
def solution(id_list, report, k):
    #answer = []
    answer = [0] * len(id_list)
    
    dict = {}
    #ans = {}
    
    for id in id_list:
        #ans[id] = 0
        dict[id] = []
    
    #for r in report:
    for r in set(report):
        res = r.split()
        #if (res[0] not in dict[res[1]]):
            #dict[res[1]].append(res[0])
        dict[res[1]].append(res[0])

    for key in dict.keys():
        if len(dict[key]) >= k:
            for id in dict[key]:
                # ans[id] += 1
                answer[id_list.index(id)] += 1
    
    #for id in id_list:
        #answer.append(ans[id])
    
    return answer