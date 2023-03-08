# ^ : 행의 시작
# $ : 행의 끝
# \A : 문자열 시작
# \Z : 문자열 끝
import re

def solution(new_id):

    answer = new_id.lower()
    answer = re.sub(r'[^0-9a-zA-Z-_.]', '', answer)
    answer = re.sub(r'\.\.+', '.', answer)
    
    # if len(answer) > 0 and answer[0] == '.':
    #     answer = answer[1:]
    # if len(answer) > 0 and (answer[-1] == '.'):
    #     answer = answer[:-1]
    answer = re.sub('^[.]|[.]$', '', answer)
    
    if len(answer) == 0:
        answer = 'a'
    elif len(answer) > 15:
        # if answer[14] == '.':
        #     answer = answer[:14]
        # else:
        #     answer = answer[:15]
        answer = re.sub('[.]$', '', answer[:15])
    
    if len(answer) < 3:
        answer = answer.ljust(3, answer[-1])
    
    return answer