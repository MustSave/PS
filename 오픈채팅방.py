def solution(record):
    answer = []
    
    #enter = "님이 들어왔습니다."
    #exit = "님이 나갔습니다."
    tail = {"Enter" : "님이 들어왔습니다.", "Leave" : "님이 나갔습니다."}
    dic = {}
    nickName = {}
    
    for r in record:
        res = r.split()

        # if (res[0] == "Change"):
        #     nickName[res[1]] = res[2]
        # elif res[0] == "Enter":
        #     if (res[1] not in dic):
        #         dic[res[1]] = []
        #     nickName[res[1]] = res[2]
        #     dic[res[1]].append(len(answer))
        #     answer.append(enter)
        # else:
        #     if (res[1] not in dic):
        #         dic[res[1]] = []
        #     dic[res[1]].append(len(answer))
        #     answer.append(exit)
        
        if (res[0] != "Leave"):
            nickName[res[1]] = res[2]
        if (res[0] != "Change"):
            if (res[1] not in dic):
                dic[res[1]] = []
            dic[res[1]].append(len(answer))
            answer.append(tail[res[0]])
    
    for key in dic.keys():
        for i in dic[key]:
            answer[i] = nickName[key] + answer[i]

    
    return answer